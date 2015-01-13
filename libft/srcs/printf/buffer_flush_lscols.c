/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_flush_lscols.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 07:07:19 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/22 09:46:17 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** datas[0], outwid
** datas[1], num entry
** datas[2], total string raw len
** datas[3], total strings showed len
** datas[4], colsz w\ spacer
** datas[5], colsz w/ spacer
** datas[6], spacer width
** datas[7], max cols per line = floor(outwid / colsz w/ spacer)
** datas[8], final num lines
** datas[9], final num cols
** datas[10], num entries on right col
*/

/*
** ent[0], cur col.
** ent[1], cur line.
** ent[2], entry type. (1)isn't last (2)is last (3)empty
*/
static size_t	malloc_len(t_list *l, int *dts)
{
	size_t	tot;
	int		ent[3];
	t_list	*tmp;

	tot = 0;
	ent[0] = 1;
	ent[1] = 1;
	while (ent[1] <= dts[8])
	{
		if (ent[0] == dts[9])
			ent[2] = ent[1] > dts[10] ? 3 : 2;
		else
			ent[2] = (ent[0] == dts[9] - 1 && ent[1] > dts[10]) ? 2 : 1;
		tmp = ent[2] == 3 ? NULL : ft_lstat(l, (ent[0] - 1) * dts[8] + ent[1]);
		tot += ent[2] < 3 ? tmp->content_size - 1 : 0;
		tot += (ent[2] == 2) ? 1 : 0;
		if (ent[2] == 1)
			tot += dts[5] - ptf_showed_len((char*)tmp->content);
		if (++ent[0] > dts[9])
		{
			ent[1]++;
			ent[0] = 1;
		}
	}
	return ((tot + 1) * sizeof(char));
}

static void		fill_buffer(char *ret, t_list *l, int *dts)
{
	int		ent[3];
	t_list	*tmp;

	ent[0] = 1;
	ent[1] = 1;
	while (ent[1] <= dts[8])
	{
		if (ent[0] == dts[9])
			ent[2] = ent[1] > dts[10] ? 3 : 2;
		else
			ent[2] = (ent[0] == dts[9] - 1 && ent[1] > dts[10]) ? 2 : 1;
		tmp = ent[2] == 3 ? NULL : ft_lstat(l, (ent[0] - 1) * dts[8] + ent[1]);
		if (ent[2] < 3)
			ret = ft_memccpy2((void*)ret, tmp->content, tmp->content_size - 1);
		if (ent[2] == 1)
			ret = ft_memcset((void*)ret, (int)' ',
						dts[5] - ptf_showed_len((char*)tmp->content));
		if (ent[2] == 2)
			*ret++ = '\n';
		if (++ent[0] > dts[9] && ++ent[1])
			ent[0] = 1;
	}
	*ret = '\0';
}

int				ptf_fflush_lscols(char **ret, int wid)
{
	t_list	*lst;
	int		dts[11];

	if (!(lst = ptf_buffer("getbuf", 0, 0)))
		return (-1);
	ft_bzero((void*)dts, sizeof(int) * 7);
	ptf_lscols_getdatas(lst, wid, dts);
	if ((*ret = (char*)malloc(malloc_len(lst, dts))) == NULL)
		exit(0);
	fill_buffer(*ret, lst, dts);
	ptf_buffer("cleanbuf", 0, 0);
	return (0);
}
