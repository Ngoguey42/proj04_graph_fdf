/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsmall_3dobj2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 07:43:29 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 11:55:17 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fdf.h>

#define PEACE(A1, A2) A1 A2; (void)A2


int		fdf_3d_line2(t_fdf fdf, t_fdfobj obj, t_point ap, t_point bp)
{
	PEACE(double, dx);
	PEACE(double, dy);
	PEACE(double, dz);
	PEACE(double, iterations);
	PEACE(int, i);

	(void)obj;
	t_cood	a2d;
	t_cood	b2d;
	a2d = fdf_get_pixproj(fdf, ap.coof);
	b2d = fdf_get_pixproj(fdf, bp.coof);
	if (1) //1 for straight lines; 0 for pixel per pixel draw
	{
		fdf_put_line_grad(fdf, a2d, b2d, obj.gr);
		return (0);
	}
/* 	dx = bp.coof.x - ap.coof.x; */
/*     dy = bp.coof.y - ap.coof.y; */
/*     dz = bp.coof.z - ap.coof.z; */

/* 	iterations = sqrt(dx * dx + dy * dy + dz * dz) * DENSITY3D; */
/* 	i = (int)ceil(ABS(iterations)); */

/* 	while (i-- && !DBG) */
/* 	{ */
/*         ap.coof.x += dx / iterations; */
/*         ap.coof.y += dy / iterations; */
/*         ap.coof.z += dz / iterations; */
/* 		fdf_3d_pix(fdf, ap.coof, ap.co); */
/* 	} */
/* 	(void)a2d; */
/* 	(void)b2d; */

/* 	return (0); */
}

void	transcript_cood2(t_fdf fdf, t_cood *coof)
{
	coof->x -= fdf.co.x;
	coof->y -= fdf.co.y;
	coof->z -= fdf.co.z;
}

t_cood	fdf_get_pixproj(t_fdf fdf, t_cood coof)
{
	t_ang	ang;

	ang.ph = (fdf.a.ph);
	ang.th =  (fdf.a.th);
	transcript_cood2(fdf, &coof);
	double tmp = coof.x;
	coof.x = coof.x * cos(-ang.ph) - coof.y * sin(-ang.ph);
	coof.y = tmp * sin(-ang.ph) + coof.y * cos(-ang.ph);
	tmp = coof.x;
	coof.x = coof.x * cos(ang.th) + coof.z * sin(ang.th);
	coof.x = WIN_X / 2 + coof.x * 50.;
	coof.y = WIN_Y / 2 + coof.y * 50.;
	coof.z = 0;
	return (coof);
}
