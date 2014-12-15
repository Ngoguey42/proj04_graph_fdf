/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 10:35:39 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/12 10:20:25 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

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

	#define PRINTCOORD(STRU) qprintf("%s: %.1f %.1f %.1f\n", #STRU, (double)STRU.x, (double)STRU.y, (double)STRU.z)

	ft_bzero(&fdf, sizeof(t_fdf));
	// exit(0);
	fdf_store_imgs(&fdf, ac, av);
	if (fdf_init_window(&fdf))
		return (1);
	fdf_set_defpos(&fdf);
	fdf.mvmt_clockev = (t_clockev){&fdf_move_void, &fdf,
							CLOCKS_PER_SEC / 24, 0, 0, 0x11};
	fdf_pause(&fdf);
	return (0);
}
