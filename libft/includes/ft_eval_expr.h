/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_expr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 11:39:32 by ngoguey           #+#    #+#             */
/*   Updated: 2014/07/20 11:42:21 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVAL_EXPR_H
# define FT_EVAL_EXPR_H

# include <stdlib.h>

typedef struct				s_evlxpr_cell
{
	struct s_evlxpr_cell	*next;
	int						value;
	char					oper;
	char					ref;
}							t_evlxpr_cell;

t_evlxpr_cell				**evlxpr_convert_chain(char *str);
int							evlxpr_shallow();
t_evlxpr_cell				*evlxpr_llast(t_evlxpr_cell **beggining);
int							evlxpr_calculate(int n1, int n2, char ref);
void						evlxpr_lpback(t_evlxpr_cell **beggining, int value,
							char oper, char ref);

#endif
