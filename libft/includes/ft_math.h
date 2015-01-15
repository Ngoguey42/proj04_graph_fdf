/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:39:10 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/15 08:36:16 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "ft_typedefs.h"

# define ABS(x) ((x) < 0 ? -(x) : (x))
# define MAX(V1, V2) ((V1) > (V2) ? V1 : V2)
# define MIN(V1, V2) ((V1) < (V2) ? V1 : V2)
# define BASE_NBRS "0123456789abcdefghijklmnopqrstuvwxyz"

# ifndef IEEE_DOUBLE_BIG_ENDIAN
#  define IEEE_DOUBLE_BIG_ENDIAN 0
# endif

# if IEEE_DOUBLE_BIG_ENDIAN

union					u_dbl_extract
{
	struct
	{
		unsigned char	sig:1;
		unsigned short	exp:11;
		t_ui32			manh:20;
		t_ui32			manl:32;
	}					s;
	double				d;
};

union					u_nan_dbl_extract
{
	struct
	{
		unsigned char	sig:1;
		unsigned short	exp:11;
		unsigned char	nan:1;
		t_ui32			manh:19;
		t_ui32			manl:32;
	}					s;
	double				d;
};

union					u_dbl_shape
{
	struct
	{
		t_ui32			manh:32;
		t_ui32			manl:32;
	}					s;
	double				d;
};

# else

union					u_dbl_extract
{
	struct
	{
		t_ui32			manl:32;
		t_ui32			manh:20;
		unsigned short	exp:11;
		unsigned char	sig:1;
	}					s;
	double				d;
};

union					u_nan_dbl_extract
{
	struct
	{
		t_ui32			manl:32;
		t_ui32			manh:19;
		unsigned char	nan:1;
		unsigned short	exp:11;
		unsigned char	sig:1;
	}					s;
	double				d;
};

union					u_dbl_shape
{
	struct
	{
		t_ui32			manl:32;
		t_ui32			manh:32;
	}					s;
	double				d;
};
# endif

typedef union u_dbl_extract		t_dbl_extract;
typedef union u_nan_dbl_extract	t_nan_dbl_extract;
typedef union u_dbl_shape		t_dbl_shape;

/*
** Coordinates structs.
*/
typedef struct			s_cooi
{
	int					x;
	int					y;
	int					z;
}						t_cooi;

typedef struct			s_coof
{
	float				x;
	float				y;
	float				z;
}						t_coof;

typedef struct			s_cood
{
	double				x;
	double				y;
	double				z;
}						t_cood;

typedef struct			s_cool
{
	long double			x;
	long double			y;
	long double			z;
}						t_cool;
/*
** Colors structs.
*/

typedef union			u_co
{
	struct
	{
		t_byte			b;
		t_byte			g;
		t_byte			r;
		t_byte			a;
	}					s;
	int					i;
}						t_co;

# define VCOTOI(R, G, B, A)	((t_co){{B, G, R, A}})

typedef struct			s_cod
{
	double				b;
	double				g;
	double				r;
	double				a;
}						t_cod;
/*
** 'struct s_grad'
**		type	gradient type.
**		stc1:	start color 1.
**		dtc1:	delta color 1.
**		itc:	intermediary color.
**		stc2:	start color 2.
**		dtc2:	delta color 2.
**		v1:		value 1.
** If obj is 1 colored, convert any type to type 1. (Avoid div /0)
** If obj is 2 colored, convert type 3 to type 2. (Optimisation purpose)
** 3 colors gradient case:
**		type	= 3.
**		stc1:	start color between color 1&2.
**		dtc1:	delta color between color 1&2.
**		stc2:	start color between color 2&3.
**		dtc2:	delta color between color 2&3.
**		v1:		color break point.
**			~0. obj is mainly color2.
**			~.5 obj is half color1, half color2.
**			~1. obj is mainly color1.
*/
typedef struct			s_grad
{
	int					type;
	t_co				ico;
	t_cod				stc1;
	t_cod				dtc1;
	t_cod				itc;
	t_cod				dtc2;
	t_cod				stc2;
	double				v1;
}						t_grad;
/*
** Image struct.
*/
typedef struct			s_img
{
	void				*img;
	char				*dat;
	int					bpp;
	int					lsz;
	int					end;
}						t_img;

/*
** Math constants.
*/
# define M_INFINITY (1.0/0.0)
# define M_MINFINITY (-1.0/0.0)
# define M_NAN (0.0/0.0)
# define M_PD_MAXU (0x1.ffffffffffffep-1023)
# define M_PD_MINU (0x1.0p-1074)

