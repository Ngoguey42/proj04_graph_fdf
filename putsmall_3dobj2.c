/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsmall_3dobj2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 07:43:29 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/17 16:33:20 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fdf.h>

#define PEACE(A1, A2) A1 A2; (void)A2


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

void	transcript_cood2(t_fdf fdf, t_cood *coof)
{
	coof->x -= fdf.co.x;
	coof->y -= fdf.co.y;
	coof->z -= fdf.co.z;
}

# define DIST 2.00
# include <stdlib.h>
# include <gmp.h>


t_cood	fdf_get_pixproj(t_fdf fdf, t_cood coof)
{
/* 	t_cood	ret; */
	t_ang	ang;
/* 	double	r; */

/* 	qprintf("camx%.3f  camy %.3f  camz %.3f \n", fdf.co.x, fdf.co.y, fdf.co.z); */

/* 	r = sqrt(coof.x * coof.x + coof.y * coof.y + coof.z * coof.z); */
	ang.ph = (
		fdf.a.ph
		);
	ang.th =  (
		fdf.a.th
		);


	transcript_cood2(fdf, &coof);
/* 	qprintf("X%.3f Y%.3f \n", coof.x, coof.y); */
	double tmp = coof.x;
	coof.x = coof.x * cos(-ang.ph) - coof.y * sin(-ang.ph);
	coof.y = tmp * sin(-ang.ph) + coof.y * cos(-ang.ph);
/* 	qprintf("X%.3f Y%.3f \n", coof.x, coof.y);	 */


	tmp = coof.x;
	coof.x = coof.x * cos(ang.th) + coof.z * sin(ang.th);
/* 	coof.z = - tmp * sin(ang.th) - coof.z * cos(ang.th); */

/* 	coof.y = coof.y * cos(ang.th) - coof.z * sin(ang.th); */




	coof.x = WIN_X / 2 + coof.x * 50.;
	coof.y = WIN_Y / 2 + coof.y * 50.;
/* 	coof.x = coof.y * 5.0; */
/* 	qprintf("ICI=> %.3f\n", (double)coof.x); */
/* 	coof.y = (double)coof.x * (double)1.0; */

/* 	qprintf("ICI=> %.3f\n", (double)coof.y); */


/* 	qprintf("fX%.0f fY%.0f \n", (double)coof.x, (double)coof.y);	 */
/* 	qprintf("fX%.1f%% fY%.1f%% \n\n", coof.x / (double)WIN_X * 100, coof.y / (double)WIN_Y * 100);	 */

	coof.z = 0;
	return (coof);


/* 	ret.z = 0; */
/* 	return (ret); */
}
/* 	coof.x = coof.x * cos(-ang.ph) - coof.y * sin(-ang.ph); */
/* 	coof.y = coof.x * sin(-ang.ph) + coof.y * cos(-ang.ph); */
