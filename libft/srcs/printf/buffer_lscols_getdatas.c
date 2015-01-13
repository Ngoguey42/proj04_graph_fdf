/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_lscols_getdatas.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 08:56:38 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/22 09:38:19 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_math.h"

size_t			ptf_showed_len(char *str)
{
	size_t	tot;

	tot = 0;
	while (*str != '\0')
	{
		if (str[0] == '\033' && str[1] == '[' && ft_isdigit(str[2]) &&
			((str[3] == 'm') || ((ft_isdigit(str[3]) && str[4] == 'm'))))
			str += (str[3] == 'm') ? 3 : 4;
		else
			tot++;
		str++;
	}
	return (tot);
}

static void		parse_lst(t_list *lst, int *datas)
{
	size_t	tmp;

	while (lst)
	{
		datas[1]++;
		datas[2] += lst->content_size - 1;
		tmp = ptf_showed_len((char*)lst->content);
		datas[3] += tmp;
		datas[4] = MAX(datas[4], (int)tmp);
		lst = lst->next;
	}
}

static int		does_entries_fits_in(int *datas)
{
	int	nlines;

	nlines = ft_idiv_ceil(datas[1], datas[9]);
	if (nlines > datas[8])
		return (0);
	return (1);
}

void			ptf_lscols_getdatas(t_list *lst, int wid, int *datas)
{
	datas[0] = wid;
	parse_lst(lst, datas);
	datas[6] = ptf_buffer_infos("getspwidth", 0);
	datas[5] = datas[4] + datas[6];
	datas[7] = ft_idiv_floor(datas[0], datas[5]);
	if (datas[7] <= 1 || datas[5] == 0)
	{
		datas[8] = datas[1];
		datas[7] = 1;
		datas[9] = 1;
		datas[10] = datas[1];
		return ;
	}
	datas[8] = ft_idiv_ceil(datas[1], datas[7]);
	datas[9] = datas[7] - 1;
	while (datas[9] > 1)
	{
		if (does_entries_fits_in(datas))
			datas[9]--;
		else
			break ;
	}
	datas[9]++;
	datas[10] = datas[8] - (datas[9] * datas[8] - datas[1]);
}
