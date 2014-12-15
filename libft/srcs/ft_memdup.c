/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 08:34:59 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/24 08:36:39 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_memdup(void *p, size_t size)
{
	void	*new;

	if (!(new = malloc(size)))
		return (NULL);
	ft_memcpy(new, p, size);
	return (new);
}
