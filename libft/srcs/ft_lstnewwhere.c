/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewwhere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:28:30 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 18:28:41 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**		Variables interpretations 'all functions':
** 'alst' unprotected, segfaults if NULL.
** 'content' interpretation if NULL.
** 'size' all values relevant.
** 'ft_lstnew' protected from NULL, and memory leaks.
** ===============================================
**		Variables interpretations 'ft_lstnewfront':
** '*alst' can be NULL.
**		Variables interpretations 'ft_lstnewback':
** '*alst' has an interpretation if NULL.
**		Variables interpretations 'ft_lstnewprev':
** 'lst' presence in 'alst' verified.
** 'ft_lstpushprev' protected from errors, and memory leaks.
**		Variables interpretations 'ft_lstnewnext':
** 'lst' presence in 'alst' verified.
** 'ft_lstpushnext' protected from errors, and memory leaks.
*/

t_list	*ft_lstnewfront(t_list **alst,
	void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	if (!new)
		return (NULL);
	ft_lstpushfront(alst, new);
	return (new);
}

t_list	*ft_lstnewback(t_list **alst,
	void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	if (!new)
		return (NULL);
	ft_lstpushback(alst, new);
	return (new);
}

t_list	*ft_lstnewprev(t_list **alst, t_list *lst,
	void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	if (!new)
		return (NULL);
	if (ft_lstpushprev(alst, lst, new))
	{
		ft_lstdelone(&new, &ft_lstfreecont);
		return (NULL);
	}
	return (new);
}

t_list	*ft_lstnewnext(t_list **alst, t_list *lst,
	void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	if (!new)
		return (NULL);
	if (ft_lstpushnext(alst, lst, new))
	{
		ft_lstdelone(&new, &ft_lstfreecont);
		return (NULL);
	}
	return (new);
}
