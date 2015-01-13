/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 07:57:12 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 11:52:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Movement balance.
** dX, dY, dZ.
** Angles balance.
** dPI, dTH.
*/

/*
** 'balance_weights' balances directions and angles (if multiple keys pressed).
**			Returns a value to call for positions/angles updates.
** 'fdf_move'
*/

static int	balance_angles(double angweight[2])
{
	int		t;
	double	tot;
	double	tmp;
	int		i;

	i = 0;
	t = 0;
	tot = 0.0;
	while (i < 2)
	{
		tmp = ABS(angweight[i]);
		if (tmp > 0)
		{
			t |= 0x2;
			tot += tmp;
		}
		i++;
	}
	while (t && --i >= 0)
		angweight[i] /= tot; 
	return (t);
}

static int	balance_directions(double dirweight[3])
{
	int		t;
	double	tot;
	double	tmp;
	int		i;

	i = 0;
	t = 0;
	tot = 0.0;
	while (i < 3)
	{
		tmp = ABS(dirweight[i]);
		if (tmp > 0)
		{
			t |= 0x1;
			tot += tmp;
		}
		i++;
	}
	while (t && --i >= 0)
		dirweight[i] /= tot; 
	return (t);
}

static void	update_directions(double dirweight[3], t_fdf *fdf)
{
	fdf->co.x +=
		XYSPEEDBASE * dirweight[0] * cos(fdf->a.ph) +
		XYSPEEDBASE * dirweight[1] * cos(fdf->a.ph + M_PI / 2);
	fdf->co.y +=
		XYSPEEDBASE * dirweight[0] * sin(fdf->a.ph) +
		XYSPEEDBASE * dirweight[1] * sin(fdf->a.ph + M_PI / 2);
	fdf->co.z += ZSPEEDBASE * dirweight[2];
}

static void	update_angles(double angweight[2], t_fdf *fdf)
{
	fdf->a.ph += ASPEEDBASE * angweight[0];
	fdf->a.th += ASPEEDBASE * angweight[1];	
}

int			fdf_move(t_fdf *fdf)
{
	int		t;
	double	dirweight[3];
	double	angweight[2];

	dirweight[0] = (fdf->ev[0] == 1) ? 1.0 : 0.0 + (fdf->ev[1] == 1) ? -1.0 : 0.0;
	dirweight[1] = (fdf->ev[2] == 1) ? 1.0 : 0.0 + (fdf->ev[3] == 1) ? -1.0 : 0.0;
	dirweight[2] = (fdf->ev[6] == 1) ? 1.0 : 0.0 + (fdf->ev[7] == 1) ? -1.0 : 0.0;
	angweight[0] = (fdf->ev[4] == 1) ? 1.0 : 0.0 + (fdf->ev[5] == 1) ? -1.0 : 0.0;
	angweight[1] = (fdf->ev[9] == 1) ? 1.0 : 0.0 + (fdf->ev[8] == 1) ? -1.0 : 0.0;
	t = balance_directions(dirweight);
	t += balance_angles(angweight);
	if (t & 0x1)
		update_directions(dirweight, fdf);
	if (t & 0x2)		
		update_angles(angweight, fdf);
	if (t)
		fdf->redraw = 1;
	return (0);
}

int			fdf_move_void(void *fdf)
{
	return (fdf_move((t_fdf*)fdf));
}
