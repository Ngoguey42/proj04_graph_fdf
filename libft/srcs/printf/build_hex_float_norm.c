/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hex_float_norm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:46:10 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 13:49:28 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_math.h"

#define WID part->width
#define PRE part->precision

/*
** 'ft_build_norm_strings' builds normalized exponant & decimal parts.
** 'ft_build_normalized' builds normalized integer part.
*/
/*
** 'ft_build_norm_strings'
** 1. Builds exponant in '*exp'.
** 2. Builds mantissa in '*mant', 4 bits at a time, reading the double's 6th
** 		 byte, shifting .manh by 4 on the left, each time.
** 2.1 [(eeee AAAA)  BBBB CCCC  DDDD EEEE] 'manh' 20 b and 'exp' 4 first b.
** 2.2 [(0000 AAAA)  BBBB CCCC  DDDD EEEE] setting exponant to 0.
** 2.3 [(0000 BBBB)  CCCC DDDD  EEEE 0000] reading and shifting (5 times).
** 2.4 [(0000 FFFF)  GGGG HHHH  IIII 0000] applying 'manl' 4 left bytes.
** 2.5 [(0000 GGGG)  HHHH IIII  0000 0000] reading and shifting (4 times).
** 2.6 [(0000 JJJJ)  KKKK LLLL  MMMM 0000] applying 'manl' 4 right bytes.
** 2.7 [(0000 KKKK)  LLLL MMMM  0000 0000] reading and shifting (4 times).
** 3. Removes trailing zeroes.
*/
/*
** 'ft_build_normalized'
** 1. Calls 'ft_build_norm_strings'
** 2. Rounds mantissa according to precision.
** 3. Joins mantissa's decimal part and the exponant in ret.
** 4. Adds the dot.
** 5. Adds the integer part (1 or 2).
** #define PRECISION_SET(REL) (AND_I(PSTA_MASK) && PRE REL)
*/

static void	ft_build_norm_strings(double nbr, char **mant, char **exp)
{
	int				i;
	t_dbl_extract	u;
	char			*ptr;

	u.d = nbr;
	i = u.s.exp - 1023;
	*exp = i < 0 ? ft_strjoinfree("p-", ft_lutoa_a(-i, 10), 0, 1) :
	ft_strjoinfree("p+", ft_lutoa_a(i, 10), 0, 1);
	*mant = (char*)malloc(sizeof(char) * 14);
	(*mant)[13] = '\0';
	i = 14;
	ptr = ((char*)(&u.d)) + 6;
	u.s.exp = 0;
	while (--i)
	{
		(*mant)[13 - i] = *ptr >= 10 ? *ptr + 'a' - 10 : *ptr + '0';
		if (i == 9)
			u.s.manh = u.s.manl >> 16;
		if (i == 5)
			u.s.manh = u.s.manl << 16 >> 16;
		u.s.manh = u.s.manh << 4;
	}
	while ((i = ft_strlen(*mant)) > 0 && (*mant)[i - 1] == '0')
		(*mant)[i - 1] = '\0';
}

char		*ft_build_normalized(double nbr, t_printf_part *part)
{
	char	*ret;
	char	*temp_str;
	char	first_decimal;
	int		integer_is2;

	ft_build_norm_strings(nbr, &temp_str, &ret);
	first_decimal = *temp_str;
	integer_is2 = 0;
	if ((AND_I(PSTA_MASK) && PRE >= 0) && PRE < (int)ft_strlen(temp_str))
		round_mantissa_b16(&temp_str, PRE, &integer_is2);
	else if (PRE > 0 && PRE > (int)ft_strlen(temp_str))
		temp_str = ft_pad_string(temp_str, '0', -PRE, 1);
	ret = ft_strjoinfree(temp_str, ret, 0, 1);
	if ((int)ft_strlen(temp_str) > 0 || AND_F(HASH_MASK))
		ret = ft_strjoinfree(".", ret, 0, 1);
	if ((first_decimal >= '8' && (int)ft_strlen(temp_str) == 0) || integer_is2)
		ret = ft_strjoinfree("2", ret, 0, 1);
	else
		ret = ft_strjoinfree("1", ret, 0, 1);
	free(temp_str);
	return (ret);
}
