/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 08:57:28 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/25 09:43:26 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	fdf_pause(t_fdf *fdf)
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
			case SDL_KEYUP: /* Si appui sur une touche */
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
					{
						continuer = 0;
						break;
					}
					case SDLK_SPACE:
					{
						fdf->co.z += 0.5;
						fdf_init_surface(*fdf);
						fdf_set_surface(*fdf);
						fdf_push_surface(*fdf);
						break;
					}
					case SDLK_c:
					{
						fdf->co.z -= 0.5;
						fdf_init_surface(*fdf);
						fdf_set_surface(*fdf);
						fdf_push_surface(*fdf);
						break;
					}
					case SDLK_a:
					{
						fdf->a.ph += 0.5;
						fdf_init_surface(*fdf);
						fdf_set_surface(*fdf);
						fdf_push_surface(*fdf);
						break;
					}
					case SDLK_d:
					{
						fdf->a.ph -= 0.5;
						fdf_init_surface(*fdf);
						fdf_set_surface(*fdf);
						fdf_push_surface(*fdf);
						break;
					}
					case SDLK_w:
					{
						fdf->co.x += acos(fdf->a.ph) * 0.5;
						fdf->co.y += asin(fdf->a.ph) * 0.5;
						fdf_init_surface(*fdf);
						fdf_set_surface(*fdf);
						fdf_push_surface(*fdf);
						break;
					}
					case SDLK_s:
					{
						fdf->co.x -= acos(fdf->a.ph) * 0.5;
						fdf->co.y -= asin(fdf->a.ph) * 0.5;
						fdf_init_surface(*fdf);
						fdf_set_surface(*fdf);
						fdf_push_surface(*fdf);
						break;
					}
					case SDLK_q:
					{
						fdf->co.x += asin(fdf->a.ph) * 0.5;
						fdf->co.y += acos(fdf->a.ph) * 0.5;
						fdf_init_surface(*fdf);
						fdf_set_surface(*fdf);
						fdf_push_surface(*fdf);
						break;
					}
					case SDLK_e:
					{
						fdf->co.x -= asin(fdf->a.ph) * 0.5;
						fdf->co.y -= acos(fdf->a.ph) * 0.5;
						fdf_init_surface(*fdf);
						fdf_set_surface(*fdf);
						fdf_push_surface(*fdf);
						break;
					}
					case SDLK_UP:
					{
						fdf->a.th -= 0.5;
						fdf_init_surface(*fdf);
						fdf_set_surface(*fdf);
						fdf_push_surface(*fdf);
						break;
					}
					case SDLK_DOWN:
					{
						fdf->a.th += 0.5;
						fdf_init_surface(*fdf);
						fdf_set_surface(*fdf);
						fdf_push_surface(*fdf);
						break;
					}
					default:
						break;
				}
			default:
				break;
        }
    }
	(void)fdf;
}