/*
** Float operations.
*/
# define FISNEQ(AV, BV) ((AV) > (BV) || (AV) < (BV))
# define FISEQ(AV, BV) !FISNEQ(AV, BV)
# define FISGE(AV, BV) ((AV) > (BV) || FISEQ(AV, BV))

/*
** Types transformations Macros.
** 		'RFI'		Round Float to Integer.
** 		'RDI'		Round Double to Integer.
** 		'RIF'		Round Integer to Float.
** 		'RID'		Round Integer to Double.
*/
# define RFI(ARG)	(lrintf((double)ARG))
# define RDI(ARG)	(lrint(ARG))
# define RIF(ARG)	((float)ARG)
# define RID(ARG)	((double)ARG)

# define FCOOTOI(ARG)	(t_cooi){RFI(ARG.x), RFI(ARG.y), RFI(ARG.z)}
# define DCOOTOI(ARG)	(t_cooi){RDI(ARG.x), RDI(ARG.y), RDI(ARG.z)}
# define ICOOTOF(ARG)	(t_coof){RIF(ARG.x), RIF(ARG.y), RIF(ARG.z)}
# define ICOOTOD(ARG)	(t_cood){RID(ARG.x), RID(ARG.y), RID(ARG.z)}

/*
** Absolute_Coords_To_Struct(t_cooi|t_coof|t_cood)
*/
# define ACOOTOI(X, Y, Z)	(t_cooi){(X), (Y), (Z)}
# define ACOOTOF(X, Y, Z)	(t_coof){(X), (Y), (Z)}
# define ACOOTOD(X, Y, Z)	(t_cood){(X), (Y), (Z)}
# define ACOOTOL(X, Y, Z)	(t_cool){(X), (Y), (Z)}

# define DCOODIV(O, OP) ACOOTOD((O).x / OP, (O).y / OP, (O).z / OP)
# define DCOOADDD(O, A) ACOOTOD((O).x + (A).x, (O).y + (A).y, (O).z + (A).z)

# define ICOOADDX(O, OP) ACOOTOI((O).x + (OP), (O).y, (O).z)
# define ICOOADDY(O, OP) ACOOTOI((O).x, (O).y + (OP), (O).z)

/*
** Colors operations to integer union.
** 		'VCOTOI'	Color 'V'alues to 'I'nteger union.
** 		'VCOTOI2'	Color Int 'V'alue to 'I'nteger union.
** 		'DCOTOI'	'D'ouble color struct, to 'I'nteger color struct.
*/

# define BMASK(ARG)			(ARG & 0xff)
# define GMASK(ARG)			(ARG & 0xff) >> 0x08
# define RMASK(ARG)			(ARG & 0xff) >> 0x10
# define AMASK(ARG)			(ARG & 0xff) >> 0x18
# define VCOTOI2(I)			VCOTOI(RMASK(I), GMASK(I), BMASK(I), AMASK(I))
# define DCOTOI(ARG) VCOTOI(RDI(ARG.r), RDI(ARG.g), RDI(ARG.b), RDI(ARG.a))

/*
** Colors operations to double struct.
** 		'VCOTOD'	Color 'V'alues to 'D'ouble struct.
** 		'ICOTOD'	'I'nteger color struct, to 'D'ouble color struct.
** 		'DCOMUL'	'D'ouble color struct values 'M'ultiplication.
** 		'DCODIV'	'D'ouble color struct values 'D'ivision.
** 		'DDCOADD'	Two 'D'ouble color struct, 'ADD'ition.
** 		'DDCOSUB'	Two 'D'ouble color struct, 'SUB'straction.
*/
# define VCOTOD(R, G, B, A)	((t_cod){B, G, R, A})
# define ICOTOD(A) VCOTOD(RID(A.s.r), RID(A.s.g), RID(A.s.b), RID(A.s.a))
# define DCOMUL(O, OP) VCOTOD(O.r * (OP), O.g * (OP), O.b * (OP), 0)
# define DCODIV(O, OP) VCOTOD(O.r / (OP), O.g / (OP), O.b / (OP), 0)
# define DDCOADD(O, A) VCOTOD(O.r + A.r, O.g + A.g, O.b + A.b, 0)
# define DDCOSUB(O, A) VCOTOD(O.r - A.r, O.g - A.g, O.b - A.b, 0)

#endif
