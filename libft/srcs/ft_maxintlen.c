/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:41:46 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 15:40:38 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_maxintlen' returns the maximum length of an int for a
** given 'sizeof(int)' and 'base'.
** Length is rounded up for uncommon bases.
*/

const int		g_base2_sizes[4] = {16, 32, 0, 64};
const int		g_base8_sizes[4] = {6, 12, 0, 22};
const int		g_base10_sizes[4] = {6, 11, 0, 20};
const int		g_base16_sizes[4] = {5, 9, 0, 17};
const int		g_base36_sizes[4] = {4, 7, 0, 14};

int		ft_maxintlen(size_t sizeofint, int base)
{
	if (base > 36 || base < 2 || sizeofint < 2 || sizeofint > 8)
		return (0);
	if (base < 8)
		return (g_base2_sizes[sizeofint / 2 - 1]);
	if (base < 10)
		return (g_base8_sizes[sizeofint / 2 - 1]);
	if (base < 16)
		return (g_base10_sizes[sizeofint / 2 - 1]);
	if (base < 36)
		return (g_base16_sizes[sizeofint / 2 - 1]);
	return (g_base36_sizes[sizeofint / 2 - 1]);
}
