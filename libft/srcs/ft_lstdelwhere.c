/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelwhere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:53:34 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:54:26 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Variables interpretations 'all functions':
** 'alst' unprotected, segfaults if NULL.
** '*alst' has an interpretation if NULL.
** 'lst' has an interpretation if NULL.
** 'del' has an interpretation if NULL.
** ===============================================
**		Variables interpretations 'ft_lstdelprev':
** 'lst' presence in 'alst' verified, and mustn't be first.
**		Variables interpretations 'ft_lstdelcur':
** 'lst' presence in 'alst' verified.
**		Variables interpretations 'ft_lstdelnext':
** 'lst' presence in 'alst' verified, and mustn's be last.
*/

void	ft_lstdelfirst(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	tmp = ft_lstpullfirst(alst);
	if (tmp)
		ft_lstdelone(&tmp, del);
}

void	ft_lstdellast(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	tmp = ft_lstpulllast(alst);
	if (tmp)
		ft_lstdelone(&tmp, del);
}

void	ft_lstdelprev(t_list **alst, t_list *lst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	tmp = ft_lstpullprev(alst, lst);
	if (tmp)
		ft_lstdelone(&tmp, del);
}

void	ft_lstdelcur(t_list **alst, t_list *lst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	tmp = ft_lstpullcur(alst, lst);
	if (tmp)
		ft_lstdelone(&tmp, del);
}

void	ft_lstdelnext(t_list *lst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	tmp = ft_lstpullnext(lst);
	if (tmp)
		ft_lstdelone(&tmp, del);
}
