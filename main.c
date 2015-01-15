/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 08:40:35 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 08:44:35 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_set_defpos(t_fdf *fdf)
{
	fdf->co.x = STARTCAMX;
	fdf->co.y = STARTCAMY;
	fdf->co.z = STARTCAMZ;
	fdf->a.ph = STARTCAMPH;
	fdf->a.th = STARTCAMTH;
	return (0);
}

int	main(int ac, char *av[])
{
	t_fdf	fdf;

	ft_bzero(&fdf, sizeof(t_fdf));
	fdf_store_imgs(&fdf, ac, av);
	if (fdf_init_window(&fdf))
		return (1);
	fdf_set_defpos(&fdf);
	ft_bzero(&fdf.mvmt_clockev, sizeof(t_clockev));
	fdf.mvmt_clockev.f = &fdf_move_void;
	fdf.mvmt_clockev.data = (void*)&fdf;
	fdf.mvmt_clockev.dt = CLOCKS_PER_SEC / 24;
	fdf.mvmt_clockev.type = 0x11;
	fdf_pause(&fdf);
	return (0);
}
