/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 11:21:43 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 13:02:31 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ptf_free_list(t_printf_part **beginning)
{
	t_printf_part	*cur;
	t_printf_part	*tmp;

	cur = *beginning;
	while (cur)
	{
		tmp = cur->next;
		if (cur->specifier)
			free(cur->nbr_ptr);
		free(cur);
		cur = tmp;
	}
}
