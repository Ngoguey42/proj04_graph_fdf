/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_dec_float_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:44:19 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 08:48:18 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_math.h"
#include "math.h"

#define PRE part->precision

static char		*build_intpart(double nbr, int *round)
{
	int		exp;
	char	*str;
	char	*save;
	double	lol;
	double	tmp;
	int		i;

	if (nbr < 1)
		return (ft_strdup("0"));
	exp = (int)ft_ceil(ft_log10(nbr));
	i = 0;
	lol = 1;
	while (i++ < (exp - 1))
		lol *= 10;
	str = (char*)malloc((exp + 1) * sizeof(char));
	save = str;
	while (exp--)
	{
/* 		if (PRE == 0 && exp == 0) */
/* 			tmp = round(nbr / lol); */
/* 		else */
			tmp = ft_floor(nbr / lol);

			*str++ = (int)tmp + '0';
		nbr = nbr - tmp * lol;
		lol /= 10;
	}
	*round = nbr < 0.5 ? 0 : 1;
	*str = '\0';
	return (save);
}

static char		*build_decpart(double nbr, int pre, int *round)
{
	char	*str;
	char	*save;
	double	div;
	double	tmp;

	str = (char*)malloc((pre + 1) * sizeof(char));
	div = 1;
	save = str;
	nbr -= ft_floor(nbr);
	while (pre--)
	{
/* 		nbr *= 10; */
		div /= 10;
/* 		if (pre == 0) */
/* 			*str++ = ((int)ft_ceil(nbr)) % 10 + '0'; */
/* 		else */
		tmp = ft_floor(nbr / div);
/* 		qprintf("%.0f\n", nbr); */
		*str++ = (int)tmp + '0';
		nbr = nbr - tmp * div;
	}
	*round = (nbr / div) < 0.5 ? 0 : 1;
/* 	qprintf("[%.2f]\n", (nbr / div)); */
	*str = '\0';
	return (save);
}

static char		*round_up(char *str)
{
	int		i;
/* 	qprintf("roudning"); */
	i = ft_strlen(str);
	while (i--)
	{
		if (str[i] == '9')
			str[i] = '0';
		else if (str[i] == '.')
			continue ;
		else
		{
			str[i]++;
			break ;
		}
	}
	return (str);
}

char			*ptf_build_decnbr(double nbr, t_printf_part *part)
{
	char	*str;
	int		round;

	round = 0;
	str = build_intpart(ABS(nbr), &round);
	if (PRE > 0)
	{
		str = ft_strjoinfree(str, ".", 1, 0);
		str = ft_strjoinfree(str, build_decpart(ABS(nbr), PRE, &round), 1, 1);
	}
	if (round)
		round_up(str);
	return (str);
}
