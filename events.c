/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 09:17:49 by ngoguey           #+#    #+#             */
/*   Updated: 2015/03/11 07:35:40 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** 'fdf_loop_hook': Called in a loop by X11.
**		1. Calls 'fdf_parse_events'
**			- Returns 1/0 whether at least a 'fdf->ev' in true or none.
**		2. If 'fdf_parse_events' returned 1, or skips this part.
**			- Updates fdf->mvmt_clockev (equiv. to reseting timer at 0.25 sec)
**			- Calls 'ft_clock_updateone' with 'mvmt_clockev'.
**		3. Calls 'ft_clock_loophook' (on every loop).
**			- May call X-times 'fdf_move_void'.
**				- 'fdf_move_void' parses 'fdf->ev', and may modifies cam coords.
**				- 'fdf_move_void' sets 'fdf->redraw' to true.
**		4. If 'fdf->redraw' == true, calls for redraw.
*/

int		fdf_parse_events(t_fdf fdf)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		if (fdf.ev[i])
			return (1);
		i++;
	}
	return (0);
}

int		fdf_loop_hook(t_fdf *fdf)
{
	if (fdf_parse_events(*fdf))
	{
		fdf->mvmt_clockev.cl = 6;
		ft_clock_updateone(&fdf->mvmt_clockev);
	}
	ft_clock_loophook();
	if (fdf->redraw)
	{
		fdf->redraw = 0;
		fdf_init_surface(*fdf);
		fdf_set_surface(*fdf);
		fdf_push_surface(*fdf);
	}
	return (0);
}

int		fdf_expose_hook(t_fdf *fdf)
{
	fdf_init_surface(*fdf);
	fdf_set_surface(*fdf);
	fdf_push_surface(*fdf);
	return (0);
}

int		fdf_keyup_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEYQUI)
		fdf_quit(*fdf);
	if (keycode == 'p' && (fdf->redraw = 1))
		fdf_set_defpos(fdf);
	else if (keycode == 'd')
		fdf->ev[0] = 0;
	else if (keycode == 'a')
		fdf->ev[1] = 0;
	else if (keycode == KEYTUP)
		fdf->ev[2] = 0;
	else if (keycode == KEYTDO)
		fdf->ev[3] = 0;
	else if (keycode == 's')
		fdf->ev[4] = 0;
	else if (keycode == 'w')
		fdf->ev[5] = 0;
	else if (keycode == 'e')
		fdf->ev[8] = 0;
	else if (keycode == 'q')
		fdf->ev[9] = 0;
	return (0);
}

int		fdf_keydo_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 'd')
		fdf->ev[0] = 1;
	else if (keycode == 'a')
		fdf->ev[1] = 1;
	else if (keycode == KEYTUP)
		fdf->ev[2] = 1;
	else if (keycode == KEYTDO)
		fdf->ev[3] = 1;
	else if (keycode == 's')
		fdf->ev[4] = 1;
	else if (keycode == 'w')
		fdf->ev[5] = 1;
	else if (keycode == 'e')
		fdf->ev[8] = 1;
	else if (keycode == 'q')
		fdf->ev[9] = 1;
	return (0);
}
