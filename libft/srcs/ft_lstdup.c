/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:54:34 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/24 08:19:07 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Variables interpretations 'ft_lstdupone':
** 'lst' unprotected, but won't segfaults if NULL.
** 'ft_lstdupone' protected from NULL, and memory leaks.
*/

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*newa;
	t_list	*new;

	if (!(newa = ft_lstdupone(lst)))
		return (NULL);
	new = newa;
	while ((lst = lst->next))
	{
		if (!(new->next = ft_lstdupone(lst)))
		{
			ft_lstdel(&newa, &ft_lstfreecont);
			return (NULL);
		}
		new = new->next;
	}
	return (newa);
}
