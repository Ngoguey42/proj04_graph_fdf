/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:28:26 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/25 11:42:33 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_clock.h>
#include <libft.h>

/*
** See ../includes/ft_clock.h for details.
** *
** 'ft_clock_updateone'	-updates an-/-add a new- event.
** 'ft_clock_loophook'	called in a loop, parses clocks, calls ev->f.
*/
/*
** Had to use a silly 'static const char*' because of school's norm.
*/

static const char	*ex_w(t_clockev *ev)
{
	while (ev->el >= ev->dt)
	{
		ev->el -= ev->dt;
		ev->cl--;
		ev->f(ev->data, ev->dt);
	}
	return (NULL);
}

static const char	*ex_i(t_clockev *ev)
{
	if (ev->el >= ev->dt)
	{
		ev->f(ev->data, ev->dt);
		ev->el = 0;
		ev->cl--;
	}
	return (NULL);
}

static const char	*ex_we(t_clockev *ev)
{
	int		calls_deducted;

	if (ev->el >= ev->dt)
	{
		calls_deducted = (int)((ev->el + ev->aht) / ev->dt);
		if (calls_deducted >= ev->cl)
		{
			ev->f(ev->data, ev->dt * (clock_t)(ev->cl) - ev->aht);
			ev->cl = 0;
			ev->el = 0;
			ev->aht = 0;
		}
		else
		{
			ev->f(ev->data, ev->el);
			ev->cl -= calls_deducted;
			ev->aht = (ev->el + ev->aht) % ev->dt;
			ev->el = 0;
		}
	}
	return (NULL);
}

void				ft_clock_updateone(t_clockev *ev)
{
	t_clockev		**evs;
	const char		*(*calls_tab[])(t_clockev *ev) = {ex_w, ex_w, ex_i, ex_we};

	evs = ft_clockev_cc(NULL, 0);
	while (*evs != NULL)
		if (*evs++ == ev)
			return ;
	ft_clockev_cc(ev, 2);
	if (ev->type & 0x10)
	{
		calls_tab[ev->type & 0x0f](ev);
		if (ev->cl <= 0)
			ft_clockev_cc(ev, 1);
	}
}

void				ft_clock_loophook(void)
{
	static clock_t	prev = 0;
	clock_t			cur;
	clock_t			elapsed;
	t_clockev		**evs;
	const char		*(*calls_tab[])(t_clockev *ev) = {ex_w, ex_w, ex_i, ex_we};

	if (prev == 0)
		prev = clock();
	cur = clock();
	elapsed = cur - prev;
	evs = ft_clockev_cc(NULL, 0);
	while (*evs != NULL)
	{
		(*evs)->el += elapsed;
		calls_tab[(*evs)->type & 0x0f](*evs);
		if ((*evs)->cl > 0)
			evs++;
		else
			ft_clockev_cc(*evs, 1);
	}
	prev = cur;
}
