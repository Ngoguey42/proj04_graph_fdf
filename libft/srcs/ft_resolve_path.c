/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:33:30 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/31 14:17:56 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_resolve_path' tries to shorten a path.
**		part1 removes multiple consecutive '/'.
**		part2 removes "/./" patterns.
**		way more to do.
*/

static void	part1(char *tmp)
{
	while (tmp[0] != '\0' && tmp[1] != '\0')
	{
		if (ft_strnequ(tmp, "/""/", 2))
			ft_memmove((void*)tmp, (void*)(tmp + 1), ft_strlen(tmp));
		else
			tmp++;
	}
	return ;
}

static void	part2(char *tmp)
{
	while (tmp[0] != '\0' && tmp[1] != '\0' && tmp[2] != '\0')
	{
		if (ft_strnequ(tmp, "/./", 3))
			ft_memmove((void*)tmp, (void*)tmp + 2, ft_strlen(tmp) - 1);
		else
			tmp++;
	}
	return ;
}

int			ft_resolve_path(char *buf)
{
	size_t	ilen;

	ilen = ft_strlen(buf);
	part1(buf);
	part2(buf);
	if (ilen != ft_strlen(buf))
		return (1);
	return (0);
}
