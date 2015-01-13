/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:28:26 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 10:45:50 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdarg.h>
# include "ft_typedefs.h"

/*
** -
** stdio.h
** -
*/
/*
** Formatted input/output:
** int		ft_fprintf(FILE *stream, const char *format, ...);
** int     ft_vfprintf(FILE *stream, const char *format, va_list arg);
*/

int		ft_vprintf(const char *format, va_list arg);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vsprintf(char *s, const char *format, va_list arg);
int		ft_vsnprintf(char *s, size_t n, const char *format, va_list arg);
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_snprintf(char *s, size_t n, const char *format, ...);

int		ft_printfibuf(char *arg1, int arg2, void *arg3);
int		ft_printffbuf(const char *type, int wid);
/*
** Character input/output:
*/
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putnbr(int i);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);

void	ft_putnbr_base(int n, int base);
void	ft_putunbr_base(unsigned int n, int base);
void	ft_putnchar(char c, size_t n);

/*
** -
** stdlib.h
** -
*/
int		ft_atoi(const char *str);
int		ft_atoi_base(const char *str, int base);
/*
** itoa and co.
** ft_itoa		alloc	, int		, base 10
** ft_itoa_c	copy	, int		, base n
** ft_itoa_a	alloc	, int		, base n
** ft_lutoa		copy	, uint64	, base n
** ft_lutoa_a	alloc	, uint64	, base n
** NYI:
** ft_litoa		copy	, int64		, base n
** ft_litoa_a	alloc	, uint64	, base n
** ft_utoa		copy	, uint		, base n
** ft_utoa_a	alloc	, uint		, base n
*/
char	*ft_itoa(int n);
char	*ft_itoa_c(int value, char *str, int base);
char	*ft_itoa_a(int value, int base);
char	*ft_lutoa(t_ui64 value, char *str, int base);
char	*ft_lutoa_a(t_ui64 value, int base);
char	*ft_utoa(t_ui32 value, char *str, int base);
/*
** char	*ft_litoa(t_i64 value, char *str, int base);
** char	*ft_litoa_a(t_i64 value, int base);
** char	*ft_utoa_a(t_ui32 value, int base);
*/
/*
** Custom Strings Manipulation:
*/
int		ft_maxintlen(size_t sizeofint, int base);
int		ft_convsz(t_ui64 bytes, char *buffer);
char	*ft_roundup_b10(char *str);
void	ft_putexpchar(int exp, char *buffer);
char	*ft_pad_string(char *str, char c, int n, int freestr);
char	*ft_revstr(char *str);
int		ft_eval_expr(char *str);
/*
** Allocation:
*/
void	*ft_memalloc(size_t size);
void	*ft_memdup(void *p, size_t size);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	*ft_crealloc(void *ptr, size_t old_size, size_t new_size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoinfree(char *s1, char *s2, int frees1, int frees2);
char	*ft_strsub(char const *s, t_ui32 start, size_t len);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
int		ft_strsplit_s(const char *s, char *delims, char ***ret);

/*
** ctype.h
** -
*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isunixspace(int c);
int		ft_isupper(int c);
int		ft_isxdigit(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

int		ft_isascii(int c);
int		ft_ispair(int c);
int		ft_isescape(int c);
int		ft_isdigit_base(int c, int base);

/*
** -
** Strings.h
** -
*/
/*
** Copying:
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *s1, const char *s2, size_t num);
size_t	ft_strlcpy(char *s1, const char *s2, size_t num);

char	*ft_strccpy(char *dst, const char *src);
char	*ft_catpath(const char *path, const char *file, char *dst);
char	*ft_filename(const char *path, char *dst);
int		ft_resolve_path(char *buf);
int		ft_getcmdpath(const char *cmd, char *refs[4], char **ptr);
int		ft_getcmdpath_env(const char *cmd, const char **env, char **ptr);
int		ft_access(const char *pathname, int mode);
void	*ft_memccpy2(void *dst, const void *src, size_t n);
/*
** Concatenation:
*/
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strcatfree(char *s1, char *s2);
/*
** Comparison:
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
int		ft_match(char *s1, char *s2);
int		ft_voidstrcmp(const void *s1, const void *s2);
int		ft_voiduintcmp(const void *s1, const void *s2);
int		ft_voidintcmp(const void *s1, const void *s2);
/*
** Searching:
*/
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *str, int c);
size_t	ft_strspn(const char *str1, const char *str2);
size_t	ft_strcspn(const char *s1r, const char *s2r);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
/*
** Other:
*/
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);

void	ft_bzero(void *s, size_t n);
void	ft_strclr(char *s);
size_t	ft_strcharlen(const char *str, const char delim);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	*ft_memcset(void *b, int c, size_t len);
int		get_next_line(int const fd, char **line);

/*
** -
** math.h
** -
*/
/*
** Exponential and logarithmic functions:
*/
double	ft_log10(double nb);
double	ft_log2(double nb);

double	ft_log16(double nb);
/*
** Power functions:
*/

