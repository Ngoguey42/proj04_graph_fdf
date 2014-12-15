/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typedefs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:39:33 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/12 10:00:52 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPEDEFS_H
# define FT_TYPEDEFS_H

# include <stddef.h>

# ifndef T_BOOL
#  define T_BOOL

typedef enum					e_bool
{
	false,
	true
}								t_bool;

# endif

typedef struct					s_list
{
	void						*content;
	size_t						content_size;
	struct s_list				*next;
}								t_list;

typedef unsigned char			t_byte;
typedef unsigned short			t_dbyte;
typedef int						t_i;
typedef unsigned int			t_ui;
typedef short int				t_i16;
typedef unsigned short int		t_ui16;
typedef long int				t_i32;
typedef unsigned long int		t_ui32;
typedef long long int			t_i64;
typedef unsigned long long int	t_ui64;

typedef struct					s_structspec
{
	char						*key;
	size_t						size;
	int							type;
}								t_structspec;

typedef union					u_readptr
{
	void						*p;
	t_ui64						li;
}								t_readptr;

typedef struct					s_tabdt
{
	void						**ptr;
	size_t						size;
}								t_tabdt;

typedef struct					s_metak
{
	void						*key;
	void						*value;
}								t_metak;

typedef struct					s_metat
{
	t_metak						**akey[1];
	size_t						keysz;
	char						tabname[21];
	void						*(*initkey)(const void *key);
	int							(*cmp)(const void *s1, const void *s2);
}								t_metat;

#endif
