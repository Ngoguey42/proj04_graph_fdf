/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 11:46:58 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/01 12:02:42 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_voidstrcmp(const void *s1, const void *s2)
{
	return (ft_strcmp((const char*)s1, (const char*)s2));
}

int		ft_voiduintcmp(const void *s1, const void *s2)
{
	return (*(unsigned int*)s1 - *(unsigned int*)s2);
}

int		ft_voidintcmp(const void *s1, const void *s2)
{
	return (*(int*)s1 - *(int*)s2);
}
