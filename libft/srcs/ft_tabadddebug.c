/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadddebug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 11:47:54 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 11:10:47 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_debug.h>

void	ft_tabadddebug1(void ***atab, void *new)
{
	if (!FTDEBUG_TABLELIB)
		return ;
	ft_printf("%Jsin::und:atab:eou:{%Hp} ", "TAB ADD     ", atab);
	ft_printf("req::und:*atab:eou: for::und:new:eou:{%p}\n", new);
}

void	ft_tabadddebug2(t_tabdt *s, int tab_increment)
{
	if (!FTDEBUG_TABLELIB)
		return ;
	ft_printf("%Js%Is", "TAB ADD     ", "  ");
	ft_printf(":und:s:eou: requires :gre:realloc:eoc: ");
	ft_printf("from %u to %u\n", s->size, s->size + tab_increment);
}

void	ft_tabadddebug3(void ***atab, t_tabdt *s)
{
	if (!FTDEBUG_TABLELIB)
		return ;
	ft_printf("%Js%Is", "TAB ADD     ", "  ");
	ft_printf("::und:*atab:eou: from {%Ip} ", *atab);
	ft_printf("to {%Ip}\n", s->ptr);
}

void	ft_tabadddebug4(t_tabdt *s, void *new)
{
	if (!FTDEBUG_TABLELIB)
		return ;
	ft_printf("%Js::und:s->ptr[%u]:eou: =", "TAB ADD     ", s->size - 1);
	ft_printf("{%p} ; new = {%p}\n", s->ptr[s->size - 1], new);
}
