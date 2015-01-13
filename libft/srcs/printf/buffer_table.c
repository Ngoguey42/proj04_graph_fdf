/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 11:36:56 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/01 11:43:07 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_math.h"

/*
** long table format for ft_printf buffer: format[i][j]
** #i columns.
** #j infos.
** j == 0 padding left
** j == 1 padding right
** j == 2 align text left.
** j == 3 empty
** j == 4 empty
** j[0] == -1, end
*/

char			*tabbuffer_settable(char *arg1)
{
	static char	*datas;

	if (arg1 == NULL)
		return (datas);
	else
		datas = arg1;
	return (datas);
}

static int		*calc_cols_sizes(t_list *buf, char *datas)
{
	size_t	num;
	int		*colsizes;

	num = 0;
	while (datas[num] >= 0)
		num++;
	num = num / 5 + 1;
	if (!(colsizes = (int*)ft_memalloc(sizeof(int) * num)))
		return (NULL);
	colsizes[num - 1] = -1;
	num = 0;
	while (buf)
	{
		num = colsizes[num] == -1 ? 0 : num;
		colsizes[num] = MAX(colsizes[num], (int)buf->content_size - 1);
		num++;
		buf = buf->next;
	}
	return (colsizes);
}

static size_t	calc_malloc(t_list *buf, char *datas, int *colsizes)
{
	int		i;
	size_t	t;

	i = 0;
	t = 0;
	while (buf)
	{
		i = (colsizes[i] == -1) ? 0 : i;
		if (colsizes[i + 1] == -1 && colsizes[i] >= 1)
		{
			if (!datas[i * 5 + 2])
				t += datas[i * 5] + colsizes[i];
			else
				t += datas[i * 5] + buf->content_size - 1;
		}
		else if (colsizes[i] >= 1)
			t += colsizes[i] + datas[i * 5] + datas[i * 5 + 1];
		buf = buf->next;
		i++;
	}
	return (t + 1);
}

static void		concat_parts(char *str, t_list *buf, char *dat, int *szs)
{
	int			i;
	const char	s = (const char)ptf_buffer_infos("getspacer", 0);

	i = -1;
	while (buf)
	{
		buf = (i == -1) ? buf : buf->next;
		i = (szs[++i] == -1) ? 0 : i;
		if (!buf || szs[i] < 1)
			continue ;
		str = ft_memcset(str, (int)s, dat[i * 5]);
		if (!dat[i * 5 + 2])
			str = ft_memcset(str, (int)s, szs[i] - (buf->content_size - 1));
		str = ft_memccpy2(str, buf->content, buf->content_size - 1);
		if (szs[i + 1] == -1)
			continue ;
		if (dat[i * 5 + 2])
			str = ft_memcset(str, (int)s, szs[i] - (buf->content_size - 1));
		str = ft_memcset(str, (int)s, dat[i * 5 + 1]);
	}
	*str = '\0';
}

int				ptf_fflush_table_buffer(char **ret)
{
	t_list	*buf;
	char	*datas;
	int		*colsizes;

	if (!(buf = ptf_buffer("getbuf", 0, NULL)))
		return (-1);
	datas = tabbuffer_settable(NULL);
	if (!(colsizes = calc_cols_sizes(buf, datas)))
		return (-1);
	*ret = (char*)malloc(sizeof(char) * calc_malloc(buf, datas, colsizes));
	if (!*ret)
		return (-1);
	concat_parts(*ret, buf, datas, colsizes);
	free(colsizes);
	ptf_buffer("cleanbuf", 0, 0);
	return (0);
}
