/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:51:45 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 16:30:05 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Variables interpretations 'ft_lstdel':
** 'alst' unprotected, segfaults if NULL.
** '*alst' has an interpretation if NULL.
** 'del' has an interpretation if NULL.
*/

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next;

	while (*alst != NULL)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next;
	}
}
