/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:34:30 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/17 13:36:04 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** 'ft_strcat' concatenates two strings.
*/

char	*ft_strcatfree(char *s1, char *s2)
{
	ft_strcpy(s1 + ft_strlen(s1), s2);
	free(s2);
	return (s1);
}
