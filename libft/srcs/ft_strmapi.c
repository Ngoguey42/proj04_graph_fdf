/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:25:18 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 15:39:06 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	char	*ret;
	size_t	i;

	if (f)
	{
		new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!(ret = new))
			return (NULL);
		i = 0;
		while (*s)
			*new++ = f(i++, *s++);
		*new = '\0';
	}
	else
		ret = ft_strdup(s);
	return (ret);
}
