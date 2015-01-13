/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evlxpr_convert_chain.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 14:39:10 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/31 14:52:55 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_eval_expr.h>

static char		evlxpr_operation(char c)
{
	if (c == '-')
		return (0);
	else if (c == '+')
		return (1);
	else if (c == '*')
		return (2);
	else if (c == '/')
		return (3);
	else if (c == '%')
		return (4);
	return (-1);
}

static char		evlxpr_operator(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else if (c == '*' || c == '/' || c == '%')
		return (2);
	else if (c == '(')
		return (3);
	else if (c == ')')
		return (4);
	return (0);
}

static int		evlxpr_get_val(char **ptr)
{
	int	total;
	int	sign;

	sign = 1;
	total = 0;
	if (evlxpr_operation(**ptr) == 0)
		sign = -1;
	if (evlxpr_operator(**ptr))
		(*ptr)++;
	while (**ptr == ' ')
		(*ptr)++;
	while (**ptr >= '0' && **ptr <= '9')
	{
		total = total * 10 + **ptr - '0';
		(*ptr)++;
	}
	(*ptr)--;
	return (sign * total);
}

int				evlxpr_convert_chain(char *str, t_evx *alst[1])
{
	while (*str != '\0')
	{
		if (*str == ' ')
			(void)1;
		else if (*str == '(' && evlxpr_lpback(alst, 0, 3, -1))
			return (1);
		else if (*str == ')' && evlxpr_lpback(alst, 0, 4, -1))
			return (1);
		else if (evlxpr_operator(*str) == 2 && evlxpr_lpback(alst, 0, 2,
				evlxpr_operation(*str)))
			return (1);
		else if (((!evlxpr_operator(*str)) || !evlxpr_llast(alst) ||
				evlxpr_llast(alst)->ref >= 0) && evlxpr_lpback(alst,
				evlxpr_get_val(&str), 0, -1))
			return (1);
		else if (evlxpr_lpback(alst, 0, 1, evlxpr_operation(*str)))
			return (1);
		str++;
	}
	return (0);
}
