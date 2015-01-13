/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_tilde_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 08:24:19 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 08:24:43 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"

int			ft_expand_tilde_env(const char *src, const char **env, char **ptr)
{
	char	*ref[3];

	if (env == NULL)
		return (-1);
	ref[0] = ft_envget(env, "HOME=");
	ref[1] = ft_envget(env, "PWD=");
	ref[2] = ft_envget(env, "OLDPWD=");
	if (ref[0] != NULL)
		ref[0] += 5;
	if (ref[1] != NULL)
		ref[1] += 4;
	if (ref[2] != NULL)
		ref[2] += 7;
	return (ft_expand_tilde(src, ref, ptr));
}
