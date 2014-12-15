/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myassert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:26:11 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 18:26:24 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_myassert(int relation)
{
	if (relation)
	{
		ft_putstr("\033[32m");
		ft_putstr("_TRUE");
	}
	else
	{
		ft_putstr("\033[31m");
		ft_putstr("FALSE");
	}
	ft_putstr("\033[39m");
}
