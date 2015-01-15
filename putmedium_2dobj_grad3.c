/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmedium_2dobj_grad3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 08:37:35 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 08:37:53 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	init_counters(int *i, int j[2], t_cood *d, t_grad *gr)
{
	double	iterations;

	iterations = sqrt(d->x * d->x + d->y * d->y) * DENSITY;
	j[0] = (int)round((double)(ABS(iterations) + 1) * gr->v1);
	j[1] = ((int)round(ABS(iterations)) + 1) - j[0];
	gr->dtc1 = DCODIV(gr->dtc1, (double)j[0]);
	gr->dtc2 = DCODIV(gr->dtc2, (double)j[1]);
	*d = DCOODIV((*d), iterations);
	*i = j[0] + j[1];
	return ;
}

static void	send_pixel(t_fdf fdf, t_grad *gr, const t_cood *cooa, int type)
{
	if (type)
	{
		(void)fdf_puts_fpix(fdf, *cooa, DCOTOI(gr->stc1));
		gr->stc1 = DDCOADD(gr->stc1, gr->dtc1);
	}
	else
	{
		(void)fdf_puts_fpix(fdf, *cooa, DCOTOI(gr->stc2));
		gr->stc2 = DDCOADD(gr->stc2, gr->dtc2);
	}
	return ;
}

int			fdf_put_line_g3(t_fdf fdf, t_cood cooa, t_cood coob, t_grad gr)
{
	t_cood	d;
	int		i;
	int		j[2];
	int		t;

	d = ACOOTOD(coob.x - cooa.x, coob.y - cooa.y, 0);
	init_counters(&i, j, &d, &gr);
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
		send_pixel(fdf, &gr, &cooa, i >= j[1]);
		cooa = DCOOADDD(cooa, d);
	}
	return (0);
}
