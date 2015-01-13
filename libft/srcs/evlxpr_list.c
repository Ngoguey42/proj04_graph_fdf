/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evlxpr_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 14:39:05 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/31 14:53:24 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_eval_expr.h>

static t_evx	*evlxpr_create_elem(int value, char oper, char ref)
{
	t_evx	*new;

	new = (t_evx*)malloc(sizeof(t_evx));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->value = value;
	new->oper = oper;
	new->ref = ref;
	return (new);
}

int				evlxpr_lpback(t_evx *alst[1], int v, char op, char ref)
{
	t_evx	*current;

	if (*alst == NULL)
	{
		*alst = evlxpr_create_elem(v, op, ref);
		if (*alst == NULL)
			return (1);
	}
	else
	{
		current = *alst;
		while (current->next != NULL)
			current = current->next;
		current->next = evlxpr_create_elem(v, op, ref);
		if (current->next == NULL)
			return (1);
	}
	return (1);
}

t_evx			*evlxpr_llast(t_evx *alst[1])
{
	t_evx	*current;

	if (!*alst)
		return (NULL);
	current = *alst;
	while (current->next)
		current = current->next;
	return (current);
}
