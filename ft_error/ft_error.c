/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 08:52:13 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/09 06:21:36 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libft.h>

/*
** Version 1 of ft_error.
*/

/*
** 'ft_error_illegal_op' functions index:
** 0 for default.
** 1 for ls.
** 'ft_error_illegal_op' modes:
** 0x1 flags
** 0x2 files
*/

const char	g_names[][6] = {"", "ft_ls"};
const char	g_flags[][20] = {"", "ABCFGRabdfghlnortu1"};
const int	g_modes[] = {0x0, 0x03};

void	ft_error_illegal_op(int fi, char o, char *ex, void (*f)(void *p))
{
	ft_dprintf(2, "%s: illegal option -- %c", ex, o ? o : '-');
	if (g_modes[fi] & 0x03)
	{
		ft_dprintf(2, "\nusage: %s", g_names[fi]);
		if (g_modes[fi] & 0x01)
			ft_dprintf(2, " [-%s]", g_flags[fi]);
		if (g_modes[fi] & 0x02)
			ft_dprintf(2, " [file ...]");
	}
	ft_putchar_fd('\n', 2);
	if (f != NULL)
		f(NULL);
	exit(EXIT_FAILURE);
}

void	ft_error_malloc(void)
{
	ft_putendl_fd("Malloc failed, exiting program.", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_unknown(void)
{
	ft_putendl_fd("Unknown error, exiting program.", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_fistrerrno(int fi, char *s)
{
	ft_dprintf(2, "%s: ", g_names[fi]);
	if (s)
		ft_dprintf(2, "%s: ", s);
	ft_dprintf(2, "%s\n", strerror(errno));
}

void	ft_error_fistrno(int fi, char *s, int no)
{
	ft_dprintf(2, "%s: ", g_names[fi]);
	if (s)
		ft_dprintf(2, "%s: ", s);
	ft_dprintf(2, "%s\n", strerror(no));
}
