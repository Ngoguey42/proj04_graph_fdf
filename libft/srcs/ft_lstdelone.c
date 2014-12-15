/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:52:13 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:53:13 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Variables interpretations 'ft_lstdelone':
** 'alst' unprotected, segfaults if NULL.
** '*alst' unprotected, segfaults if NULL.
** 'del' has an interpretation if NULL.
*/

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (del)
		del((*alst)->content, (*alst)->content_size);
	ft_memdel((void**)alst);
}
