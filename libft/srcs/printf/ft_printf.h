/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:35:17 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/22 09:44:06 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include "libft.h"

/*
** TODOLIST
** recheck les arguments size
** take care of memory leaks in add_color_flags.c
*/

/*
** va_ lib to use, if forbidden in project.
*/

# include <stdarg.h>
# define VATYPE		va_arg
# define VASTA		va_start
# define VACPY		va_copy
# define VAEND		va_end

/*
** FLAGS
*/
# define CHARS_FLAGS "-+ #0!$MNHIJK_\'"
# define MINU_MASK 0x1
# define PLUS_MASK 0x2
# define SPAC_MASK 0x4
# define HASH_MASK 0x8
# define ZERO_MASK 0x10
# define EXCL_MASK 0x20
# define DOLL_MASK 0x40
# define APOS_MASK 0x4000

# define FIRT_C_FLAG_ID		7
# define NUM_COLOR_FLAGS 	7
# define COLORS_FLAGS_FIELD	0x3F80
# define SIZE_OF_FLAGS		(sizeof(TYPE_OF_FLAGS) * 8)
# define TYPE_OF_FLAGS		unsigned short
# include "ft_printfdefs.h"

/*
** INFO
*/
# define WSTA_MASK	0x1
# define PSTA_MASK	0x2
# define PNUM_MASK	0x4

/*
** LENGTH, SPECIFIERS
*/
# define CHARS_LENGTH		"jztLhl"
# define NUM_DBL_CHAR_LEN	2
# define CHARS_SPECIFIERS	"diuoxXfFeEgGaAcspn%brDUO"
# define NUM_SPECIFIERS		25 + 1

/*
** MACROS
*/
# define AND_F(x) (part->flags & x)
# define AND_I(x) (part->info & x)
# define PAD_CHAR part->flags & ZERO_MASK ? '0' : ' '

/*
** MISC
*/
# define NUM_C_TAGS 33
# define NUM_SMALLC_TAGS 7

/*
** BUFFERS
*/
# define DEFAULT_SCREEN_WIDTH 75
# define DEFAULT_COLS_SPACER ' '
# define DEFAULT_FILLER ' '

/*
** For external use.
*/
int		ft_getprintf(char **ret, const char *format, va_list args);
void	ptf_free_list(t_printf_part **beginning);

int		parse_format(const char *format, t_printf_part **beginning);
int		final_string_size(t_printf_part *current);
int		coi(const char *str);
int		add_color_flag(t_printf_part *p);
void	string_cat(char *s1, size_t len);

int		store_opt_1(char c, t_printf_part *part);
int		store_opt_2(char c, t_printf_part *part);
int		store_opt_3(char c, t_printf_part *part);
int		store_opt_5(char c, t_printf_part *part);
int		store_opt_6(char c, t_printf_part *part);
int		store_opt_7(char c, t_printf_part *part);
int		store_opt_8(char c, t_printf_part *part);

/*
** Specifiers building.
*/
int		build_nbr_0(t_printf_part *part, va_list *args);
int		build_nbr_1(t_printf_part *part, va_list *args);
int		build_nbr_3(t_printf_part *part, va_list *args);
int		build_nbr_4(t_printf_part *part, va_list *args);
int		build_nbr_5(t_printf_part *part, va_list *args);
int		build_nbr_6(t_printf_part *part, va_list *args);
int		build_nbr_7(t_printf_part *part, va_list *args);
int		build_nbr_8(t_printf_part *part, va_list *args);
int		build_nbr_13(t_printf_part *part, va_list *args);
int		build_nbr_14(t_printf_part *part, va_list *args);
int		build_nbr_15(t_printf_part *part, va_list *args);
int		build_nbr_16(t_printf_part *part, va_list *args);
int		build_nbr_17(t_printf_part *part, va_list *args);
int		build_nbr_19(t_printf_part *part, va_list *args);
int		build_nbr_20(t_printf_part *part, va_list *args);
int		build_nbr_21(t_printf_part *part, va_list *args);
int		build_nbr_22(t_printf_part *part, va_list *args);
int		build_nbr_23(t_printf_part *part, va_list *args);
int		build_nbr_24(t_printf_part *part, va_list *args);
t_i64	get_signed_varg(t_byte length, va_list *args);
t_ui64	get_unsigned_varg(t_byte length, va_list *args);

/*
** %i %d %u %x %X %o %p dependency.
*/
void	apply_width_integer_pad(t_printf_part *part, char **sp, int l, int w);

/*
** %a %A dependencies.
*/
char	*ft_build_unnormalized(double nbr, t_printf_part *part);
char	*ft_build_normalized(double nbr, t_printf_part *part);
void	round_mantissa_b16(char **ptr, int pre, int *int_part_two);

char	*ptf_build_decnbr(double nbr, t_printf_part *part);

/*
** %S dependencies.
*/
size_t	npnt_len(char *str, t_printf_part *part, int p);
void	npnt_cat(char **ret, char src, char *input, int *color_status);

/*
** Buffer.
*/
int		ft_fbuffer(char **ret, const char *arg1, int arg2);
char	*tabbuffer_settable(char *arg1);
int		ptf_fflush_table_buffer(char **ret);
int		ptf_buffer_infos(char *arg1, int arg2);
int		ptf_cols_concat_string(char **ret, t_list *l, int *cols, int n);
size_t	ptf_calc_real_content_size(t_list *lst);
t_list	*ptf_buffer(char *arg1, int arg2, void *arg3);
int		ptf_fflush_cols_buffer(char **ret, int width);
int		ptf_fflush_lscols(char **ret, int width);
void	ptf_lscols_getdatas(t_list *lst, int wid, int *datas);
size_t	ptf_showed_len(char *str);

/*
** debug
*/
void	inspect_part(t_printf_part *part);

#endif
