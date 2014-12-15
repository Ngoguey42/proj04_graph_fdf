/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:46:55 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/07 11:44:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_memmove' copies the 'n' first bytes of 'source' to 'destination'.
** This function also handle overlap.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dstc;
	const char	*srcc = (const char*)src;

	if (src >= dst)
		ft_memcpy(dst, src, len);
	else
	{
		dstc = (char*)dst;
		while (len-- > 0)
			dstc[len] = (char)srcc[len];
	}
	return (dst);
}
