/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 10:38:29 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 13:28:54 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <string.h>

int		fdf_draw_screen(t_fdf fdf)
{
	int		i;
	int		j;
	int		k;

	(void)i;
	(void)j;

	for (k = 0; k < 1;k++)
	{
		ft_memset(fdf.s.dat, 0, WIN_X * WIN_Y * 4);
/* 	j = 0; */
/* 	for (i = 0; i < (fdf.s.bpp / 8 * WIN_X * WIN_Y) ; i++) */
/* 	{ */
/* 		fdf.s.dat[i] = 0; */
/* 		j++; */
/* 	} */

	}
    t_fdfobj      *objs = fdf.obj;
/*     t_point       *points = fdf.pnt; */
/*     while (objs->type) */
/*     { */
/*         if (objs->type == 1) */
/*         { */
/* 			fdf_3d_line(fdf, points[objs->apointi].coof, */
/* 						points[objs->bpointi].coof, objs->co1); */
/*         } */
/*         objs++; */
/*     } */
	t_fdfobj	**objs2 = *fdf.objm;
/*     t_point		**points2 = *fdf.pntm; */

/* 	j = 0; */
    while (*objs2)
    {
		objs = *objs2;
/* 		points = *points2; */
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
