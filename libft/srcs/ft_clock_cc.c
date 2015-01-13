/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock_cc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:08:37 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/22 07:50:31 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_clock.h>
#include <libft.h>

/*
** See ../includes/ft_clock.h for details.
** *
** 'ft_clock_cc'	stores clocks.
*/

static void		fill_hole(t_clockev *evs[MAX_CLOCKS + 1], int hole)
{
	int	i;

	i = MAX_CLOCKS;
	while (--i > hole)
	{
		if (evs[i] != NULL)
		{
			evs[hole] = evs[i];
			evs[i] = NULL;
			return ;
		}
	}
	evs[hole] = NULL;
}

static int		remove_entry(t_clockev *evs[MAX_CLOCKS + 1], t_clockev *ev)
{
	int	i;

	i = 0;
	while (evs[i] != NULL)
	{
		if (evs[i] == ev)
		{
			fill_hole(evs, i);
			return (1);
		}
		i++;
	}
	return (0);
}

static int		add_entry(t_clockev *evs[MAX_CLOCKS + 1], t_clockev *new)
{
	int	i;

	i = 0;
	while (i < MAX_CLOCKS)
	{
		if (evs[i] == NULL)
		{
			evs[i] = new;
			return (0);
		}
	}
	ft_putendl_fd("Clock command center overflow.", 2);
	return (1);
}

t_clockev		**ft_clockev_cc(t_clockev *ev, int action)
{
	static t_clockev	*evs[MAX_CLOCKS + 1] = {NULL};

	if (ev != NULL)
	{
		if (action == 1)
			remove_entry(evs, ev);
		else if (action == 2)
			if (add_entry(evs, ev))
				return (NULL);
	}
	return (evs);
}
