/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:24:14 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 16:39:38 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newa;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	newa = NULL;
	while (lst)
	{
		new = ft_lstdupone(f(lst));
		if (!new)
			return (NULL);
		ft_lstpushback(&newa, new);
		lst = lst->next;
	}
	return (newa);
}
