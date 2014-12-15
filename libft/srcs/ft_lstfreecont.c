/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreecont.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:55:04 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 20:25:50 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**		Variables interpretations 'ft_lstfreecont':
** 'content' has an interpretation if NULL.
** 'size' all values relevant.
*/

void	ft_lstfreecont(void *content, size_t content_size)
{
	if (content)
		free(content);
	(void)content_size;
}
