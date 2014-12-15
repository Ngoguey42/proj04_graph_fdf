/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 11:43:42 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/01 11:46:11 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** 'ft_catpath' concatenates a given path and file adding a '/' if required.
*/

char	*ft_catpath(const char *path, const char *file, char *dst)
{
	char	*dst_save;

	dst_save = dst;
	dst = ft_strccpy(dst, path);
	if (dst_save != dst && *(dst - 1) != '/')
		dst = ft_strccpy(dst, "/");
	ft_strccpy(dst, file);
	return (dst_save);
}
