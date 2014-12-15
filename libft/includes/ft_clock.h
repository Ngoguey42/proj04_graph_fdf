/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 10:00:22 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/12 14:01:55 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLOCK_H
# define FT_CLOCK_H

# include <time.h>
# include "ft_typedefs.h"

# define MAX_CLOCKS 10

/*
** 'struct s_clockev':
**      f:      function called.
**      data:   pointed passed to f.
**      dt:     delta time between calls, set by caller (clock tick).
**      cl:     calls left, set by caller.
**      el:     elapsed time since last call, set by ft_clock (clock tick).
**      type:   type of iterations.
**                  0x01. Conservation of #calls:
**                          while (el > dt) {el -= dt; [...]}
**                  0x02. Conservation of minumum time between calls.
**                          if (el > dt) {el = 0; [...]}
**                  0x10. Additional call on timer start.
*/

typedef struct			s_clockev
{
	int					(*f)(void *data);
	void				*data;
	clock_t				dt;
	int					cl;
	clock_t				el;
	int					type;
}						t_clockev;

void					ft_clock_updateone(t_clockev *ev);
void					ft_clock_loophook(void);
t_clockev				**ft_clockev_cc(t_clockev *new, int action);

#endif
