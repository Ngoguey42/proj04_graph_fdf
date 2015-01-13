/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 08:26:57 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/31 14:13:57 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_tabdel(void ***atab)
{
	t_tabdt	*s;

	if (!(s = ft_tabcc(*atab)))
		return (1);
	free(s->ptr);
	ft_bzero((void*)s, sizeof(t_tabdt));
	*atab = NULL;
	return (0);
}

int		ft_tabdel2(void ***atab)
{
	t_tabdt	*s;
	void	**dts;

	if (!(s = ft_tabcc(*atab)) || !s->ptr)
		return (1);
	dts = s->ptr;
	while (*dts)
	{
		free(*dts);
		dts++;
	}
	free(s->ptr);
	ft_bzero((void*)s, sizeof(t_tabdt));
	*atab = NULL;
	return (0);
}

int		ft_tabdel3(void ***atab)
{
	t_tabdt	*s;

	if (!(s = ft_tabcc(*atab)))
		return (1);
	ft_bzero((void*)s, sizeof(t_tabdt));
	return (0);
}

int		ft_tabdelf(void ***atab, void (*f)(void *c))
{
	t_tabdt	*s;
	void	**dts;

	if (!(s = ft_tabcc(*atab)) || !s->ptr)
		return (1);
	dts = s->ptr;
	while (*dts)
	{
		f(*dts);
		dts++;
	}
	free(s->ptr);
	ft_bzero((void*)s, sizeof(t_tabdt));
	*atab = NULL;
	return (0);
}
