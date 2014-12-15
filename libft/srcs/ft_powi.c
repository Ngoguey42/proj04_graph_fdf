/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:11:09 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 10:12:17 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_powi(int n, t_ui32 p)
{
	int	total;

	total = 1;
	while (p--)
		total *= n;
	return (total);
}

t_i64	ft_lpowi(t_i64 n, t_ui32 p)
{
	t_i64	total;

	total = 1;
	while (p--)
		total *= n;
	return (total);
}
