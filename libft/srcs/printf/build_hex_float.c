/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hex_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:39:56 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/09 14:40:31 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_math.h"

#define HEXFL_HAS_PREFIX (type % 2 == 0 || AND_F(PLUS_MASK) || AND_F(SPAC_MASK))
#define HEXFL_LEN_PLUS_PREFIX (ft_strlen(str) + (HEXFL_HAS_PREFIX ? 1 : 0))

#define WID part->width
#define PRE part->precision

#define GET_CHAR(DELTA) ((*ptr)[pre + (DELTA)])

/*
** 'round_mantissa_b16' rounds the decimal part.
** 'build_zero' builds the number if it's equal to +/-zero.
** 'build_hex_sci' builds the number, and adds leading zeroes and prefixes.
** 'build_nbr_13' %a.
*/

void			round_mantissa_b16(char **ptr, int pre, int *int_part_two)
{
	int	i;

	if (((int)ft_strlen(*ptr) - 1) == pre && GET_CHAR(0) <= '8' &&
	ft_ispair(GET_CHAR(-1)))
		;
	else if (GET_CHAR(0) >= '8')
	{
		if (GET_CHAR(-1) == 'f')
		{
			i = -1;
			while ((pre - 1 - ++i) >= 0 && GET_CHAR(-1 - i) == 'f')
				GET_CHAR(-1 - i) = '0';
			if ((pre - 1 - i) >= 0)
				GET_CHAR(-1 - i) += (GET_CHAR(-1 - i) == '9') ? 40 : 1;
			else
				*int_part_two = 1;
		}
		else
		{
			GET_CHAR(-1) += (GET_CHAR(-1) == '9') ? ('a' - '9') : 1;
			*ptr = ft_strdup(*ptr);
		}
	}
	GET_CHAR(0) = '\0';
}

static char		*build_zero(t_printf_part *part, int precision)
{
	char	*str;

	str = ft_strdup("p+0");
	if (precision > 0)
		str = ft_pad_string(str, '0', precision + 3, 1);
	if (precision > 0 || AND_F(HASH_MASK))
		str = (char*)ft_strjoinfree(".", str, 0, 1);
	str = (char*)ft_strjoinfree("0", str, 0, 1);
	return (str);
}

static char		*build_hex_sci(double nbr, t_printf_part *part, int type)
{
	char	*str;

	if (type <= 2)
		str = ft_build_normalized(nbr, part);
	else if (type >= 9)
		str = ft_strdup("nan");
	else if (type >= 7)
		str = ft_strdup("inf");
	else if (type >= 5)
		str = build_zero(part, PRE);
	else
		str = ft_build_unnormalized(nbr, part);
	if (type <= 6 && AND_F(ZERO_MASK) && !AND_F(MINU_MASK) &&
		WID > (int)(HEXFL_LEN_PLUS_PREFIX + 2))
		str = ft_pad_string(str, '0', WID - (HEXFL_HAS_PREFIX ? 1 : 0) - 2, 1);
	if (type <= 6)
		str = (char*)ft_strjoinfree("0x", str, 0, 1);
	if ((type % 2) == 0 && type != 10)
		str = (char*)ft_strjoinfree("-", str, 0, 1);
	else if (AND_F(PLUS_MASK) || AND_F(SPAC_MASK))
		str = (char*)ft_strjoinfree(AND_F(PLUS_MASK) ? "+" : " ", str, 0, 1);
	return (str);
}

int				build_nbr_13(t_printf_part *part, va_list *args)
{
	char	*str;
	double	nbr;

	WID = AND_I(WSTA_MASK) ? va_arg(*args, int) : WID;
	PRE = AND_I(PSTA_MASK) ? va_arg(*args, int) : PRE;
	nbr = va_arg(*args, double);
	str = build_hex_sci(nbr, part, ft_dbltype(nbr));
	if (WID > 0 && WID > (int)ft_strlen(str))
	{
		if (part->flags & MINU_MASK)
			str = ft_pad_string(str, ' ', -WID, 1);
		else
			str = ft_pad_string(str, ' ', WID, 1);
	}
	else if (WID < 0 && ABS(WID) > (int)ft_strlen(str))
		str = ft_pad_string(str, ' ', WID, 1);
	part->nbr_ptr = str;
	return (1);
}
