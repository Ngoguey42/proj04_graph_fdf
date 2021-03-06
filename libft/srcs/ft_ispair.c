/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:05:25 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 10:05:29 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ispair(int c)
{
	if (!ft_isalnum(c))
		return (-1);
	if (ft_isdigit(c))
		return (c % 2 == 0);
	else
		return (c % 2 == 1);
	return (0);
}
