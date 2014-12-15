/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprntone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:12:32 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/24 08:25:38 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FMT1 ==ptr:%R.10*p
#define FMT2 ======next:%N.10*p
#define FMT3 ===content:%R.10*p
#define FMT4 ======size:%03u
#define FMT5 =====\n

#define STRI(ARG) #ARG
#define FMT STRI(FMT1)STRI(FMT2)STRI(FMT3)STRI(FMT4)STRI(FMT5)

void	ft_lstprntone(t_list *lst)
{
	ft_printf(FMT,
		(void*)lst, (void*)lst->next, lst->content, lst->content_size);
}
