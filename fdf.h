/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 08:53:27 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 08:38:35 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <libft.h>
# include <ft_math.h>
# include <ft_clock.h>
#include <ft_debug.h> //debug

# define USEMLX
# ifdef USEMLX
# include <mlx.h>
# define SERV fdf.serv
# define WIN1 fdf.win1
# define SERVP fdf->serv
# define WIN1P fdf->win1
# else
# include <SDL/SDL.h>
# define BPP 4
# define DEPTH 32
# define WIN1 ((SDL_Surface*)fdf.win1)
# define WIN1P ((SDL_Surface*)fdf->win1)
# endif

#define PEACE(A1, A2) A1 A2; (void)A2

# define WINY 1000.0

# define WIN_Y (int)(WINY)
# define RATIO 1.77777778
# define WIN_X (int)(WINY * RATIO)

# define FOV (M_PI * 1.0 / 3.0)
# define FOV_Y (FOV / RATIO)
# define FOV_X FOV

# define THDELTA (FOV_Y / 2.0)
# define THMIN (M_PI / 2 - THDELTA)
# define THMAX (M_PI / 2 + THDELTA)

# define PHMAX (FOV_X / 2.0)
# define PHMIN (-PHMAX)

# define DENSITY 1.0
# define DENSITY3D 50.0

# define DBG (0)

# define DISTANCE_FOCALE 5.0

# define XYSPEEDBASE 0.5
# define ZSPEEDBASE 0.5  
# define ASPEEDBASE 0.075

# define DEFAULT_COLOR0 VCOTOI(50, 125, 50, 0)
# define DEFAULT_COLOR1 VCOTOI(255, 255, 255, 0)
# define DEFAULT_COLOR2 VCOTOI(139, 69, 19, 0)

# define STARTCAMX 6.361
# define STARTCAMY 11.382
# define STARTCAMZ 0.0

# define STARTCAMPH (1.528 * M_PI)
# define STARTCAMTH (10.958 * M_PI)


# define POINTS_NAMES_LEN 30

# define KEYQUI 65307
# define KEYMFW 65362
# define KEYMBW 65364
# define KEYMLE 65361
# define KEYMRI 65363
# define KEYMUP 32
# define KEYMDO b
# define KEYTRI d
# define KEYTLE a
# define KEYTUP 65362
# define KEYTDO 65364

# define MAX_PNT 50
# define MAX_OBJ 75

/*
** 'struct s_ang':	Spherical coordinates.
** 	th:		Theta. Angle x1-O-Pxy. With Pxy: Pt's projection in the Oxy plan.
**	ph:		Phi. Angle z1-O-Point. 
*/
typedef struct	s_ang
{
	double		th;
	double		ph;
}				t_ang;

/*
** 'struct s_point':
** 		name:	Point's name, for index or debug purpose.
** 		coof:	Coordinates x,y,z.
** 		color:	{{r, g, b, a}, i} colors.
*/
typedef struct	s_point
{
	char		name[POINTS_NAMES_LEN + 1];
	t_cood		coof;
	t_co		co;
}				t_point;

/*
** 'struct s_fdfobj':
**		type:		object shape.
**		Xpointi:	points indexes
**		gr:			colors/gradients informations
*/
typedef struct	s_fdfobj
{
	int			type;
	int			apointi;
	int			bpointi;
	int			cpointi;
	t_grad		gr;
}				t_fdfobj;

/*
** 'struct s_fdf':
**		serv:		mlx X11 serv.
**		win1:		mlx & sdl window pointer.
**		s:			screen img struct. (see libft's ft_math.h)
**		coo:		camera coordinates.
**		a:			camera angle.
**		ev:			events states.
**		pnt:		points table.
**		obj			objects table.
**		pntm:		malloced' points table.
**		objm:		malloced' objetcs table.
** 		fdfsz:		grid size, as read in av[1].
** 		num_avco:	num colors read in av[2].
** 		avco:		colors read in av[2].
** 		davco:		delta between colors read in av[2].
*/
typedef struct	s_fdf
{
	void		*serv;
	void		*win1;
	t_img		s;
	t_cood		co;
	t_ang		a;
	int			ev[10];
	t_clockev	mvmt_clockev;
	int			redraw;
	t_point		pnt[MAX_PNT + 1];
	t_fdfobj	obj[MAX_OBJ + 1];
	t_point		**pntm[1];
	t_fdfobj	**objm[1];
	t_cooi		fdfsz;
	int			num_avco;
	t_co		avco[3];
	t_cod		davco[2];
}				t_fdf;

int     fdf_3d_line(t_fdf fdf, t_fdfobj obj, t_point ap, t_point bp);
t_cood  fdf_3d_pix(t_fdf fdf, t_cood coof, t_co c);
int		fdf_put_line_g3(t_fdf fdf, t_cood cooa, t_cood coob, t_grad gr);

int		fdf_put_pix(t_fdf fdf, t_cooi coo, t_co c);
int		fdf_put_fpix(t_fdf fdf, t_cood coof, t_co c);
int		fdf_put_string(t_fdf fdf, t_cooi coo, t_co c, char *str);

int		fdf_puts_pix(t_fdf fdf, t_cooi coo, t_co c);
int		fdf_puts_fpix(t_fdf fdf, t_cood coof, t_co c);

int		fdf_put_line(t_fdf fdf, t_cood cooa, t_cood coob, t_co c);
int		fdf_put_line_grad(t_fdf fdf, t_cood cooa, t_cood coob, t_grad grad);

void	fdf_pause(t_fdf *fdf);

void	store_segments(int lineinfo[3], t_fdf *fdf);
void    fdf_store_imgs(t_fdf *fdf, int ac, char *av[]);
int		fdf_store_acavgrid(int ac, char *av[], t_fdf *fdf);
int		fdf_store_acavcolor(int ac, char *av[], t_fdf *fdf);
t_grad	fdf_build_grad(t_fdf fdf, double az, double bz);

int     fdf_draw_screen(t_fdf fdf);

int		fdf_init_window(t_fdf *fdf);
int		fdf_init_surface(t_fdf fdf);
int 	fdf_set_surface(t_fdf fdf);
int		fdf_push_surface(t_fdf fdf);
int		fdf_quit(t_fdf fdf);

int		fdf_set_defpos(t_fdf *fdf);
int		fdf_move(t_fdf *fdf);
int		fdf_move_void(void *fdf);

int		fdf_expose_hook(t_fdf *fdf);
int		fdf_keydo_hook(int keycode,t_fdf *fdf);
int		fdf_keyup_hook(int keycode,t_fdf *fdf);
int		fdf_mouse_hook(int button,int x,int y,t_fdf *fdf);
int		fdf_loop_hook(t_fdf *fdf);



void    fdf_debug(t_fdf fdf);

#endif
