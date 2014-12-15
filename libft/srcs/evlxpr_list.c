/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 11:39:42 by ngoguey           #+#    #+#             */
/*   Updated: 2014/07/19 17:38:37 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval_expr.h"

t_evlxpr_cell	*evlxpr_create_elem(int value, char oper, char ref)
{
	t_evlxpr_cell	*new;

	new = malloc(sizeof(t_evlxpr_cell));
	new->next = NULL;
	new->value = value;
	new->oper = oper;
	new->ref = ref;
	return (new);
}

void			evlxpr_lpback(t_evlxpr_cell **begin_list, int value, char oper,
				char ref)
{
	t_evlxpr_cell	*current;

	if (*begin_list == NULL)
		*begin_list = evlxpr_create_elem(value, oper, ref);
	else
	{
		current = *begin_list;
		while (current->next != NULL)
			current = current->next;
		current->next = evlxpr_create_elem(value, oper, ref);
	}
}

t_evlxpr_cell	*evlxpr_llast(t_evlxpr_cell **begin_list)
{
	t_evlxpr_cell	*current;

	if (!*begin_list)
		return (NULL);
	current = *begin_list;
	while (current->next)
		current = current->next;
	return (current);
}
