/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:28:26 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/12 14:01:40 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_clock.h>
#include <libft.h>

static void		exec_clockev_w(t_clockev *ev)
{
	while (ev->el >= ev->dt)
	{
		ev->el -= ev->dt;
		ev->cl--;
		ev->f(ev->data);
	}
}

static void		exec_clockev_i(t_clockev *ev)
{
	if (ev->el >= ev->dt)
	{
		ev->el = 0;
		ev->cl--;
		ev->f(ev->data);
	}
}

void	ft_clock_updateone(t_clockev *ev)
{
	t_clockev		**evs;

	evs = ft_clockev_cc(NULL, 0);
	while (*evs != NULL)
	{
		if (*evs == ev)
		{
			return ;
		}
	}
	ft_clockev_cc(ev, 2);
	if (ev->type & 0x10)
	{
        if ((ev->type & 0x0f) == 0x02)
            exec_clockev_i(ev);
		else
            exec_clockev_w(ev);
        if (ev->cl <= 0)
            ft_clockev_cc(ev, 1);
	}
}

void			ft_clock_loophook(void)
{
	static clock_t	prev = 0;
	clock_t			cur;
	clock_t			elapsed;
	t_clockev		**evs;

	if (prev == 0)
		prev = clock();
	cur = clock();
	elapsed = cur - prev;
	evs = ft_clockev_cc(NULL, 0);
	while (*evs != NULL)
	{
		(*evs)->el += elapsed;
		if (((*evs)->type & 0x0f) == 0x02)
			exec_clockev_i(*evs);
		else
			exec_clockev_w(*evs);
		if ((*evs)->cl > 0)
			evs++;
		else
			ft_clockev_cc(*evs, 1);
	}
	prev = cur;
}
