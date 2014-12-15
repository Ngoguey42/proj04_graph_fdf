/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_flushcols_concat.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:43:10 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 13:43:36 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define GET(ARG) ptf_buffer_infos(ARG, 0)

size_t			ptf_calc_real_content_size(t_list *lst)
{
	return (lst->content_size - 1);
}

static size_t	calc_total_malloc_len(t_list *l, int *cols, int ncol)
{
	size_t	total;
	int		i;
	int		spacer_width;

	total = 0;
	i = 0;
	spacer_width = GET("getspwidth");
	while (l)
	{
		if (i != ncol - 1 && l->next != NULL)
			total += cols[i] - ptf_calc_real_content_size(l) +
			l->content_size - 1 + spacer_width;
		else
			total += l->content_size + (l->next ? 1 : 0) - 1;
		i = (i + 1) % ncol;
		l = l->next;
	}
	return (total + 1);
}

static int		cat_parts(char *s, t_list *l, int *cols, int ncol)
{
	int			i;
	int			j;
	const int	d[3] = {GET("getspwidth"), GET("getspacer"), DEFAULT_FILLER};

	i = 0;
	while (l)
	{
		ft_memcpy(s, l->content, (j = (l->content_size - 1)));
		s += j;
		if (i != ncol - 1 && l->next != NULL)
		{
			ft_memset(s, d[2], (j = cols[i] - ptf_calc_real_content_size(l)));
			s += j;
			ft_memset(s, d[1], d[0]);
			s += d[0];
		}
		else if (l->next != NULL)
			*s++ = '\n';
		else
			*s++ = '\0';
		i = (i + 1) % ncol;
		l = l->next;
	}
	return (0);
}

int				ptf_cols_concat_string(char **ret, t_list *l, int *cols, int n)
{
	int	size;

	size = calc_total_malloc_len(l, cols, n);
	*ret = (char*)malloc(sizeof(char) * size);
	if (!*ret)
		return (-1);
	cat_parts(*ret, l, cols, n);
	return (size);
}
