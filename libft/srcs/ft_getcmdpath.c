/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmdpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 10:04:04 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/31 09:11:50 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

/*
** *
** 'test_path' Concats a given 'dirpath' from env, and a 'cmdname' an tests it.
** *
** 'cmd_as_path' Tries to expand a tilde or treats cmdname as a full path.
** *
** 'cmd_as_cmd' Parses env's 'path' for a bin path.
** *
** 'ft_getcmdpath' looks for a binary path.
**		Treats 'cmd' as a full binary path if it contains a '/' char.
**		Else, treats 'cmd' as a command name.
** *
**		If 'ft_access' returned 0, stores in 'ptr' an allocation of 'cmd'
**		Else, sets '*ptr' to NULL.
** *
**	  Returns:
**		>0 Errno equivalent.
**		0 No error encountered.
**		-1 Undefined error.
**		-2 Command not found.
** *
*/

static int	test_path(const char *dirpath, const char *cmdname)
{
	char	fullpath[PATH_MAX + 1];

	if (ft_strlen(dirpath) + ft_strlen(cmdname) + 1 > PATH_MAX)
		return (ENAMETOOLONG);
	if (*dirpath != '\0')
	{
		ft_strcpy(fullpath, dirpath);
		ft_strcat(fullpath, "/");
	}
	else
		*fullpath = '\0';
	ft_strcat(fullpath, cmdname);
	return (ft_access(fullpath, X_OK));
}

static int	cmd_as_path(char **cmdname, char *refs[4])
{
	int		ret;
	char	*expansion;

	ret = ft_expand_tilde(*cmdname, (char**)(refs + 1), &expansion);
	if (ret > 0)
		return (ret);
	if (ret == 0)
	{
		free(*cmdname);
		*cmdname = expansion;
	}
	if (ret >= 0)
		return (ret);
	return (test_path("", *cmdname));
}

static int	alloc_new_string(size_t n, char *dirpath, char **cmdname, int prev)
{
	char	*new;

	n += ft_strlen(*cmdname) + 1;
	new = (char*)malloc(sizeof(char) * (n + 1));
	if (new == NULL)
		return (ENOMEM);
	*new = '\0';
	ft_strcpy(new, dirpath);
	ft_strcat(new, "/");
	ft_strcat(new, *cmdname);
	free(*cmdname);
	*cmdname = new;
	return (prev);
}

static int	cmd_as_cmd(const char *path, char **cmdname)
{
	char	dirpath[PATH_MAX + 1];
	size_t	n;
	int		ret;

	while (*path != '\0')
	{
		n = ft_strcharlen(path, ':');
		if (n < PATH_MAX)
		{
			ft_strlcpy(dirpath, path, n + 1);
			if ((ret = test_path(dirpath, *cmdname)) != ENOENT)
			{
				if (ret == 0)
					return (alloc_new_string(n, dirpath, cmdname, ret));
				return (ret);
			}
		}
		path += n;
		path += (*path == ':') ? 1 : 0;
	}
	return (-2);
}

int			ft_getcmdpath(const char *cmd, char *refs[4], char **ptr)
{
	size_t	n;
	char	*cmdname;
	int		ret;

	*ptr = NULL;
	n = ft_strcspn(cmd, "<>;| \t");
	cmdname = (char*)malloc(sizeof(char) * (n + 1));
	if (cmdname == NULL)
		return (ENOMEM);
	ft_strlcpy(cmdname, cmd, n + 1);
	if (ft_strchr(cmdname, (int)'/') != NULL)
		ret = cmd_as_path(&cmdname, refs);
	else if (refs[0] == NULL)
		ret = ENOENT;
	else
		ret = cmd_as_cmd(refs[0], &cmdname);
	if (ret != 0)
		free(cmdname);
	else
		*ptr = cmdname;
	return (ret);
}
