/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 14:13:47 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/31 14:13:48 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** 'ft_strsplit_s' like 'ft_strsplit' but takes several chars as delimiters.
*/

static size_t	num_strings(const char *str, char *delims)
{
	size_t	tmp;
	size_t	tot;

	tot = 0;
	while (*str != '\0')
	{
		tmp = ft_strspn(str, delims);
		if (tmp > 0)
			str += tmp;
		else
		{
			tot++;
			str += ft_strcspn(str, delims);
		}
	}
	return (tot);
}

static int		populate_tabs(const char *str, char *delims, char **ret)
{
	size_t	tmp;

	while (*str != '\0')
	{
		tmp = ft_strspn(str, delims);
		if (tmp > 0)
			str += tmp;
		else
		{
			tmp = ft_strcspn(str, delims);
			*ret = (char*)malloc(sizeof(char) * (tmp + 1));
			if (*ret == NULL)
				return (1);
			ft_strncpy(*ret, str, tmp);
			(*ret)[tmp] = '\0';
			ret++;
			str += tmp;
		}
	}
	return (0);
}

int				ft_strsplit_s(const char *str, char *delims, char ***ret)
{
	size_t	n_str;

	n_str = num_strings(str, delims);
	*ret = (char**)malloc(sizeof(char*) * (n_str + 1));
	if (*ret == NULL)
		return (1);
	(*ret)[n_str] = NULL;
	if (populate_tabs(str, delims, *ret))
		return (1);
	return (0);
}
