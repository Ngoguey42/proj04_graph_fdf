/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 10:41:34 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/05 09:18:52 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
/*
t_point	fdf_point(char *name, double x, double y, double z)
{
	t_point		pt;

	ft_strlcpy(pt.name, name, POINTS_NAMES_LEN);
	pt.coof.x = x;
	pt.coof.y = y;
	pt.coof.z = z;
	return (pt);
}

int		fdf_store_point(t_point points[MAX_PNT], t_point point)
{
	static int	i = 0;

	if (i > MAX_PNT - 1)
	{
		ft_dprintf(2, "Points tab overflow.\n");
		exit(0);
	}
	points[i++] = point;
	return (0);
}

int		fdf_store_obj(t_fdfobj objs[MAX_OBJ], t_fdfobj obj)
{
	static int	i = 0;

	if (i > MAX_OBJ - 1)
	{
		ft_dprintf(2, "Objs tab overflow.\n");
		exit(0);
	}
	objs[i++] = obj;
	return (0);
}

t_fdfobj	fdf_line(int apnt, int bpnt, t_co c)
{
	t_fdfobj	obj;

	ft_bzero(&obj, sizeof(t_fdfobj));
	obj.type = 1;
	obj.apointi = apnt;
	obj.bpointi = bpnt;
	obj.gr.ico = c;
	return (obj);
}

int			fdf_get_pnti(t_point points[MAX_PNT], char *name)
{
	int		i;

	i = 0;
	while (*points[i].name)
	{
		if (ft_strequ(points[i].name, name))
			return (i);
		i++;
	}
	return (-1);
}

t_fdfobj	fdf_line_str(t_point points[MAX_PNT], char *apnt, char *bpnt, t_co c)
{
	int			ai;
	int			bi;
	t_fdfobj	errobj;

	errobj.type = -1;
	if ((ai = fdf_get_pnti(points, apnt)) < 0)
		return (errobj);
	if ((bi = fdf_get_pnti(points, bpnt)) < 0)
		return (errobj);
	return (fdf_line(ai, bi, c));
}
*/
/*
** 'fdf_store_acav' error codes:
**		0: Reading done, Grid valid
**		1: Could not open av[1]. Exiting.
**		2: Grid is invalid for some reason. Exiting.
**		3: Could not open av[1] for second reading. Exiting.
*/

static void	acavgrid_validity(int ac, char *av[], int ret, t_fdf fdf)
{
	if (!ret)
		ft_printf("%UQs reading done: %dl/%dc/%dh\n", av[1],
				fdf.fdfsz.x, fdf.fdfsz.y, fdf.fdfsz.z);
	else
	{
		if (ret == 1)
			ft_dprintf(2, "%s\n", "Could not open av[1]. Exiting.");
		if (ret == 2)
			ft_dprintf(2, "%s\n", "Grid is invalid for some reason. Exiting.");
		if (ret == 3)
			ft_dprintf(2, "%s\n",
				"Could not open av[1] for second reading. Exiting.");
		exit(EXIT_FAILURE);
	}
	(void)ac;
}

static void	acavcolor_storedefault(t_fdf *fdf)
{
	fdf->num_avco = 3;
	fdf->avco[0] = DEFAULT_COLOR0;
	fdf->avco[1] = DEFAULT_COLOR1;
	fdf->avco[2] = DEFAULT_COLOR2;
}

static void	acavcolor_delta(t_fdf *fdf)
{
	if (fdf->num_avco == 1)
		return ;
	if (fdf->num_avco == 2)
		fdf->davco[0] = VCOTOD(
			(double)fdf->avco[1].s.r - (double)fdf->avco[0].s.r,
			(double)fdf->avco[1].s.g - (double)fdf->avco[0].s.g,
			(double)fdf->avco[1].s.b - (double)fdf->avco[0].s.b, 0.0);
	if (fdf->num_avco == 3)
	{
		fdf->davco[0] = VCOTOD(
			(double)fdf->avco[2].s.r - (double)fdf->avco[0].s.r,
			(double)fdf->avco[2].s.g - (double)fdf->avco[0].s.g,
			(double)fdf->avco[2].s.b - (double)fdf->avco[0].s.b, 0.0);
		fdf->davco[1] = VCOTOD(
			(double)fdf->avco[1].s.r - (double)fdf->avco[2].s.r,
			(double)fdf->avco[1].s.g - (double)fdf->avco[2].s.g,
			(double)fdf->avco[1].s.b - (double)fdf->avco[2].s.b, 0.0);
	}
}
static void	acavcolor_validity(int ret, t_fdf *fdf)
{
	int i;

	if (ret == 0)
	{
		i = -1;
		ft_printf("%d colors read:", fdf->num_avco);
		while (++i < fdf->num_avco)
			ft_printf("(:red:%2d :gre:%2d :cya:%2d:eoC:)",
				fdf->avco[i].s.r,
				fdf->avco[i].s.g, fdf->avco[i].s.b);
		ft_putchar('\n');
	}
	else
	{
		if (ret == 1)
			ft_dprintf(2, "Colors missing: Default colors loaded\n", ret);
		if (ret == 2)
			ft_dprintf(2, "Invalid av[2] string: Default colors loaded\n", ret);
		if (ret == 3)
			ft_dprintf(2, "av[2] is invalid for some reason:"
				" Default colors loaded\n", ret);
		if (ret == 4)
			ft_dprintf(2, "av[2] too long: Default colors loaded\n", ret);
		acavcolor_storedefault(fdf);
	}
}

void	fdf_store_imgs(t_fdf *fdf, int ac, char *av[])
{
	acavcolor_validity(fdf_store_acavcolor(ac, av, fdf), fdf);
	acavcolor_delta(fdf);
	acavgrid_validity(ac, av, fdf_store_acavgrid(ac, av, fdf), *fdf);

/* 	acav_store_points_colors(fdf, *fdf->pntm); */
/* 	exit(0); */
/*
	fdf_store_point(fdf->pnt, fdf_point("O", 0, 0, 0));
	fdf_store_point(fdf->pnt, fdf_point("x10", 10, 0, 0));
	fdf_store_point(fdf->pnt, fdf_point("y10", 0, 10, 0));
	fdf_store_point(fdf->pnt, fdf_point("z10", 0, 0, 10));
	fdf_store_point(fdf->pnt, fdf_point("x-10", -10, 0, 0));
	fdf_store_point(fdf->pnt, fdf_point("y-10", 0, -10, 0));
	fdf_store_point(fdf->pnt, fdf_point("z-10", 0, 0, -10));
	fdf_store_obj(fdf->obj, fdf_line_str(fdf->pnt, "O", "x10",
										VCOTOI(255, 0, 0, 0)));
	fdf_store_obj(fdf->obj, fdf_line_str(fdf->pnt, "O", "x-10",
										VCOTOI(70, 0, 0, 0)));
	fdf_store_obj(fdf->obj, fdf_line_str(fdf->pnt, "O", "y10",
										VCOTOI(0, 255, 0, 0)));
	fdf_store_obj(fdf->obj, fdf_line_str(fdf->pnt, "O", "y-10",
										VCOTOI(0, 70, 0, 0)));
	fdf_store_obj(fdf->obj, fdf_line_str(fdf->pnt, "O", "z10", 
										VCOTOI(0, 0, 255, 0)));
	fdf_store_obj(fdf->obj, fdf_line_str(fdf->pnt, "O", "z-10",
									VCOTOI(0, 0, 70, 0)));
*/
}
