/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 10:41:34 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 11:56:06 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
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

void		fdf_store_imgs(t_fdf *fdf, int ac, char *av[])
{
	acavcolor_validity(fdf_store_acavcolor(ac, av, fdf), fdf);
	acavcolor_delta(fdf);
	acavgrid_validity(ac, av, fdf_store_acavgrid(ac, av, fdf), *fdf);
}
