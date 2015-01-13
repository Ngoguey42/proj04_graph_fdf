/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metaget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 08:51:27 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 10:44:04 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_debug.h>

static int	store_new_key(t_metat *m, const void *rkey, size_t keysz)
{
	t_metak	k;

	if (!(k.key = malloc(keysz)))
	{
		ft_putendl_fd("Metatab malloc failed", 2);
		return (1);
	}
	ft_memcpy(k.key, rkey, keysz);
	k.value = (m->initkey)(k.key);
	ft_metagetdebug3(m, k);
	if (ft_tabaddm((void***)m->akey, (void*)&k, sizeof(t_metak)))
	{
		ft_putendl_fd("Tab storing failed", 2);
		return (1);
	}
	return (0);
}

static int	get_key_index(t_metat *m, const void *rkey, size_t keysz)
{
	int		i;
	t_metak	**keys;

	ft_metagetdebug2(m, rkey);
	if (!*m->akey)
		if (store_new_key(m, rkey, keysz))
			return (-1);
	keys = *m->akey;
	i = 0;
	while (keys[i])
	{
		if ((m->cmp)(rkey, keys[i]->key) == 0)
			return (i);
		i++;
	}
	if (store_new_key(m, rkey, keysz))
		return (-1);
	return (i);
}

void		*ft_metaget(char *tabname, const void *key)
{
	t_metat	*m;
	int		i;

	ft_metagetdebug1(tabname, key);
	if (!(m = ft_metacc(tabname)))
		return (NULL);
	if (!m->initkey)
		return (NULL);
	i = get_key_index(m, key, m->keysz);
	if (i < 0)
		return (NULL);
	ft_metagetdebug5(m, i);
	return ((*m->akey)[i]->value);
}
