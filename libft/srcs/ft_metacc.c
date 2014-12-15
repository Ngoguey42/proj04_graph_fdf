/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metacc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 08:52:24 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 11:06:27 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <ft_debug.h>

#define MAX_METAT  10

void		ft_metadebug1(char *requested)
{
	if (!FTDEBUG_METATABLIB)
		return ;
	ft_printf("%MsREQU tab name{%p} \"% $.6r\"\n", "META CC ",
		requested, requested);
}

void		ft_metadebug2(t_metat metas[], int i)
{
	if (!FTDEBUG_METATABLIB)
		return ;
	ft_printf("%MsRETU t_metat[%Hd]={%p} ", "META CC ", i, metas + i);
	ft_printf("akey{%p} keysz(%u)\n", metas[i].akey, metas[i].keysz);
}

static int	request_index(t_metat metas[MAX_METAT], char *requested)
{
	static int	i = 0;
	int			j;

	if (ft_strequ(metas[i].tabname, requested))
		return (i);
	j = -1;
	i = 0;
	while (i < MAX_METAT)
	{
		if (ft_strequ(metas[i].tabname, requested))
			return (i);
		if (j < 0 && !metas[i].cmp)
			j = i;
		i++;
	}
	if (j >= 0)
		return (j);
	ft_putendl_fd("Metatables command center overflow", 2);
	return (-1);
}

t_metat		*ft_metacc(char *requested)
{
	static t_metat	metas[MAX_METAT];
	static int		initialized = 0;
	int				i;

	ft_metadebug1(requested);
	if (!initialized)
	{
		ft_bzero((void*)metas, MAX_METAT * sizeof(t_metat));
		initialized++;
	}
	i = request_index(metas, requested);
	if (i < 0)
		return (NULL);
	ft_metadebug2(metas, i);
	return (metas + i);
}
