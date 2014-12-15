/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myputnchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:52:51 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 18:56:11 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putbs(char c, int *count)
{
	ft_putstr("\033[33m");
	ft_putnbr(c);
	ft_putstr("\033[39m");
	if (c < 0)
		(*count)++;
	if (c <= -10 || c >= 10)
		(*count)++;
	if (c <= -100 || c >= 100)
		(*count)++;
}

static void	putspecial(char c)
{
	ft_putstr("\033[33m\\");
	if (c == '\f')
		ft_putchar('f');
	else if (c == '\n')
		ft_putchar('n');
	else if (c == '\r')
		ft_putchar('r');
	else if (c == '\033')
		ft_putchar('e');
	else if (c > '\b')
		ft_putchar(c + 107);
	else
		ft_putchar(c + 90);
	ft_putstr("\033[39m");
}

int			ft_myputnchar(char *str, int num)
{
	int	count;

	if (!str)
	{
		ft_putstr("\033[33m(null)\033[39m");
		return (6);
	}
	count = 0;
	while (num > 0)
	{
		if (ft_isprint(*str))
			ft_putchar(*str);
		else if ((*str >= '\a' && *str <= '\r') || *str == '\033')
		{
			count++;
			putspecial(*str);
		}
		else
			putbs(*str, &count);
		str++;
		num--;
		count++;
	}
	return (count);
}
