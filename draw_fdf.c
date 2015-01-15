/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 10:38:29 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 08:20:08 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		fdf_draw_screen(t_fdf fdf)
{
	t_fdfobj	*objs;
	t_fdfobj	**objs2;

	ft_memset(fdf.s.dat, 0, WIN_X * WIN_Y * 4);
	objs2 = *fdf.objm;
	while (*objs2)
	{
		objs = *objs2;
		if (objs->type == 1)
		{
			fdf_3d_line(fdf, *objs,
						*(*(fdf.pntm))[objs->apointi],
						*(*(fdf.pntm))[objs->bpointi]);
		}
		objs2++;
	}
	return (0);
}
