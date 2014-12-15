/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtfloor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:34:21 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:34:24 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ui32	ft_sqrtfloor(t_ui32 nb)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (result == 0)
	{
		if ((unsigned)i * i > nb)
		{
			result = i;
			i = nb;
		}
		else
			i++;
	}
	return (result - 1);
}
