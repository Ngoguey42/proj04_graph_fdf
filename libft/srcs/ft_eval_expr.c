/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_expr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 12:12:17 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/31 14:49:07 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_eval_expr.h>

static int	evlxpr_deep(t_evx *alst[1])
{
	int total;

	total = 0;
	if (!(*alst)->oper)
	{
		total = (*alst)->value;
		(*alst) = (*alst)->next;
	}
	else if ((*alst)->oper == 3)
	{
		(*alst) = (*alst)->next;
		total = evlxpr_shallow(alst);
		(*alst) = (*alst)->next;
	}
	return (total);
}

static int	evlxpr_medium(t_evx *alst[1])
{
	int total;

	total = evlxpr_deep(alst);
	if ((*alst) == NULL)
		return (total);
	while ((*alst)->oper == 2)
	{
		(*alst) = (*alst)->next;
		if ((*alst) == NULL)
			return (total);
		total = evlxpr_calculate(total, evlxpr_deep(alst), (*alst)->ref);
		if ((*alst) == NULL)
			return (total);
	}
	return (total);
}

int			evlxpr_shallow(t_evx *alst[1])
{
	int	total;

	total = evlxpr_medium(alst);
	if ((*alst) == NULL)
		return (total);
	while ((*alst)->oper == 1)
	{
		(*alst) = (*alst)->next;
		if ((*alst) == NULL)
			return (total);
		total = evlxpr_calculate(total, evlxpr_medium(alst), (*alst)->ref);
		if ((*alst) == NULL)
			return (total);
	}
	return (total);
}

int			ft_eval_expr(char *str)
{
	t_evx	*alst[1];

	*alst = NULL;
	if (evlxpr_convert_chain(str, alst))
		return (0);
	return (evlxpr_shallow(alst));
}
