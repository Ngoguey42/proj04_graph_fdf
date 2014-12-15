/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:27:47 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 15:23:25 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** 'ft_strsub' allocates a copy of 's', along with the specified indexes.
*/

char	*ft_strsub(char const *s, t_ui32 start, size_t len)
{
	char	*ret;

	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	s += start + len;
	ret += len;
	while (len-- != 0)
		*(--ret) = *(--s);
	return (ret);
}
