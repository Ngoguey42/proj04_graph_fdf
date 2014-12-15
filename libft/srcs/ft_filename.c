/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 11:41:15 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/01 11:43:34 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** 'ft_filename' extracts a file name from a file path.
*/

char	*ft_filename(const char *path, char *dst)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(path);
	i = 0;
	while (len-- > 0)
	{
		if (i == 0 && path[len] == '/')
			continue ;
		if (i != 0 && path[len] == '/')
			break ;
		dst[i++] = path[len];
	}
	dst[i] = '\0';
	return (ft_revstr(dst));
}
