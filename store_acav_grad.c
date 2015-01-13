/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_acav_grad.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 07:15:46 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 11:53:15 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Functions here are designed to minimize calculations for color gradients in
** 		the rendering functions.
** Type 1: represents a single colored object.
** Type 1: represents a two gradients colored object.
** Type 1: represents a three gradients colored object.
*/
/*
** 'fdf_build_grad'
** 		calls 'build_type1' if type 1, or if line is flat.
** 		calls 'build_type2' if type 2, or if line don't cross the maxz/2 plan.
** 		calls 'build_type31' if type 3 and az < bz.
** 		calls 'build_type32' if type 3 and az > bz.
*/

static t_grad	build_type1(t_fdf fdf, double az)
{
	t_grad			gr;

	gr = (t_grad){1, fdf.avco[0], {0.0, .0, .0, .0}, {0.0, .0, .0, .0},
			{0.0, .0, .0, .0}, {0.0, .0, .0, .0}, {.0, .0, .0, .0}, 0.0};
	if (fdf.num_avco > 1 && fdf.num_avco <= 3)
	{
		gr.v1 = az / ((double)fdf.fdfsz.z / 5.5);
		if (fdf.num_avco == 3 && !(gr.v1 < 0.5))
		{
			gr.v1 = (gr.v1 - 0.5) * 2.0;
			gr.stc1 = DDCOADD((double)fdf.avco[2].s, DCOMUL(fdf.davco[1], gr.v1));
		}
		else
		{
			if (fdf.num_avco == 3)
				gr.v1 = gr.v1 * 2.0;
			gr.stc1 = DDCOADD((double)fdf.avco[0].s, DCOMUL(fdf.davco[0], gr.v1));
		}
	}
	gr.ico = DCOTOI(gr.stc1);
	return (gr);
}

static t_grad	build_type2(t_fdf fdf, double az, double bz)
{
	t_grad	gr;
	double	v2;

	gr = build_type1(fdf, az);
	gr.type = 2;
	v2 = fdf.fdfsz.z / 5.5 / 2.0;
	if (fdf.num_avco == 3 && az < v2 && bz < v2)
	{
		v2 = (bz / ((double)fdf.fdfsz.z / 5.5)) * 2 - gr.v1;
		gr.dtc1 = DCOMUL(fdf.davco[0], v2);
	}
	else if (fdf.num_avco == 3)
	{
		v2 = ((bz / ((double)fdf.fdfsz.z / 5.5)) - 0.5) * 2.0 - gr.v1;
		gr.dtc1 = DCOMUL(fdf.davco[1], v2);
	}
	else
	{
		v2 = bz / ((double)fdf.fdfsz.z / 5.5) - gr.v1;
		gr.dtc1 = DCOMUL(fdf.davco[0], v2);
	}
	return (gr);
}

static t_grad	build_type31(t_fdf fdf, double az, double bz)
{
	t_grad	gr;
	double	hratl;
	double	hrath;
	t_cod	avco0;
	t_cod	avco2;

	t_cod	tmp1;
	double	tmp3;
	gr = (t_grad){3, {{0.0, 0.0, 0.0, 0.0}}, {0.0, .0, .0, .0}, {0.0, .0, .0, .0},
			{0.0, .0, .0, .0}, {0.0, .0, .0, .0}, {.0, .0, .0, .0}, 0.0};
	
	avco0 = ICOTOD((double)fdf.avco[0]);
	avco2 = ICOTOD((double)fdf.avco[2]);
	
	t_cod davco0 = fdf.davco[0];
	t_cod davco1 = fdf.davco[1];

	hratl = az / ((double)fdf.fdfsz.z / 5.5);
	hrath = bz / ((double)fdf.fdfsz.z / 5.5);
	gr.stc2 = avco2;
	tmp1 = DCOMUL(davco0, (hratl * 2));
	gr.stc1 = DDCOADD(tmp1, avco0);
	gr.dtc1 = DDCOSUB(avco2, gr.stc1);
	tmp3 = (hrath - 0.5) * 2;
	gr.dtc2 = DCOMUL(davco1, tmp3);
	gr.v1 = (0.5 - hratl) / (hrath - hratl);
	return (gr);
}

static t_grad	build_type32(t_fdf fdf, double az, double bz)
{
	t_grad	gr;
	double	hratl;
	double	hrath;
	t_cod	avco2;
	double	tmp3;
	gr = (t_grad){3, {{0.0, 0.0, 0.0, 0.0}}, {0.0, .0, .0, .0}, {0.0, .0, .0, .0},
			{0.0, .0, .0, .0}, {0.0, .0, .0, .0}, {.0, .0, .0, .0}, 0.0};
	
	avco2 = ICOTOD((double)fdf.avco[2]);
	t_cod davco0 = fdf.davco[0];
	t_cod davco1 = fdf.davco[1];
	hratl = az / ((double)fdf.fdfsz.z / 5.5);
	hrath = bz / ((double)fdf.fdfsz.z / 5.5);
	gr.stc2 = avco2;
	tmp3 = (hratl - 0.5) * 2 * -1;
	gr.dtc1 = DCOMUL(davco1, tmp3);
	gr.stc1 = DDCOSUB(avco2, gr.dtc1);
	tmp3 = (0.5 - hrath) * 2 * -1;
	gr.dtc2 = DCOMUL(davco0, tmp3);
	gr.v1 = (0.5 - hratl) / (hrath - hratl);
	return (gr);
}

t_grad			fdf_build_grad(t_fdf fdf, double az, double bz)
{
	double	hsz;

	if (fdf.num_avco == 1 || FISEQ(az, bz))
		return (build_type1(fdf, az));
	else if ((fdf.num_avco == 2) ||
				(az < (hsz = fdf.fdfsz.z / 5.5 / 2.0) && bz < hsz) ||
				(az > hsz && bz > hsz))
		return (build_type2(fdf, az, bz));
	else if (fdf.num_avco == 3 && az < bz)
		return (build_type31(fdf, az, bz));
	else if (fdf.num_avco == 3 && az > bz)
		return (build_type32(fdf, az, bz));
	return ((t_grad){0});
}
