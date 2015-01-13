/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 10:38:29 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 11:51:07 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <string.h>

int		fdf_draw_screen(t_fdf fdf)
{
    t_fdfobj	*objs = fdf.obj;
	t_fdfobj	**objs2 = *fdf.objm;

	ft_memset(fdf.s.dat, 0, WIN_X * WIN_Y * 4);
    while (*objs2)
    {
		objs = *objs2;
        if (objs->type == 1)
        {
			fdf_3d_line2(fdf, *objs, 
						*(*(fdf.pntm))[objs->apointi],
						*(*(fdf.pntm))[objs->bpointi]);
        }
        objs2++;
    }
	return (0);
}
