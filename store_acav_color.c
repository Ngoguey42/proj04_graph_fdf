/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_acav_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 10:02:03 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/03 12:02:06 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Valid Color Field, (default colors if invalid):
**		Field's valid characters are " ;0123456789", and begin with a digit. 
**		Field must contain 1, 2 or 3 color(s).
**		Each color must have 3 consecutive numbers, for r, g, b values.
**		Numbers must be separated with a single space.
**		A number must <= 255.
**		Colors must be separated with a single semicolon.
*/

/*
** If 1 color. Lines will be fully colored with it.
** If 2 colors. Lines will be colored with a gradient of these 2 colors.
** If 3 colors. Same as 2, having color #3 as a third gradient in the middle.
** Colors Gradient algorithm:
**		Along with fdf's maximum Z axis, the full gradient will only be
**			visible on the longest lines of all.
**		A flat az == bz == 0 line takes the first color.
**		A flat az == bz == maxz line takes the second color.
**		A flat az == bz == maxz/2 line takes the third color.
*/

static char	*get_color(char *str, t_co *color)
{
	int		nbi;
	t_byte	*cptr;

	nbi = 1;
	while (*str && *str != ';')
	{
		if (nbi > 3)
			return (NULL);
		else if (nbi == 1)
			cptr = &color->s.r;
		else
			cptr = (nbi == 2) ? &color->s.g : &color->s.b;
		if (ft_isdigit(*str))
		{
			if ((((t_ui32)*cptr) * 10 + (t_ui32)*str - (t_ui32)'0') > 255)
				return (NULL);
			*cptr = *cptr * 10 + (t_byte)*str - (t_byte)'0';
		}
		else
			nbi++;
		str++;
	}
	return ((nbi == 3) ? str : NULL);
}

static void	store_colors(t_co colors[3], int nb, t_fdf *fdf)
{
	fdf->num_avco = nb;
	while (--nb >= 0)
		fdf->avco[nb] = colors[nb];
}

int			 fdf_store_acavcolor(int ac, char *av[], t_fdf *fdf)
{
	t_co	colors[3];
	char	*str;
	int		i;

	if (ac < 3)
		return (1);
	if (*av[2] == '\0' || ft_strlen(av[2]) != ft_strspn(av[2], " ;0123456789"))
		return (2);
	ft_bzero((void*)colors, sizeof(t_co) * 3);
	str = av[2];
	i = 0;
	while (str && *str && i < 3)
	{
		str += (i == 0) ? 0 : 1;
		str = get_color(str, &colors[i++]);
	}
	if (!str || i > 3)
		return ((!str) ? 3 : 4);
	store_colors(colors, i, fdf);
	return (0);
}
