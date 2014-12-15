/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/20 11:40:05 by ngoguey           #+#    #+#             */
/*   Updated: 2014/07/20 11:43:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	evlxpr_calculate(int n1, int n2, char ref)
{
	if (ref == 0)
		return (n1 - n2);
	else if (ref == 1)
		return (n1 + n2);
	else if (ref == 2)
		return (n1 * n2);
	else if (ref == 3)
		return (n1 / n2);
	return (n1 % n2);
}
