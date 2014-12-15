/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convsz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 15:36:34 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/01 11:57:30 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putexpchar(int exp, char *buffer)
{
	if (exp < 3)
		*buffer = 'B';
	else if (exp < 6)
		*buffer = 'K';
	else if (exp < 9)
		*buffer = 'M';
	else if (exp < 12)
		*buffer = 'G';
	else if (exp < 15)
		*buffer = 'T';
	else if (exp < 18)
		*buffer = 'P';
	else if (exp < 21)
		*buffer = 'E';
	else if (exp < 24)
		*buffer = 'Z';
	else if (exp < 27)
		*buffer = 'Y';
	else
		*buffer = '?';
}

int		ft_convsz(t_ui64 bytes, char *buffer)
{
	float	fl;
	int		tmp;
	int		exp;

	ft_bzero((void*)buffer, 5);
	exp = 0;
	fl = (float)bytes;
	while (!(fl < 1000))
	{
		fl /= 1024;
		exp += 3;
	}
	tmp = (int)ft_floor((double)fl);
	if (tmp >= 10 || exp == 0)
		ft_itoa_c(tmp, buffer, 10);
	else
	{
		buffer[0] = '0' + tmp;
		buffer[1] = '.';
		fl = (fl - (float)tmp) * 10;
		tmp = (int)ft_floor((double)fl);
		buffer[2] = '0' + tmp;
	}
	ft_putexpchar(exp, buffer + ft_strlen(buffer));
	return (exp);
}
