/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiterif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:55:26 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 20:25:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiterif(t_list *lst, void (*f)(t_list *elem),
			t_list *lst_ref, int (*cmp)(t_list *lst, t_list *lst_ref))
{
	if (!lst || !f || !lst_ref || !cmp)
		return ;
	while (lst)
	{
		if (cmp(lst, lst_ref))
			f(lst);
		lst = lst->next;
	}
}
