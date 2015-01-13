/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 10:35:39 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 11:50:08 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_init_window(t_fdf *fdf)
{
    SDL_Init(SDL_INIT_VIDEO);
    fdf->win1 = (void*)SDL_SetVideoMode(WIN_X, WIN_Y, DEPTH, SDL_HWSURFACE);
    if (WIN1P == NULL)
    {
		ft_dprintf(2, "Could not create new window : %s\n", SDL_GetError());
		return (1);
    }
	ft_dprintf(2, "New window created. %p\n", WIN1P);
    SDL_WM_SetCaption("Fil de Fer", NULL);
	return (0);
}

int	fdf_init_surface(t_fdf fdf)
{
	SDL_LockSurface(WIN1);
	SDL_FillRect(WIN1, NULL, 0x000000);
	return (0);
}

int fdf_set_surface(t_fdf fdf)
{
	fdf_draw_screen(fdf);
	return (0);
}

int	fdf_push_surface(t_fdf fdf)
{
	SDL_UnlockSurface(WIN1);
	SDL_Flip(WIN1); 
	return (0);
}

int	fdf_quit(t_fdf fdf)
{
    SDL_Quit();
	(void)fdf;
	exit(EXIT_SUCCESS);
}
