/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:10:36 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/25 17:14:19 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	fdf_debug(t_fdf fdf)
{
	printf("Coords CAM: (%.3f, %.3f, %.3f)\n",
			   fdf.co.x, fdf.co.y, fdf.co.z);
	printf("Angle  CAM: (%.3f, %.3f) * pi\n",
			   fdf.a.ph / M_PI, fdf.a.th / M_PI);
	
}
