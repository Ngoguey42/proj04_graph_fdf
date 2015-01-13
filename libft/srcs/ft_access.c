/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 13:41:31 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/31 08:33:04 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include "libft.h"
#include "ft_math.h"

/*
** 'ft_access' in case 'errno' is not allowed.
**		>0	Errno equivalent.
**		0	No error encountered.
**		-1	Undefined error. (Unused)
** *
**		Errors catched in 'ft_access':
** EFAULT		'pathname' pointer incorrect.
** ENAMETOOLONG	'pathname' too long.
** *
**		Errors catched if 'access(fullpath, 0)' returns 0:
** EACCES		Access with current 'mode' denied.
** *
**		Errors catched while following down fullpath
** ENOTDIR		Part of the path is not a directory.
** ENOENT		No such file or directory.
** EIO			In / Out error.
** *
**		Errors not handled:
** EINVAL		'mode' incorrect.
** ETXTBSY		W_OK on currently executed file.
** EROFS		W_OK on read-only file.
** ELOOP		Too many symbolic links encountered while exploring path.
*/

static int	analyse_fullpath(const char *path, int mode)
{
	if (access(path, mode) == 0)
		return (0);
	if (access(path, 0) == 0)
		return (EACCES);
	return (ENOENT);
}

static int	analyse_pathchunk(const char *path)
{
	struct stat		s;

	if (access(path, 0) == 0)
	{
		if (lstat(path, &s) < 0)
			return (EIO);
		if (!(S_ISDIR(s.st_mode)))
			return (ENOTDIR);
		return (0);
	}
	return (ENOENT);
}

static int	explore_path(const char *path)
{
	char	*slash_ptr;
	int		i;

	while ((slash_ptr = ft_strrchr(path, (int)'/')) != NULL)
	{
		*slash_ptr = '\0';
		if ((i = analyse_pathchunk(path)) != ENOENT)
			return (i == 0 ? ENOENT : i);
	}
	return (ENOENT);
}

static int	max_file_len(const char *str)
{
	int		max;
	char	*tmp;

	max = 0;
	if (ft_strchr(str, (int)'/') == NULL)
		return (ft_strlen(str));
	while ((tmp = ft_strchr(str, (int)'/')) != NULL)
	{
		max = MAX(max, tmp - str);
		str = tmp + 1;
	}
	return (max);
}

int			ft_access(const char *pathname, int mode)
{
	char		path[PATH_MAX + 1];
	int			i;

	if (pathname == NULL)
		return (EFAULT);
	if (ft_strlen(pathname) >= PATH_MAX || max_file_len(pathname) > NAME_MAX)
		return (ENAMETOOLONG);
	*path = '\0';
	(void)ft_resolve_path(ft_strcpy(path, pathname));
	if ((i = analyse_fullpath(path, mode)) != ENOENT)
		return (i);
	return (explore_path(path));
}
