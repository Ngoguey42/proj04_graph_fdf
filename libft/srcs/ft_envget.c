/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 08:22:49 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 08:22:50 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_envgetp(const char **env, const char *key)
{
	size_t		klen;

	if (env == NULL)
		return (NULL);
	if (ft_strchr(key, (int)'=') != NULL)
		klen = ft_strcharlen(key, '=') + 1;
	else
		klen = ft_strlen(key);
	while (*env != NULL)
	{
		if (ft_strnequ(*env, key, klen))
			return ((char**)env);
		env++;
	}
	return (NULL);
}

char	*ft_envget(const char **env, const char *key)
{
	char **ret;

	ret = ft_envgetp(env, key);
	return (ret == NULL ? NULL : *ret);
}
