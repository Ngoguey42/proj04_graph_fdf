/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:09:14 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 15:37:14 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*ret;

	if (f)
	{
		new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!(ret = new))
			return (NULL);
		while (*s != '\0')
			*new++ = f(*s++);
		*new = '\0';
	}
	else
		ret = ft_strdup(s);
	return (ret);
}
