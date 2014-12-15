/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpix_sdl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:05:33 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/03 13:05:35 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int fdf_put_pix(t_fdf fdf, t_cooi coo, t_co c)
{
    t_ui32	*pixmem32;
    t_ui32	colour;  
 
    colour = SDL_MapRGB( WIN1->format, c.s.r, c.s.g, c.s.b );
  
    pixmem32 = (t_ui32*) WIN1->pixels + coo.y * WIN1->pitch/BPP + coo.x;
    *pixmem32 = colour;
	return (0);
}

int fdf_put_fpix(t_fdf fdf, t_cood coof, t_co c)
{
    return (fdf_put_pix(fdf, DCOOTOI(coof), c));
}

int fdf_puts_pix(t_fdf fdf, t_cooi coo, t_co c)
{
    t_ui32	*pixmem32;
    t_ui32	colour;  
 
    colour = SDL_MapRGB( WIN1->format, c.s.r, c.s.g, c.s.b );
  
    pixmem32 = (t_ui32*) WIN1->pixels + coo.y * WIN1->pitch/BPP + coo.x;
    *pixmem32 = colour;
	return (0);
}

int fdf_puts_fpix(t_fdf fdf, t_cood coof, t_co c)
{
    return (fdf_puts_pix(fdf, DCOOTOI(coof), c));
}
