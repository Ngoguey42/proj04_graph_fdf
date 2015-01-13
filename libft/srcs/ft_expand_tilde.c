/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_tilde.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 08:22:35 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 08:22:38 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

static int	pwd(const char *src, const char *pwd, char **ptr)
{
	if (pwd == NULL || (src[2] != '/' && src[2] != '\0'))
		return (-1);
	*ptr = malloc(sizeof(char) * ft_strlen(src + 2) + ft_strlen(pwd) + 1);
	if (!ptr)
		return (ENOMEM);
	**ptr = '\0';
	ft_strcpy(*ptr, pwd);
	ft_strcat(*ptr, src + 2);
	ft_resolve_path(*ptr);
	return (0);
}

static int	home_cat(const char *src, const char *home, char buf[PATH_MAX + 1])
{
	size_t	nhome;
	size_t	nuid;

	*buf = '\0';
	nhome = ft_strlen(home);
	while (nhome > 0 && home[nhome - 1] == '/')
		nhome--;
	while (nhome > 0 && home[nhome - 1] != '/')
		nhome--;
	if (nhome == 0)
	{
		ft_strcpy(buf, "/");
		nhome = 1;
	}
	if (nhome + ft_strlen(src + 1) > PATH_MAX)
		return (ENAMETOOLONG);
	nuid = ft_strcharlen(src + 1, '/');
	ft_strlcpy(buf, home, nhome + 1);
	ft_strlcat(buf, src + 1, nhome + nuid + 1);
	return (0);
}

static int	homeroot(const char *src, const char *home, char **ptr)
{
	char	buf[PATH_MAX + 1];
	int		ret;

	if (home == NULL)
		return (-1);
	if ((ret = home_cat(src, home, buf)))
		return (ret);
	if ((ret = ft_access(buf, 0)) != 0)
		return (ret);
	*ptr = malloc(sizeof(char) * (ft_strlen(buf) +
		ft_strlen(src + ft_strcharlen(src + 1, '/')) + 1));
	if (*ptr == NULL)
		return (ENOMEM);
	**ptr = '\0';
	ft_strcpy(*ptr, buf);
	ft_strcat(*ptr, src + ft_strcharlen(src + 1, '/') + 1);
	ft_resolve_path(*ptr);
	return (0);
}

static int	home(const char *src, const char *home, char **ptr)
{
	size_t	nhome;
	size_t	nuid;

	nhome = ft_strlen(home);
	nuid = ft_strlen(src + 1);
	if (nhome + nuid > PATH_MAX)
		return (ENAMETOOLONG);
	*ptr = malloc(sizeof(char) * (nhome + nuid + 1));
	if (*ptr == NULL)
		return (ENOMEM);
	**ptr = '\0';
	ft_strcpy(*ptr, home);
	ft_strcat(*ptr, src + 1);
	ft_resolve_path(*ptr);
	return (0);
}

int			ft_expand_tilde(const char *src, char *refs[3], char **ptr)
{
	if (*src != '~')
		return (-1);
	else if (src[1] == '+')
		return (pwd(src, refs[1], ptr));
	else if (src[1] == '-')
		return (pwd(src, refs[2], ptr));
	else if (src[1] != '/' && src[1] != '\0')
		return (homeroot(src, refs[0], ptr));
	if (refs[0] == NULL)
		return (-2);
	return (home(src, refs[0], ptr));
}
