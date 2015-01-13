/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 10:00:22 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/22 09:24:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLOCK_H
# define FT_CLOCK_H

# include <time.h>
# include "ft_typedefs.h"

# define MAX_CLOCKS 10

/*
** 'struct s_clockev':
**	  f:		function called.
**	  data:		pointed passed to 'f'.
**	  dt:		delta time between calls, set by caller (clock tick).
**	  cl:		calls left, set by caller.
**	  el:		elapsed time since last call, set by ft_clock (clock tick).
**    aht:		ahead time, used in weighting type.
**	  type:		type of iterations.
**				  0x01. Conservation of #calls and (el * cl):
**						  while (el > dt) {el -= dt; cl--; [...]}
**						calls ev-f(ev->data);
** *
**				  0x02. Conservation of #calls and min time between calls.
**						  if (el > dt) {el = 0; cl--; [...]}
**						calls ev-f(ev->data);
** *
**				  0x03. Weighting,
**						Conservation of (el * cl) and min time between calls.
**						  if (el > dt) {[...]; el = 0;} (see function)
**						calls ev-f(ev->data, ev->el);
** *
**				  0x10. Additional call on timer start.
*/

/*
** ***Three parameters***
** *
** 'NumCalls'		Number of 'f' calls upon full length.
** 'FullLength'		Expected time between start and end.
** 'DeltaTime'		Minimum time between calls.
** *
** *
** ***Three ways of calling 'f'***
** *
** #0x01 ==>		Conservation of 'FullLength', and 'NumCalls'.
**		Downside: 	Loosing 'DeltaTime'.
**						Not recomended if 'f' is a heavy function.
** *
** #0x02 ==>		Conservation of 'DeltaTime', and 'NumCalls'.
**		Downside: 	Loosing 'FullLength'.
**						Not recommended for events that requires precision.
** *
** #0x03 ==>		Conservation of 'DeltaTime', and 'FullLength'.
**		Downside: 	Loosing 'NumCalls'.
**						'f' has to handle the elapsed time argument.
*/

typedef struct			s_clockev
{
	int					(*f)();
	void				*data;
	clock_t				dt;
	int					cl;
	clock_t				el;
	clock_t				aht;
	int					type;
}						t_clockev;

void					ft_clock_updateone(t_clockev *ev);
void					ft_clock_loophook(void);
t_clockev				**ft_clockev_cc(t_clockev *new, int action);

#endif
