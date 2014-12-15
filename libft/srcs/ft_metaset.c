/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metaset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 10:02:05 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/24 08:37:52 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_metaset(char *tabname, void *(*f)(const void *k),
						int (*c)(const void *s1, const void *s2), size_t keysz)
{
	t_metat *m;

	if (!(m = ft_metacc(tabname)))
		return (1);
	ft_strcpy(m->tabname, tabname);
	m->keysz = keysz;
	m->initkey = f;
	m->cmp = c;
	return (0);
}
