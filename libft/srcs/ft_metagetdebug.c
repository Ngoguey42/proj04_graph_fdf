/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metaget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 08:51:27 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 11:07:14 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_debug.h>

void	ft_metagetdebug1(char *tabname, const void *key)
{
	if (!FTDEBUG_METATABLIB)
		return ;
	ft_printf("\n%MsREQU :und:\"%Hs\":eou: ", "META GET    ", tabname);
	ft_printf("key {%p}\n", key);
}

void	ft_metagetdebug2(t_metat *m, const void *rkey)
{
	if (!FTDEBUG_METATABLIB)
		return ;
	ft_printf("%MsLOOK in t_metat{%Hp} ", "META GET    ", m);
	ft_printf(":und:*akey:eou:{%p} key{%p}\n", *m->akey, rkey);
}

void	ft_metagetdebug3(t_metat *m, t_metak k)
{
	if (!FTDEBUG_METATABLIB)
		return ;
	ft_printf("%Ms%IsSTOR in {%p} t_metak ", "META GET    ", "  ", m->akey);
	ft_printf("key(%u) val\"% $.6r\"\n", *(int*)k.key, (char*)k.value);
}

void	ft_metagetdebug5(t_metat *m, int i)
{
	if (!FTDEBUG_METATABLIB)
		return ;
	ft_printf("%MsRETU (*t_metat->akey)[%u]", "META GET    ", i);
	ft_printf("->value = {%p}\"% $.6r\"\n", (*m->akey)[i]->value,
		(*m->akey)[i]->value);
}
