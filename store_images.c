/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 10:41:34 by ngoguey           #+#    #+#             */
/*   Updated: 2015/03/11 07:43:06 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

/*
** 'fdf_store_acav' error codes:
**		0: Reading done, Grid valid
**		1: Could not open av[1]. Exiting.
**		2: Grid is invalid for some reason. Exiting.
**		3: Could not open av[1] for second reading. Exiting.
*/

static void	acavgrid_validity(int ac, char *av[], int ret, t_fdf fdf)
{
	if (ret)
	{
		if (ret == 1)
			ft_putendl_fd("Could not open av[1]. Exiting.", 2);
		if (ret == 2)
			ft_putendl_fd("Grid is invalid for some reason. Exiting.", 2);
		if (ret == 3)
			ft_putendl_fd("Could not open av[1] for second reading. Exiting.",
				2);
		exit(EXIT_FAILURE);
	}
	(void)ac;
	(void)av;
	(void)fdf;
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
	if (ret != 0)
	{
		if (ret == 1)
			ft_putendl("Colors missing: Default colors loaded");
		if (ret == 2)
			ft_putendl("Invalid av[2] string: Default colors loaded");
		if (ret == 3)
			ft_putendl("av[2] is invalid for some reason:"
				" Default colors loaded");
		if (ret == 4)
			ft_putendl("av[2] too long: Default colors loaded");
		acavcolor_storedefault(fdf);
	}
}

void		fdf_store_imgs(t_fdf *fdf, int ac, char *av[])
{
	acavcolor_validity(fdf_store_acavcolor(ac, av, fdf), fdf);
	acavcolor_delta(fdf);
	fdf->fdfsz.z = 1.;
	acavgrid_validity(ac, av, fdf_store_acavgrid(ac, av, fdf), *fdf);
}
