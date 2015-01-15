/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 12:00:09 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 07:51:29 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

# include "ft_typedefs.h"

# define FTDEBUG_TABLELIB 0
# define FTDEBUG_METATABLIB 0

void	ft_tabadddebug1(void ***atab, void *new);
void	ft_tabadddebug2(t_tabdt *s, int tab_increment);
void	ft_tabadddebug3(void ***atab, t_tabdt *s);
void	ft_tabadddebug4(t_tabdt *s, void *new);
void	ft_metagetdebug1(char *tabname, const void *key);
void	ft_metagetdebug2(t_metat *m, const void *rkey);
void	ft_metagetdebug3(t_metat *m, t_metak k);
void	ft_metagetdebug5(t_metat *m, int i);

void	ft_printvar(char s[3][50], void *ptr, int line);

# define D(T, A) ft_printvar((char[][50]){#T, #A, __FILE__}, (T*)&A, __LINE__)
# define PEACE(A1, A2) A1 A2; (void)A2

int		qprintf(const char *format, ...);

#endif
