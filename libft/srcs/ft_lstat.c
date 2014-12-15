/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:51:30 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 16:32:08 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Variables interpretations 'ft_lstat':
** 'lst' has an interpretation if NULL.
** 'size' all values relevant.
*/

t_list	*ft_lstat(t_list *lst, size_t s)
{
	if (!lst || s == 0)
		return (NULL);
	while (lst && --s)
		lst = lst->next;
	return (lst);
}
