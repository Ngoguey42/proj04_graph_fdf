/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_acav_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 07:42:11 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 07:41:45 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <fdf.h>

/*
** Valid stdin file:
**		At least 1 point per line.
**		At least 1 point per column.
**		Same amount of points on every lines.
**		Consists of '\n' 'spaces' and 'base-10 digits'.
** Valid stdin line specifications:
**		Must start with a digit.
**		Must end with a digit and a '\n'.
**		Points consisting of adjacent 'base-10 digits' must be separated with
**			at least 1 'space(s)'.
*/

/*
** 'lineinfo'
**		[0] = cols on cur line, then line number.
**		[1] = numlines.
**		[2] = cols expected, then num cols.
** 'pointinfo'
**		[0] = line number, X.
**		[1] = col number, Y.
**		[2] = number read. Z.
*/

static int	get_line_infos(char *line, int lineinfo[3])
{
	int	t;

	if (!ft_isdigit(*line))
		return (1);
	t = 1;
	lineinfo[0] = 1;
	while (*line != '\0')
	{
		if (ft_isdigit(*line))
		{
			if (t == 0)
				lineinfo[0]++;
			t = 1;
		}
		else if (*line != ' ' || line[1] == '\0')
			return (1);
		else
			t = 0;
		line++;
	}
	lineinfo[2] = (lineinfo[2] == -1) ? lineinfo[0] : lineinfo[2];
	if (lineinfo[2] != lineinfo[0])
		return (1);
	lineinfo[1]++;
	return (0);
}

static void	store_point(int pointinfo[3], int lineinfo[3], t_fdf *fdf)
{
	t_cood	coof;
	t_point	point;
	char	buf[POINTS_NAMES_LEN + 1];
	char	tmp[6 + 1];

	ft_strcpy(buf, "fdf");
	*tmp = '\0';
	ft_strcat(buf, ft_itoa_c(pointinfo[0], tmp, 10));
	ft_strcat(buf, ";");
	*tmp = '\0';
	ft_strcat(buf, ft_itoa_c(pointinfo[1], tmp, 10));
	coof = (t_cood){
		(double)pointinfo[0],
		(double)pointinfo[1],
		(double)pointinfo[2] / 5.5};
	ft_strcpy(point.name, buf);
	point.coof = coof;
	fdf->fdfsz.z = MAX(fdf->fdfsz.z, pointinfo[2]);
	if (ft_tabaddm((void***)fdf->pntm, &point, sizeof(t_point)))
		exit(0);
	(void)lineinfo;
}

static void	store_line(t_fdf *fdf, char *line, int lineinfo[3])
{
	int		pointinfo[3];
	int		t;

	pointinfo[0] = lineinfo[0];
	pointinfo[1] = 1;
	pointinfo[2] = 0;
	t = 1;
	while (*line != '\0')
	{
		if (*line == ' ')
		{
			t = 0;
			pointinfo[2] = 0;
		}
		else
		{
			pointinfo[1] += (t == 0) ? 1 : 0;
			t = 1;
			pointinfo[2] = pointinfo[2] * 10 + *line - '0';
			if (line[1] == ' ' || line[1] == '\0')
				store_point(pointinfo, lineinfo, fdf);
		}
		line++;
	}
}

int			fdf_store_acavgrid(int ac, char *av[], t_fdf *fdf)
{
	char	*fileline;
	int		lineinfo[3];
	int		fd;
	int		gnl;

	if (ac < 1 || (fd = open(av[1], O_RDONLY)) < 0)
		return (1);
	lineinfo[1] = 0;
	lineinfo[2] = -1;
	while ((gnl = get_next_line(fd, &fileline)) > 0)
		if (get_line_infos(fileline, lineinfo))
			return (2);
	if (gnl < 0)
		return (1);
	if ((fd = (close(fd), open(av[1], O_RDONLY))) < 0)
		return (3);
	lineinfo[0] = 0;
	while (get_next_line(fd, &fileline) > 0)
	{
		lineinfo[0]++;
		store_line(fdf, fileline, lineinfo);
	}
	store_segments(lineinfo, fdf);
	fdf->fdfsz = ACOOTOI(lineinfo[1], lineinfo[2], fdf->fdfsz.z);
	return (close(fd), 0);
}
