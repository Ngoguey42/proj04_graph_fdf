/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_chars_and_strings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:33:52 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 12:36:49 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_math.h"

/*
** 'build_nbr_15' %c.
** 'build_nbr_16' %s.
** 'build_nbr_19' %%.
*/
/*
** %c
** if (c == '\0')
** (1) convert '\0' to '\1' and remember it in unused int precision;
** (2) deal with Width;
** (3) save strlen;
** (4) convert '\1' back to '\0'
*/

int		build_nbr_15(t_printf_part *part, va_list *args)
{
	int		precision;
	char	*str;
	char	c;

	part->width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	precision = AND_I(PSTA_MASK) ? va_arg(*args, int) : part->precision;
	c = (char)va_arg(*args, int);
	precision = c == 0 ? 1 : 0;
	if (!(str = ft_strnew(1)))
		return (0);
	str[0] = precision ? 1 : c;
	if (part->width > 1)
	{
		if (AND_F(MINU_MASK))
			str = ft_pad_string(str, ' ', -part->width, 1);
		else
			str = ft_pad_string(str, PAD_CHAR, part->width, 1);
	}
	else if (part->width < -1)
		str = ft_pad_string(str, ' ', part->width, 1);
	part->nbr_ptr = str;
	part->nbr_size = ft_strlen(str);
	if (precision)
		part->nbr_ptr[ft_strcharlen(str, '\1')] = '\0';
	return (1);
}

int		build_nbr_16(t_printf_part *part, va_list *args)
{
	int		width;
	int		precision;
	char	*str;

	width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	precision = AND_I(PSTA_MASK) ? va_arg(*args, int) : part->precision;
	str = (char*)va_arg(*args, char*);
	str = (str == NULL) ? ft_strdup("(null)") : ft_strdup(str);
	if (AND_I(PNUM_MASK) && precision >= 0 && precision < (int)ft_strlen(str))
		str[precision] = '\0';
	if (width > 0 && width > (int)ft_strlen(str))
	{
		if (AND_F(MINU_MASK))
			str = ft_pad_string(str, ' ', -width, 1);
		else
			str = ft_pad_string(str, PAD_CHAR, width, 1);
	}
	else if (width < 0 && ABS(width) > (int)ft_strlen(str))
		str = ft_pad_string(str, ' ', width, 1);
	part->nbr_ptr = str;
	return (1);
}

int		build_nbr_19(t_printf_part *part, va_list *args)
{
	int		width;
	int		precision;

	width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	precision = AND_I(PSTA_MASK) ? va_arg(*args, int) : part->precision;
	(void)precision;
	if (width > 1)
	{
		if (AND_F(MINU_MASK))
			part->nbr_ptr = ft_pad_string("%", ' ', -width, 0);
		else
			part->nbr_ptr = ft_pad_string("%", PAD_CHAR, width, 0);
	}
	else if (width < -1)
		part->nbr_ptr = ft_pad_string("%", ' ', width, 0);
	else
		part->nbr_ptr = (char*)ft_strdup("%");
	return (1);
}
