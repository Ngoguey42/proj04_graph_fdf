/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:28:00 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 16:11:27 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strtrim' allocates a copy of 's', trimmig 'spaces' at the end and the
** beginning.
** FINI A LA VA VITE, DEBUGGER
*/

char	*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	i;
	size_t	u;

	s += ft_strspn(s, " \t\n");
	u = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			u = i;
		i++;
	}
	if (!(ret = ft_strsub(s, 0, u + 1)))
		return (NULL);
	return (ret);
}
