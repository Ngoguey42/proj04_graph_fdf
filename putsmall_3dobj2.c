/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsmall_3dobj2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 07:43:29 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 07:51:34 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		fdf_3d_line2(t_fdf fdf, t_fdfobj obj, t_point ap, t_point bp)
{
	t_cood	a2d;
	t_cood	b2d;

	a2d = fdf_get_pixproj(fdf, ap.coof);
	b2d = fdf_get_pixproj(fdf, bp.coof);
	fdf_put_line_grad(fdf, a2d, b2d, obj.gr);
	return (0);
}

static void	transcript_cood2(t_fdf fdf, t_cood *coof)
{
	coof->x -= fdf.co.x;
	coof->y -= fdf.co.y;
	coof->z -= fdf.co.z;
}

t_cood		fdf_get_pixproj(t_fdf fdf, t_cood coof)
{
	t_ang	ang;
	double tmp = coof.x;

	ang.ph = (fdf.a.ph);
	ang.th =  (fdf.a.th);
	transcript_cood2(fdf, &coof);
	coof.x = coof.x * cos(-ang.ph) - coof.y * sin(-ang.ph);
	coof.y = tmp * sin(-ang.ph) + coof.y * cos(-ang.ph);
	tmp = coof.x;
	coof.x = coof.x * cos(ang.th) + coof.z * sin(ang.th);
	coof.x = WIN_X / 2 + coof.x * 50.;
	coof.y = WIN_Y / 2 + coof.y * 50.;
	coof.z = 0;
	return (coof);
}
