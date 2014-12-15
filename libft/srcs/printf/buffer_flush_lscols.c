/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_flush_lscols.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 07:07:19 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/09 11:33:55 by ngoguey          ###   ########.fr       */
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
static size_t	malloc_len(t_list *lst, int *datas)
{
	size_t	tot;
	int		ent[3];
	t_list	*tmp;

	tot = 0;
	ent[0] = 1;
	ent[1] = 1;
	while (ent[1] <= datas[8])
	{
		if (ent[0] == datas[9])
			ent[2] = ent[1] > datas[10] ? 3 : 2;
		else
			ent[2] = (ent[0] == datas[9] - 1 && ent[1] > datas[10]) ? 2 : 1;
		tmp = ent[2] == 3 ? NULL : ft_lstat(lst, (ent[0] - 1) * datas[8] + ent[1]);
		tot += ent[2] < 3 ? tmp->content_size - 1 : 0;
		tot += (ent[2] == 2) ? 1 : 0;
		if (ent[2] == 1)
			tot += datas[5] - ptf_showed_len((char*)tmp->content);
/* 		qprintf("for col(%d) lin(%d) ", ent[0], ent[1]); */
/* 		qprintf("t(%d) ", ent[2]); */
/* 		if (ent[2] < 3) */
/* 			qprintf("\"%13s\" ", (char*)tmp->content); */
/* 		else */
/* 			qprintf("%*s ", 15, ""); */
/* 		qprintf("tot(%d)", tot); */
/* 		qprintf("\n"); */
		if (++ent[0] > datas[9])
		{
			ent[1]++;
			ent[0] = 1;
		}
	}
	return ((tot + 1) * sizeof(char));
}

static void		fill_buffer(char *ret, t_list *lst, int *datas)
{
	int		ent[3];
	t_list	*tmp;

	ent[0] = 1;
	ent[1] = 1;
	while (ent[1] <= datas[8])
	{
		if (ent[0] == datas[9])
			ent[2] = ent[1] > datas[10] ? 3 : 2;
		else
			ent[2] = (ent[0] == datas[9] - 1 && ent[1] > datas[10]) ? 2 : 1;
		tmp = ent[2] == 3 ? NULL : ft_lstat(lst, (ent[0] - 1) * datas[8] + ent[1]);
		if (ent[2] < 3)
			ret = ft_memccpy2((void*)ret, tmp->content, tmp->content_size - 1);
/* 		tot += ent[2] < 3 ? tmp->content_size - 1 : 0; */
		if (ent[2] == 1)
			ret = ft_memcset((void*)ret, (int)' ',
						datas[5] - ptf_showed_len((char*)tmp->content));
/* 			tot += datas[5] - ptf_showed_len((char*)tmp->content); */
		if (ent[2] == 2)
			*ret++ = '\n';
/* 		tot += (ent[2] == 2) ? 1 : 0; */
/* 		qprintf("for col(%d) lin(%d) ", ent[0], ent[1]); */
/* 		qprintf("t(%d) ", ent[2]); */
/* 		if (ent[2] < 3) */
/* 			qprintf("\"%13s\" ", (char*)tmp->content); */
/* 		else */
/* 			qprintf("%*s ", 15, ""); */
/* 		qprintf("\n"); */
		if (++ent[0] > datas[9])
		{
			ent[1]++;
			ent[0] = 1;
		}
	}
	*ret = '\0';
}


int				ptf_fflush_lscols(char **ret, int wid)
{
	t_list	*lst;
	int		datas[11];

	if (!(lst = ptf_buffer("getbuf", 0, 0)))
		return (-1);
	ft_bzero((void*)datas, sizeof(int) * 7);
	ptf_lscols_getdatas(lst, wid, datas);
/* 	qprintf("outwid[%2d] num entry[%2d]\n", datas[0], datas[1]); */
/* 	qprintf("rawlen[%3d] len[%3d]\n", datas[2], datas[3]); */
/* 	qprintf("colszraw[%3d] colsz[%3d]\n", datas[4], datas[5]); */
/* 	qprintf("maxcols per line[%3d]\n", datas[7]); */
/* 	qprintf("lines[%2d] cols[%2d]\n", datas[8], datas[9]); */
/* 	qprintf("num ent on last col[%3d]\n", datas[10]);  */
	if ((*ret = (char*)malloc(malloc_len(lst, datas))) == NULL)
		exit(0); //exit
/* 	qprintf("len %d\n", malloc_len(lst, datas)); */
	(void)ret;
	fill_buffer(*ret, lst, datas);
	ptf_buffer("cleanbuf", 0, 0);
	return (0);
}
