/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_acav_segments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 07:40:07 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 07:44:37 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fdf.h>

static void	store_segment(int c, int l, int lineinfo[3], t_fdf *fdf)
{
	t_fdfobj		obj;
	const int		pnti = (l - 1) * lineinfo[2] + (c - 1);

	ft_bzero(&obj, sizeof(t_fdfobj));
	obj.type = 1;
	obj.apointi = (int)pnti;
	if (c != 1)
	{
		obj.bpointi = obj.apointi - 1;
		obj.gr = fdf_build_grad(*fdf, (*fdf->pntm)[obj.apointi]->coof.z,
							(*fdf->pntm)[obj.bpointi]->coof.z);
		if (ft_tabaddm((void***)fdf->objm, &obj, sizeof(t_fdfobj)))
			exit(0);
	}
	if (l != 1)
	{
		obj.bpointi = obj.apointi - lineinfo[2];
		obj.gr = fdf_build_grad(*fdf, (*fdf->pntm)[obj.apointi]->coof.z,
								(*fdf->pntm)[obj.bpointi]->coof.z);
		if (ft_tabaddm((void***)fdf->objm, &obj, sizeof(t_fdfobj)))
			exit(0);
	}
}

void		store_segments(int lineinfo[3], t_fdf *fdf)
{
	int			l;
	int			c;

	l = 0;
	while (++l <= lineinfo[1])
	{
		c = 0;
		while (++c <= lineinfo[2])
			store_segment(c, l, lineinfo, fdf);
	}
}
