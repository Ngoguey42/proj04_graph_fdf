/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:52:02 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 20:21:28 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelif(t_list **alst, void (*del)(void*, size_t),
			t_list *lst_ref, int (*cmp)(t_list *lst, t_list *lst_ref))
{
	t_list *lst;
	t_list *next;

	if (!alst || !lst_ref || !cmp)
		return ;
	lst = *alst;
	while (lst)
	{
		next = lst->next;
		if (cmp(lst, lst_ref))
			ft_lstdelcur(alst, lst, del);
		lst = next;
	}
	return ;
}
