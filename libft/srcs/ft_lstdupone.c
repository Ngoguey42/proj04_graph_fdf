/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdupone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:54:44 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:54:47 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Variables interpretations 'ft_lstdupone':
** 'lst' unprotected, segfaults if NULL.
** 'ft_lstnew' protected from NULL, and memory leaks.
*/

t_list	*ft_lstdupone(t_list *lst)
{
	return (ft_lstnew(lst->content, lst->content_size));
}
