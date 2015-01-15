/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 07:44:42 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 08:42:25 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	fdf_init_window(t_fdf *fdf)
{
	if (!(SERVP = mlx_init()))
	{
		ft_putendl_fd("Could not establish connection to X-Window server.", 2);
		return (1);
	}
	if (!(fdf->win1 = mlx_new_window(SERVP, WIN_X, WIN_Y, "fdf")))
	{
		ft_putendl_fd("Could not create new window.", 2);
		return (1);
	}
	mlx_expose_hook(WIN1P, &fdf_expose_hook, fdf);
	mlx_hook(WIN1P, 2, 1, &fdf_keydo_hook, fdf);
	mlx_hook(WIN1P, 3, 2, &fdf_keyup_hook, fdf);
	mlx_loop_hook(SERVP, &fdf_loop_hook, fdf);
	fdf->s.img = mlx_new_image(SERVP, WIN_X, WIN_Y);
	fdf->s.dat = mlx_get_data_addr(fdf->s.img, &fdf->s.bpp,
							&fdf->s.lsz, &fdf->s.end);
	return (0);
}

int	fdf_init_surface(t_fdf fdf)
{
	(void)fdf;
	return (0);
}

int fdf_set_surface(t_fdf fdf)
{
	fdf_draw_screen(fdf);
	mlx_put_image_to_window(SERV, WIN1, fdf.s.img, 0, 0);
	return (0);
}

int	fdf_push_surface(t_fdf fdf)
{
	(void)fdf;
	return (0);
}

int	fdf_quit(t_fdf fdf)
{
	mlx_destroy_window(SERV, WIN1);
	(void)fdf;
	exit(EXIT_SUCCESS);
}