int		ft_powi(int n, t_ui32 p);
t_i64	ft_lpowi(t_i64 n, t_ui32 p);
t_ui32	ft_sqrtfloor(t_ui32 n);
/*
** Rounding and remainder functions:
*/
double	ft_ceil(double nb);
double	ft_floor(double nb);

int		ft_idiv_ceil(int n, int d);
int		ft_idiv_floor(int n, int d);
/*
** Floating-point manipulation functions:
*/
int		ft_dbltype(double nbr_ref);
/*
** Other:
*/
int		ft_abs(int i);

int		ft_subs(int n1, int n2);
int		ft_addi(int n1, int n2);
int		ft_mult(int n1, int n2);
int		ft_divi(int n1, int n2);
int		ft_modu(int n1, int n2);
t_ui64	ft_getbitarray(unsigned char *nbr, size_t first, size_t last);

/*
** -
** My default linked list manipulation functions
** -
*/
/*
** Add functions
*/
t_list	*ft_lstnew(void const *content, size_t content_size);
int		ft_lstpushfront(t_list **alst, t_list *new);
int		ft_lstpushback(t_list **alst, t_list *new);
int		ft_lstpushprev(t_list **alst, t_list *lst, t_list *new);
int		ft_lstpushnext(t_list **alst, t_list *lst, t_list *new);
t_list	*ft_lstnewfront(t_list **alst,
			void const *content, size_t content_size);
t_list	*ft_lstnewback(t_list **alst,
			void const *content, size_t content_size);
t_list	*ft_lstnewprev(t_list **alst, t_list *lst,
			void const *content, size_t content_size);
t_list	*ft_lstnewnext(t_list **alst, t_list *lst,
			void const *content, size_t content_size);
/*
** Delete functions
*/
void	ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void	ft_lstfreecont(void	*content, size_t content_size);
t_list	*ft_lstpullfirst(t_list **alst);
t_list	*ft_lstpulllast(t_list **alst);
t_list	*ft_lstpullprev(t_list **alst, t_list *lst);
t_list	*ft_lstpullcur(t_list **alst, t_list *lst);
t_list	*ft_lstpullnext(t_list *lst);
void	ft_lstdelfirst(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdellast(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdelprev(t_list **alst, t_list *lst, void (*del)(void*, size_t));
void	ft_lstdelcur(t_list **alst, t_list *lst, void (*del)(void*, size_t));
void	ft_lstdelnext(t_list *lst, void (*del)(void*, size_t));
void	ft_lstdelif(t_list **alst, void (*del)(void*, size_t),
			t_list *lst_ref, int(*cmp)(t_list *lst, t_list *lst_ref));
/*
** List modifications functions
*/
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void	ft_lstiterif(t_list *lst, void (*f)(t_list *elem),
			t_list *lst_ref, int(*cmp)(t_list *lst, t_list *lst_ref));
void	ft_lstrev(t_list **alst);
/*
** Search functions
*/
t_list	*ft_lstlast(t_list *alst);
t_list	*ft_lstat(t_list *alst, size_t nbr);
t_list	*ft_lstfind(t_list *alst,
			t_list *lst_ref, int(*cmp)(t_list *lst, t_list *lst_ref));
/*
** List creation functions
*/
t_list	*ft_lstdupone(t_list *lst);
t_list	*ft_lstdup(t_list *alst);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstparams(int ac, char **av);
/*
** Others
*/
size_t	ft_lstsize(t_list *lst);
void	ft_lstprntone(t_list *lst);
void	ft_lstprnt(t_list *lst);

/*
** -
** My default tables manipulation functions
** -
*/
/*
** Void* Tables
*/
int		ft_tabadd(void ***atab, void *new);
int		ft_tabaddm(void ***atab, void *new, size_t size);
t_tabdt	*ft_tabcc(void **requested);
size_t	ft_tabsize(void **tab);
int		ft_tabdel(void ***atab);
int		ft_tabdel2(void ***atab);
int		ft_tabdel3(void ***atab);
int		ft_tabdelf(void ***atab, void (*f)(void *c));
void	ft_tabsort(void **tab, int (*f)(const void *s1, const void *s2), int n);
/*
** Metatables
*/
t_metat	*ft_metacc(char *requested);
void	*ft_metaget(char *tabname, const void *key);
int		ft_metaset(char *tabname, void *(*f)(const void *k),
						int (*c)(const void *s1, const void *s2), size_t keysz);

/*
** Others
*/
size_t	ft_tblsize(void **tbl);

char	**ft_envgetp(const char **env, const char *key);
char	*ft_envget(const char **env, const char *key);
char	**ft_envupdate_m(char ***env, char *line);
char	**ft_envnew_m(char ***env, char *line);
char	**ft_envnew(char ***env, char *line);
int		ft_expand_tilde(const char *src, char *ref[3], char **ptr);
int		ft_expand_tilde_env(const char *src, const char **env, char **ptr);

/*
** -
** My custom debug functions
** -
*/
t_ui64	ft_getptri(void *ptr);
void	ft_myassert(int relation);
int		ft_myputnchar(char *str, int num);
void	*ft_memprint(void *p, size_t s);
int		qprintf(const char *format, ...);

#endif
