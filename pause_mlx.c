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
	fdf_init_surface(*fdf);
	fdf_set_surface(*fdf);
	fdf_push_surface(*fdf);
	mlx_loop(SERVP);
}

