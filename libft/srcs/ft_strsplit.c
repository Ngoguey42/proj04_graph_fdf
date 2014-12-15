/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:27:34 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 15:13:18 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** 'ft_strsplit' allocates a table of strings contaning parts of a
** 'C-string' splitted with a delimiter.
** -
** static 'num_tabs' counts the number of 'words'
** static 'alloc_save_str' allocates memory for each strings.
** static 'populate_tabs' fills the tab.
*/

static size_t	num_tabs(char const *s, char c)
{
	size_t	l;
	int		t;

	l = 0;
	t = 0;
	while (*s)
	{
		if (*s == c)
		{
			l = (t == 1) ? l + 1 : l;
			t = 0;
		}
		else
			t = 1;
		s++;
	}
	return ((t == 1) ? l + 1 : l);
}

static char		*alloc_save_str(char const *s, char c, char **ret, size_t *i)
{
	ret[*i] = (char*)malloc(sizeof(char) * (ft_strcharlen(s, c) + 1));
	return (ret[(*i)++]);
}

static int		populate_tabs(char const *s, char c, char **ret, size_t i)
{
	char	*tmp;
	int		t;

	t = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (t == 1)
				*tmp = '\0';
			t = 0;
		}
		else
		{
			if (t == 0 && !(tmp = alloc_save_str(s, c, ret, &i)))
				return (1);
			*tmp++ = *s;
			t = 1;
		}
		s++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	l;
	char	**ret;

	l = num_tabs(s, c);
	if (!(ret = (char**)ft_memalloc(sizeof(char*) * (l + 1))))
		return (NULL);
	ret[l] = NULL;
	if (populate_tabs(s, c, ret, 0))
		return (NULL);
	return (ret);
}
