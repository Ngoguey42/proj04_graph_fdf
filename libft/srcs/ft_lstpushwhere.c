/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushwhere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:38:05 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 16:31:10 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Variables interpretations 'all functions':
** 'alst' unprotected, segfaults if NULL.
** 'new' unprotected, segfaults if NULL.
** ===============================================
**		Variables interpretations 'ft_lstpushfront':
** '*alst' can be NULL.
**		Variables interpretations 'ft_lstpushback':
** '*alst' has an interpretation if NULL.
**		Variables interpretations 'ft_lstpushnext', 'ft_lstpushprev':
** 'lst' has an interpretation if NULL.
** '*alst' has an interpretation if NULL.
** 'lst' presence in 'alst' verified.
*/

int	ft_lstpushfront(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
	return (0);
}

int	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (*alst)
	{
		tmp = ft_lstlast(*alst);
		tmp->next = new;
	}
	else
		*alst = new;
	return (0);
}

int	ft_lstpushnext(t_list **alst, t_list *lst, t_list *new)
{
	t_list	*tmp;

	if ((*alst == NULL && lst == NULL) || (*alst != NULL && lst != NULL))
	{
		if (lst == NULL)
			*alst = new;
		else
		{
			tmp = *alst;
			while (tmp && tmp != lst)
				tmp = tmp->next;
			if (tmp == lst)
			{
				new->next = lst->next;
				lst->next = new;
			}
			else
				return (1);
		}
		return (0);
	}
	return (1);
}

int	ft_lstpushprev(t_list **alst, t_list *lst, t_list *new)
{
	t_list	*tmp;

	if ((*alst == NULL && lst == NULL) || (*alst != NULL && lst != NULL))
	{
		if (lst == *alst)
		{
			new->next = lst;
			*alst = new;
		}
		else
		{
			tmp = *alst;
			while (tmp->next && tmp->next != lst)
				tmp = tmp->next;
			if (tmp->next == lst)
			{
				tmp->next = new;
				new->next = lst;
			}
			else
				return (1);
		}
		return (0);
	}
	return (1);
}
