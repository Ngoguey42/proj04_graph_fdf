/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 08:23:04 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 08:23:06 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_envnew(char ***env, char *line)
{
	size_t	count;
	char	**newenv;

	count = 0;
	while ((*env)[count] != NULL)
		count++;
	if ((newenv = (char**)malloc(sizeof(char*) * (count + 2))) == NULL)
		return (NULL);
	newenv[count + 1] = NULL;
	newenv[count] = line;
	count = 0;
	while ((*env)[count] != NULL)
	{
		newenv[count] = (*env)[count];
		count++;
	}
	free(*env);
	*env = newenv;
	return (*env + count);
}

char	**ft_envnew_m(char ***env, char *line)
{
	char	*str;

	if ((str = ft_strdup(line)) == NULL)
		return (NULL);
	return (ft_envnew(env, str));
}

char	**ft_envupdate_m(char ***env, char *line)
{
	char	**ptr;

	ptr = ft_envgetp((const char**)*env, line);
	if (ptr == NULL)
		return (ft_envnew_m(env, line));
	free(*ptr);
	*ptr = ft_strdup(line);
	if (*ptr == NULL)
		return (NULL);
	return (ptr);
}
