/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsmall_3dobj2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 07:43:29 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 15:03:59 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fdf.h>

#define PEACE(A1, A2) A1 A2; (void)A2

void	transcript_cood2(t_fdf fdf, t_cood *coof)
{
	coof->x -= fdf.co.x;
	coof->y -= fdf.co.y;
	coof->z -= fdf.co.z;
}

int		fdf_3d_line2(t_fdf fdf, t_fdfobj obj, t_point ap, t_point bp)
/* int		fdf_3d_line2(t_fdf fdf, t_point ap, t_point bp) */
{
	PEACE(double, dx);
	PEACE(double, dy);
	PEACE(double, dz);
	PEACE(double, iterations);
	PEACE(int, i);
/* 	t_point ap = obj.ap; */
/* 	t_point bp = obj.bpoint; */
	(void)obj;
	t_cood	a2d;
	t_cood	b2d;

/* 	printf("Coords a (%.3f, %.3f, %.3f)\n", ap.coof.x, ap.coof.y, ap.coof.z); */
/* 	printf("Coords b (%.3f, %.3f, %.3f)\n", bp.coof.x, bp.coof.y, bp.coof.z); */
	a2d = fdf_get_pixproj(fdf, ap.coof);
	b2d = fdf_get_pixproj(fdf, bp.coof);

/* 	t_co c; */

/* 	c = VCOTOI(100, 0, 0, 0); */

	if (1) //1 for straight lines; 0 for pixel per pixel draw
	{
/* 		if (obj.cotype == 2) */
/* 			; */
/* 		else if (obj.cotype == 3) */
/* 			; */
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

t_cood	fdf_get_pixproj(t_fdf fdf, t_cood coof)
{
	t_cood	ret;
	t_ang	ang;
	double	r;

	transcript_cood2(fdf, &coof);
	r = sqrt(coof.x * coof.x + coof.y * coof.y + coof.z * coof.z);
	ang.ph = (
		atan(coof.y / coof.x)
		- fdf.a.ph);
	ang.th = M_PI / 2 - (fdf.a.th - acos(coof.z / (r)));
	ret.x = WIN_X / 2 - WIN_X / 2 * (ang.ph / PHMAX);
	ret.y = WIN_Y / 2 + WIN_Y / 2 * ((ang.th - M_PI / 2) / THDELTA);
	ret.z = 0;
	return (ret);
}
