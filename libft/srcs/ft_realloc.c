/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 08:31:08 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/24 08:31:39 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (!(new = malloc(new_size)))
		return (NULL);
	if (new_size < old_size)
		old_size = new_size;
	if (ptr && old_size > 0)
	{
		ft_memcpy(new, ptr, old_size);
		free(ptr);
	}
	return (new);
}
