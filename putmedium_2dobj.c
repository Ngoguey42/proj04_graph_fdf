/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmedium_2dobj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 14:26:17 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/05 16:15:44 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** 'fdf_put_line' draws a simple 2d line.
** For a distance d, draws ceil(d)+1 points f
*/

int		fdf_put_line(t_fdf fdf, t_cood cooa, t_cood coob, t_co c)
{
	t_cood	d;
	double	iterations;
	int		i;
	int		t;

	d = ACOOTOD(coob.x - cooa.x, coob.y - cooa.y, 0);
	iterations = sqrt(d.x * d.x + d.y * d.y) * DENSITY;
	i = (int)round(ABS(iterations)) + 1;
	d = DCOODIV(d, iterations);
	t = 0;
	while (i--)
	{
		if (cooa.x < 0 || cooa.x > WIN_X || cooa.y < 0 || cooa.y > WIN_Y)
		{
			if (t == 0)
				continue ;
			break ;
		}
		t = 1;
		(void)fdf_puts_fpix(fdf, cooa, c);
		cooa = DCOOADDD(cooa, d);
	}
	return (0);
}

int		fdf_put_line_g2(t_fdf fdf, t_cood cooa, t_cood coob, t_grad gr)
{
	t_cood	d;
	double	iterations;
	int		i;
	int		t;

	d = ACOOTOD(coob.x - cooa.x, coob.y - cooa.y, 0);
	iterations = sqrt(d.x * d.x + d.y * d.y) * DENSITY;
	i = (int)round(ABS(iterations)) + 1;
	d = DCOODIV(d, iterations);
	gr.dtc1 = DCODIV(gr.dtc1, iterations);
	t = 0;
	while (i--)
	{
		if (cooa.x < 0 || cooa.x > WIN_X || cooa.y < 0 || cooa.y > WIN_Y)
		{
			if (t == 0)
				continue ;
			break ;
		}
		t = 1;
		(void)fdf_puts_fpix(fdf, cooa, DCOTOI(gr.stc1));
		gr.stc1 = DDCOADD(gr.stc1, gr.dtc1);
		cooa = DCOOADDD(cooa, d);
	}
	return (0);
}

int		fdf_put_line_g3(t_fdf fdf, t_cood cooa, t_cood coob, t_grad gr)
{
	t_cood	d;
	double	iterations;
	int		i;
	int		j[2];
	int		t;

	d = ACOOTOD(coob.x - cooa.x, coob.y - cooa.y, 0);
	iterations = sqrt(d.x * d.x + d.y * d.y) * DENSITY;
/* 	j[1] = (int)round((double)(ABS(iterations) + 1) * gr.v1); */
/* 	j[0] = ((int)round(ABS(iterations)) + 1) - j[1]; */
	j[0] = (int)round((double)(ABS(iterations) + 1) * gr.v1);
	j[1] = ((int)round(ABS(iterations)) + 1) - j[0];
	gr.dtc1 = DCODIV(gr.dtc1, (double)j[0]);
	gr.dtc2 = DCODIV(gr.dtc2, (double)j[1]);
	d = DCOODIV(d, iterations);
	i = j[0] + j[1];
	t = 0;
	while (i--)
	{
		if (cooa.x < 0 || cooa.x > WIN_X || cooa.y < 0 || cooa.y > WIN_Y)
		{
			if (t == 0)
				continue ;
			break ;
		}
		t = 1;
		if (i >= j[1])
		{
			(void)fdf_puts_fpix(fdf, cooa, DCOTOI(gr.stc1));
			gr.stc1 = DDCOADD(gr.stc1, gr.dtc1);
		}
		else
		{
			(void)fdf_puts_fpix(fdf, cooa, DCOTOI(gr.stc2));
			gr.stc2 = DDCOADD(gr.stc2, gr.dtc2);
		}
		cooa = DCOOADDD(cooa, d);
	}
	return (0);
}

int		fdf_put_line_grad(t_fdf fdf, t_cood cooa, t_cood coob, t_grad grad)
{
/* 	if (grad.type >= 2 && ((grad.agrad > grad.bgrad) || (grad.agrad < grad.bgrad))) */
/* 		return (fdf_put_line_g2(fdf, cooa, coob, grad)); */
	if (grad.type == 2)
		return (fdf_put_line_g2(fdf, cooa, coob, grad));
	if (grad.type == 3)
		return (fdf_put_line_g3(fdf, cooa, coob, grad));
	return (fdf_put_line(fdf, cooa, coob, grad.ico));
}
