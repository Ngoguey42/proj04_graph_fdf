/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:54:52 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 20:26:03 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *alst,
			t_list *lst_ref, int (*cmp)(t_list *lst, t_list *lst_ref))
{
	if (!alst || !lst_ref || !cmp)
		return (NULL);
	while (alst)
	{
		if (cmp(alst, lst_ref))
			return (alst);
		alst = alst->next;
	}
	return (NULL);
}
