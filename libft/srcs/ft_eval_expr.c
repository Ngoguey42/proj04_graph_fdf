/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_expr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 12:12:17 by ngoguey           #+#    #+#             */
/*   Updated: 2014/07/21 09:50:45 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval_expr.h"

t_evlxpr_cell	*g_self;

static int	evlxpr_deep(void)
{
	int total;

	total = 0;
	if (!g_self->oper)
	{
		total = g_self->value;
		g_self = g_self->next;
	}
	else if (g_self->oper == 3)
	{
		g_self = g_self->next;
		total = evlxpr_shallow();
		g_self = g_self->next;
	}
	return (total);
}

static int	evlxpr_medium(void)
{
	int total;

	total = evlxpr_deep();
	if (g_self == NULL)
		return (total);
	while (g_self->oper == 2)
	{
		g_self = g_self->next;
		if (g_self == NULL)
			return (total);
		total = evlxpr_calculate(total, evlxpr_deep(), g_self->ref);
		if (g_self == NULL)
			return (total);
	}
	return (total);
}

int			evlxpr_shallow(void)
{
	int	total;

	total = evlxpr_medium();
	if (g_self == NULL)
		return (total);
	while (g_self->oper == 1)
	{
		g_self = g_self->next;
		if (g_self == NULL)
			return (total);
		total = evlxpr_calculate(total, evlxpr_medium(), g_self->ref);
		if (g_self == NULL)
			return (total);
	}
	return (total);
}

int			ft_eval_expr(char *str)
{
	t_evlxpr_cell	**beggining;

	beggining = evlxpr_convert_chain(str);
	g_self = *beggining;
	return (evlxpr_shallow());
}
