/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_chain.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 12:14:06 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 18:57:55 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval_expr.h"

char	*g_str;

char			evlxpr_operation(void)
{
	if (*g_str == '-')
		return (0);
	else if (*g_str == '+')
		return (1);
	else if (*g_str == '*')
		return (2);
	else if (*g_str == '/')
		return (3);
	else if (*g_str == '%')
		return (4);
	return (-1);
}

char			evlxpr_operator(void)
{
	if (*g_str == '-' || *g_str == '+')
		return (1);
	else if (*g_str == '*' || *g_str == '/' || *g_str == '%')
		return (2);
	else if (*g_str == '(')
		return (3);
	else if (*g_str == ')')
		return (4);
	return (0);
}

int				evlxpr_get_val(void)
{
	int total;
	int sign;

	sign = 1;
	total = 0;
	if (evlxpr_operation() == 0)
		sign = -1;
	if (evlxpr_operator())
		g_str++;
	while (*g_str == ' ')
		g_str++;
	while (*g_str >= '0' && *g_str <= '9')
	{
		total = total * 10 + *g_str - '0';
		g_str++;
	}
	g_str--;
	return (sign * total);
}

t_evlxpr_cell	**evlxpr_convert_chain(char *str)
{
	t_evlxpr_cell	**beginning;

	beginning = malloc(sizeof(t_evlxpr_cell*));
	*beginning = NULL;
	g_str = str;
	while (*g_str != '\0')
	{
		if (*g_str == ' ')
			;
		else if (*g_str == '(')
			evlxpr_lpback(beginning, 0, 3, -1);
		else if (*g_str == ')')
			evlxpr_lpback(beginning, 0, 4, -1);
		else if (evlxpr_operator() == 2)
			evlxpr_lpback(beginning, 0, 2, evlxpr_operation());
		else if (!evlxpr_operator() || !evlxpr_llast(beginning) ||
					evlxpr_llast(beginning)->ref >= 0)
			evlxpr_lpback(beginning, evlxpr_get_val(), 0, -1);
		else
			evlxpr_lpback(beginning, 0, 1, evlxpr_operation());
		g_str++;
	}
	return (beginning);
}
