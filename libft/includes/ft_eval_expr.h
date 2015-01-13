/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_expr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 11:39:32 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/31 14:56:06 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVAL_EXPR_H
# define FT_EVAL_EXPR_H

# include "libft.h"

typedef struct		s_evx
{
	struct s_evx	*next;
	int				value;
	char			oper;
	char			ref;
}					t_evx;

int					evlxpr_convert_chain(char *str, t_evx *alst[1]);
int					evlxpr_shallow();
t_evx				*evlxpr_llast(t_evx *alst[1]);
int					evlxpr_calculate(int n1, int n2, char ref);
int					evlxpr_lpback(t_evx *alts[1], int v, char op, char ref);

#endif
