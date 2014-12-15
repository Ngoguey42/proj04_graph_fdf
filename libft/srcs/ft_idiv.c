/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idiv_ceil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 07:30:09 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/09 08:32:09 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_math.h"

int		ft_idiv_ceil(int n, int d)
{
	int	ret;

	if (d == 0)
		return (0);
	ret = n / d;
	if (ret * d == n || (d < 0 && n > 0) || (n < 0 && d > 0))
		return (ret);
	return (ret + 1);
}

int		ft_idiv_floor(int n, int d)
{
	int	ret;

	if (d == 0)
		return (0);
	ret = n / d;
	if (ret * d == n || (d < 0 && n < 0) || (n > 0 && d > 0))
		return (ret);
	return (ret - 1);
}
