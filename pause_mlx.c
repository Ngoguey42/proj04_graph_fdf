/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 08:40:52 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 08:42:08 by ngoguey          ###   ########.fr       */
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
