/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 08:30:06 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/18 11:02:05 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_tabsort(void **tab, int (*f)(const void *s1, const void *s2), int n)
{
	void	**cmp;
	void	*tmp;

	while (*tab)
	{
		cmp = tab + 1;
		while (*cmp)
		{
			if ((!n && f(*tab, *cmp) > 0) || (n && f(*tab, *cmp) <= 0))
			{
				tmp = *tab;
				*tab = *cmp;
				*cmp = tmp;
			}
			cmp++;
		}
		tab++;
	}
}
