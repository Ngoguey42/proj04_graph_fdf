/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hex_float_unnorm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:50:01 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 13:51:29 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define WID part->width
#define PRE part->precision

/*
** 'ft_get_unnorm_exp' looks for the first bit from the left.
** 'ft_build_unnorm_strings' builds unnormalized exponant & decimal parts.
** 'ft_build_normalized' builds unnormalized integer part.
*/
/*
** 'ft_build_unnorm_strings'
** Dirty way i found diging into doubles representations.
** Need rebuild it from scratch, without ceil and log. Just like i did
** 		with 'ft_build_NORM_strings'.
*/

static int	ft_get_unnorm_exp(t_ui64 nbr)
{
	int				i;
	unsigned char	*ptr;

	ptr = ((unsigned char*)&nbr) + 6;
	i = 51;
	while (i > 0)
	{
		if (*ptr & 0b00001000)
			return (i);
		i--;
		nbr = nbr << 1;
	}
	return (0);
}

static void	ft_build_unnorm_strings(double nbr, char **mant, char **exp)
{
	t_i64	i;
	t_i64	j;
	t_ui64	temp_nbr;

	temp_nbr = ft_getbitarray((t_byte*)&(nbr), 0, 51);
	j = ft_get_unnorm_exp(temp_nbr);
	i = j - 1023 - 51;
	*exp = (char*)ft_strjoinfree("p-", ft_lutoa_a(-i, 10), 0, 1);
	((t_byte*)&temp_nbr)[j / 8] ^= 1 << (j % 8);
	j = ft_lpowi(2, j);
	i = (t_i64)ft_ceil(ft_log16((double)j));
	*mant = ft_lutoa_a(temp_nbr * (ft_lpowi(16, (int)i) / j), 16);
	if (i > (t_i64)ft_strlen(*mant))
		*mant = ft_pad_string(*mant, '0', i, 1);
}

char		*ft_build_unnormalized(double nbr, t_printf_part *part)
{
	char	*ret;
	char	*temp_str;
	char	first_decimal;
	int		i;

	ft_build_unnorm_strings(nbr, &temp_str, &ret);
	first_decimal = *temp_str;
	while (PRE < 0 && temp_str[i = ((int)ft_strlen(temp_str) - 1)] == '0')
		temp_str[i] = '\0';
	i = 0;
	if ((AND_I(PSTA_MASK) && PRE >= 0) && PRE < (int)ft_strlen(temp_str))
		round_mantissa_b16(&temp_str, PRE, &i);
	else if (PRE > 0 && PRE > (int)ft_strlen(temp_str))
		temp_str = ft_pad_string(temp_str, '0', -PRE, 1);
	while (!AND_I(PSTA_MASK) && ft_strlen(temp_str) > 0 &&
		temp_str[(int)ft_strlen(temp_str) - 1] == '0')
		temp_str[(int)ft_strlen(temp_str) - 1] = '\0';
	ret = (char*)ft_strjoinfree(temp_str, ret, 0, 1);
	if (!((int)ft_strlen(temp_str) == 0 && !AND_F(HASH_MASK)))
		ret = (char*)ft_strjoinfree(".", ret, 0, 1);
	if ((first_decimal >= '8' && (int)ft_strlen(temp_str) == 0) || i)
		ret = ft_strjoinfree("2", ret, 0, 1);
	else
		ret = ft_strjoinfree("1", ret, 0, 1);
	return (free(temp_str), ret);
}
