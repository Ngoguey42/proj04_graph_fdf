/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 08:29:24 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/01 12:01:53 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <ft_debug.h>

#define TAB_INCREMENT 5

/*
** 'ft_tabadd' stores 'new' in '*atab' and may ask for a table resize, storing
**		the new 'first pointer' in 'atab'.
** 'realloc_table' reallocates the table represented in a 't_tabdt'
** ('realloc', stdlib's function is never allowed).
*/

static int	realloc_table(t_tabdt *s)
{
	void	**new;

	new = (void**)ft_crealloc(s->ptr, sizeof(void*) * s->size,
				sizeof(void*) * (s->size + 1 + TAB_INCREMENT));
	if (!new)
	{
		ft_putendl_fd("'realloc_tables' malloc failed", 2);
		return (1);
	}
	s->ptr = new;
	return (0);
}

int			ft_tabadd(void ***atab, void *new)
{
	t_tabdt	*s;

	ft_tabadddebug1(atab, new);
	if (!(s = ft_tabcc(*atab)))
		return (1);
	if (s->size % TAB_INCREMENT == 0)
	{
		ft_tabadddebug2(s, TAB_INCREMENT);
		if (realloc_table(s))
			return (1);
		ft_tabadddebug3(atab, s);
		*atab = s->ptr;
	}
	s->ptr[s->size++] = new;
	ft_tabadddebug4(s, new);
	return (0);
}

int			ft_tabaddm(void ***atab, void *new, size_t size)
{
	void	*newm;

	if (!(newm = ft_memdup(new, size)))
	{
		ft_putendl_fd("'ft_tabaddm' malloc failed", 2);
		return (1);
	}
	return (ft_tabadd(atab, newm));
}
