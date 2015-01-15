/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpix_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 08:40:08 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 08:40:08 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int fdf_put_pix(t_fdf fdf, t_cooi coo, t_co c)
{
	return (mlx_pixel_put(SERV, WIN1, coo.x, coo.y, c.i));
}

int fdf_put_fpix(t_fdf fdf, t_cood coof, t_co c)
{
	return (fdf_put_pix(fdf, DCOOTOI(coof), c));
}

int fdf_puts_pix(t_fdf fdf, t_cooi coo, t_co c)
{
	const int		dst = fdf.s.lsz * coo.y + coo.x * (fdf.s.bpp / 8);
	int				i;

	i = -1;
	while (++i < (fdf.s.bpp / 8))
	{
		fdf.s.dat[dst + i] = (char)c.s.b;
		c.i >>= 8;
	}
	return (0);
}

int fdf_puts_fpix(t_fdf fdf, t_cood coof, t_co c)
{
	return (fdf_puts_pix(fdf, DCOOTOI(coof), c));
}
