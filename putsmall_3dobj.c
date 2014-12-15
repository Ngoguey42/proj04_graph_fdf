/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsmall3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 16:44:19 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/04 07:23:24 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fdf.h>

#define PEACE(A1, A2) A1 A2; (void)A2

void	transcript_cood(t_fdf fdf, t_cood *coof)
{
	coof->x -= fdf.co.x;
	coof->y -= fdf.co.y;
	coof->z -= fdf.co.z;
}

int		fdf_3d_line(t_fdf fdf, t_cood cooa, t_cood coob, t_co c)
{
	PEACE(double, dx);
	PEACE(double, dy);
	PEACE(double, dz);
	PEACE(double, iterations);
	PEACE(int, i);
	t_cood	a2d;
	t_cood	b2d;

/* 	printf("Coords a (%.3f, %.3f, %.3f)\n", cooa.x, cooa.y, cooa.z); */
/* 	printf("Coords b (%.3f, %.3f, %.3f)\n", coob.x, coob.y, coob.z); */
	a2d = fdf_3d_pix(fdf, cooa, c);
	b2d = fdf_3d_pix(fdf, coob, c);


	if (1)
	{
		fdf_put_line(fdf, a2d, b2d, c);
		return (0);
	}
	dx = coob.x - cooa.x;
    dy = coob.y - cooa.y;
    dz = coob.z - cooa.z;

	iterations = sqrt(dx * dx + dy * dy + dz * dz) * DENSITY3D;
	i = (int)ceil(ABS(iterations));

	while (i-- && !DBG)
	{
        cooa.x += dx / iterations;
        cooa.y += dy / iterations;
        cooa.z += dz / iterations;
		fdf_3d_pix(fdf, cooa, c);
	}
	(void)a2d;
	(void)b2d;

	return (0);
}

# include <stdlib.h>


t_cood	fdf_3d_pix(t_fdf fdf, t_cood coof, t_co c)
{
	t_cood	ret;

	PEACE(t_ang, baang);
	PEACE(t_ang, reang);
	PEACE(double, r);
	PEACE(t_cood, coo2d);

/*     printf("Coords from Ori   PIX: (%.3f, %.3f, %.3f)\n", coof.x, coof.y, \ */
/* 		   coof.z); */

	transcript_cood(fdf, &coof); 

if (DBG)
printf("Coords from Cam   PIX: (%.3f, %.3f, %.3f)\n", coof.x, coof.y, coof.z);

	r = sqrt(coof.x * coof.x + coof.y * coof.y + coof.z * coof.z);
if (DBG)
printf("Distance    CAM ->PIX: %.3f\n", r);

if (DBG)
printf("Coords from Cam2  PIX: (%.3f, %.3f, %.3f)\n", coof.x, coof.y, coof.z);



	baang.ph = atan(coof.y / coof.x);
/* 	baang.th = asin(coof.x / (r * cos(baang.ph))); */
/* 	baang.th = asin(coof.y / (r * sin(baang.ph))); */
	baang.th = acos(coof.z / (r));

	reang.ph = (baang.ph - fdf.a.ph);
	reang.th = M_PI / 2 - (fdf.a.th - baang.th);

if (DBG)
printf("Rel angle   CAM-> PIX: (%.3f, %.3f) * pi\n", reang.ph / M_PI, reang.th / M_PI);
if (DBG)
printf("Angle Limits Xphi: g, d(%.3f, %.3f)*pi Ythe: h, b , delta(%.3f, %.3f, %.3f) * pi\n", 
PHMAX / M_PI,  PHMIN / M_PI, 
	   THMIN / M_PI,  THMAX / M_PI, THDELTA / M_PI
);
	PEACE(double, test1);
	PEACE(double, test2);
	PEACE(double, screenx);
	PEACE(double, screeny);
	PEACE(double, tmpx);
	PEACE(double, tmpy);

	PEACE(double, maxx);
	PEACE(double, maxy);
	test1 = reang.ph;
	test2 = ((reang.th - M_PI / 2));
	if (DBG)
		printf("myphi %.3f     maxphi%.3f\n", test1/ M_PI, PHMAX/ M_PI);
	if (DBG)
		printf("mythe %.3f     maxthe%.3f\n", test2/ M_PI, THDELTA/ M_PI);

	screenx = WIN_X / 2 - WIN_X / 2 * (test1 / PHMAX);
	screeny = WIN_Y / 2 + WIN_Y / 2 * (test2 / THDELTA);
if (DBG)
	printf("ScreenPOS    X%.1f%%  Y%.1f%%\n", screenx / WIN_X * 100, screeny / WIN_Y * 100);


if (DBG)
	printf("\n");
ret.x = screenx;
ret.y = screeny;
ret.z = 0;
	if (screenx > 0 && screenx < WIN_X && screeny > 0 && screeny < WIN_Y)
	{
		coo2d.x = screenx;
		coo2d.y = screeny;
		fdf_puts_fpix(fdf, coo2d, c);

	}

	return (ret);
}
