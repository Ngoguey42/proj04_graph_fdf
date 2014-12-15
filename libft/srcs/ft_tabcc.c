/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 08:27:28 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 12:13:14 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_debug.h>
#include "libft.h"

#define MAX_TABLES	500
#define DEBUGCC		1

/*
** 'ft_tabcc' handles up to MAX_TABLES tables stored in 't_tabdt'.
**		The function returns the requested tables's 't_tabdt'.
** 'request_index' searches or allow a new index for 'requested'.
*/

/*
** 'ft_tabcc' returns a pointer to a 't_tabdt' or NULL if MAX_TABLES exceed.
*/

void		ft_tabdebug1(void **requested)
{
	if (!FTDEBUG_TABLELIB)
		return ;
	ft_printf("%JsREQU ptr{%p}\n", "TAB CC  ", requested);
}

void		ft_tabdebug2(t_tabdt tables[], int i)
{
	if (!FTDEBUG_TABLELIB)
		return ;
	ft_printf("%JsRETU ptr{%p} ", "TAB CC  ", tables[i].ptr);
	ft_printf("t_tabdt[%Hd]{%p} of size(%d)\n", i, &tables[i], tables[i].size);
}

static int	request_index(t_tabdt tables[MAX_TABLES], void **requested)
{
	static int	i = 0;
	int			j;

	if (i < MAX_TABLES && tables[i].ptr == requested)
		return (i);
	j = -1;
	i = 0;
	while (i < MAX_TABLES)
	{
		if (tables[i].ptr == requested)
			return (i);
		if (j < 0 && !tables[i].ptr)
			j = i;
		i++;
	}
	if (j >= 0)
		return (j);
	ft_putendl_fd("Tables command center overflow", 2);
	return (j);
}

t_tabdt		*ft_tabcc(void **requested)
{
	static t_tabdt	tables[MAX_TABLES];
	static int		initialized = 0;
	int				i;

	ft_tabdebug1(requested);
	if (!initialized)
	{
		ft_bzero((void*)tables, MAX_TABLES * sizeof(t_tabdt));
		initialized++;
	}
	i = request_index(tables, requested);
	if (i < 0)
		return (NULL);
	ft_tabdebug2(tables, i);
	return (&tables[i]);
}
