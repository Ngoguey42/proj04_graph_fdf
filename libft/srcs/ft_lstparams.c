/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstparams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:58:33 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 16:32:28 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	assign_vals(t_list **v1, t_list **v2, int ac, char **av)
{
	*v1 = ft_lstnew((void*)av[ac], av[ac] ? ft_strlen(av[ac] + 1) : 0);
	if (v2)
		*v2 = *v1;
	else
		*v1 = (*v1)->next;
}

t_list		*ft_lstparams(int ac, char **av)
{
	t_list	*alst;
	t_list	*cur;

	if (ac < 1 || !av)
		return (NULL);
	alst = NULL;
	while (--ac >= 0)
	{
		if (alst)
			assign_vals(&(cur->next), NULL, ac, av);
		else
			assign_vals(&cur, &alst, ac, av);
		if (!cur)
		{
			ft_lstdel(&alst, NULL);
			return (NULL);
		}
	}
	return (alst);
}
