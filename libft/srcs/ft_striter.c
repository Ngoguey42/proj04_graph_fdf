/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:48:13 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 14:18:05 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_striter' applies a given function on each chars of a 'C-string'.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (!f)
		return ;
	while (*s)
		f(s++);
}
