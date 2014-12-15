/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbitarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:00:54 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 20:01:54 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ui64	ft_getbitarray(unsigned char *nbr, size_t first, size_t last)
{
	t_ui64			ret;
	unsigned char	*ptr;
	size_t			i;

	ret = 0;
	ptr = (unsigned char*)&ret;
	i = first;
	while (i <= last)
	{
		if (nbr[i / 8] & (1 << (i % 8)))
			ptr[(i - first) / 8] |= (1 << ((i - first) % 8));
		i++;
	}
	return (ret);
}
