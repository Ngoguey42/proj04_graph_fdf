#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 11:29:36 by ngoguey           #+#    #+#              #
#    Updated: 2015/01/09 12:52:24 by ngoguey          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NNAME = ft
NAME = lib$(NNAME).a

INCLUDE = ./includes
SRCPATH = srcs
PTFSRCPATH = $(SRCPATH)/printf
OBJPATH = obj

# CC = /bin/i686-w64-mingw32-gcc.exe
CC = gcc
BASEFLAGS = -Wall -Wextra
CFLAGS = $(BASEFLAGS) -Werror -O2
DEBUGFLAGS = $(BASEFLAGS) -g
LIB = ar rc
RM = rm -rf

Y = \033[0;33m
R = \033[0;31m
G = \033[0;32m
E = \033[39m

#SOURCES VARIABLES
COUNT = 0
TABLEN = 28
W = 0
OBJPERLINES = 4

#PRINTF SOURCES VARIABLES
PTFCOUNT = 0
PTFTABLEN = 34
X = 0
PTFOBJPERLINES = 3

#SOURCES
SRCSFILES =\
ft_putchar.c  ft_putstr.c ft_putnbr.c      ft_putendl.c\
ft_putnchar.c             ft_putnbr_base.c \
\
ft_atoi.c      ft_itoa_a.c ft_utoa.c ft_lutoa.c\
ft_atoi_base.c ft_itoa_c.c ft_itoa.c ft_lutoa_a.c\
\
ft_maxintlen.c  ft_revstr.c    evlxpr_calculate.c     evlxpr_list.c    ft_convsz.c\
ft_pad_string.c ft_eval_expr.c evlxpr_convert_chain.c                  ft_roundup_b10.c\
ft_memalloc.c   ft_strnew.c    ft_strdup.c            ft_strjoin.c     ft_strtrim.c\
ft_memdel.c     ft_strdel.c    ft_strsub.c            ft_strjoinfree.c ft_strsplit.c\
ft_realloc.c    ft_crealloc.c  ft_memdup.c                             ft_strsplit_s.c\
\
ft_isalnum.c ft_iscntrl.c      ft_islower.c ft_isspace.c  ft_tolower.c\
ft_isalpha.c ft_isdigit.c      ft_ispair.c  ft_isupper.c  ft_toupper.c\
ft_isascii.c ft_isdigit_base.c ft_isprint.c ft_isxdigit.c ft_isunixspace.c\
ft_isblank.c ft_isgraph.c      ft_ispunct.c ft_isescape.c \
\
ft_memcpy.c   ft_strcat.c     ft_memcmp.c  ft_memchr.c  ft_memset.c\
ft_memmove.c  ft_strncat.c    ft_strcmp.c  ft_strchr.c  ft_strlen.c\
ft_memccpy.c  ft_strlcat.c    ft_strncmp.c ft_strrchr.c ft_bzero.c\
ft_strcpy.c   ft_strcatfree.c ft_strequ.c  ft_strspn.c  ft_strclr.c\
ft_strncpy.c                  ft_strnequ.c ft_strcspn.c ft_strcharlen.c\
ft_strlcpy.c                  ft_match.c   ft_strstr.c  ft_striter.c\
ft_strccpy.c                  ft_voidcmp.c ft_strnstr.c ft_striteri.c\
ft_catpath.c                                            ft_strmap.c\
ft_filename.c get_next_line.c                           ft_strmapi.c\
ft_resolve_path.c ft_getcmdpath.c ft_getcmdpath_env.c ft_access.c\
ft_envget.c ft_envnew.c ft_expand_tilde_env.c ft_expand_tilde.c\
\
ft_lstnew.c       ft_lstdel.c       ft_lstiter.c   ft_lstdupone.c ft_lstlast.c\
ft_lstpushwhere.c ft_lstdelone.c    ft_lstiterif.c ft_lstdup.c    ft_lstat.c\
ft_lstnewwhere.c  ft_lstfreecont.c  ft_lstrev.c    ft_lstmap.c    ft_lstfind.c\
                  ft_lstpullwhere.c                ft_lstparams.c \
                  ft_lstdelwhere.c                                ft_lstsize.c\
                  ft_lstdelif.c                                   ft_lstprntone.c\
                                                                  ft_lstprnt.c\
\
ft_log10.c ft_powi.c      ft_ceil.c    ft_abs.c         \
ft_log16.c ft_sqrtfloor.c ft_floor.c   operations.c     \
ft_log2.c                 ft_dbltype.c ft_getbitarray.c ft_idiv.c\
\
ft_getptri.c ft_myassert.c ft_myputnchar.c ft_memprint.c qprintf.c ft_printvar.c\
\
ft_tabadd.c ft_tabcc.c ft_tabdel.c ft_tabsize.c ft_tabsort.c ft_tabadddebug.c\
ft_metacc.c ft_metaget.c ft_metaset.c ft_metagetdebug.c\
\
ft_clock_cc.c ft_clock_update.c

#PRINTF_SOURCES
PTFSRCSFILES = \
	ft_printf.c         build_integers.c            freemem.c\
	ft_getprintf.c      build_uppercases.c          build_dependencies.c\
	calc_return_value.c build_chars_and_strings.c   get_varg.c\
	parse_format.c      build_hex_float.c           buffer_printf.c\
	store_opt_1to5.c    build_hex_float_norm.c      buffer_flushcols.c\
	store_opt_6to8.c    build_hex_float_unnorm.c    buffer_flushcols_concat.c\
	add_color_flags.c   build_bonuses.c             ft_vprintf.c\
	add_color_tags.c    build_nonprintable_string.c buffer_table.c\
	debug.c             build_nonprintable_string_deps.c\
	                    build_uppercases2.c         buffer_flush_lscols.c\
	                    build_dec_float.c           buffer_lscols_getdatas.c\
	                    build_dec_float_nbr.c

#SOURCES/OBJECTS TARGETS
SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

#PRINTF SOURCES/OBJECTS TARGETS
PTFSRC = $(addprefix $(PTFSRCPATH)/,$(PTFSRCSFILES))
PTFOBJECTS = $(PTFSRC:$(PTFSRCPATH)/%.c=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(PTFOBJECTS)
	@printf "\n$(Y)%-6s$(E) $(NAME) $(R)$(OBJPATH)/%.o$(E)\n" "$(LIB)"
	@$(LIB) $(NAME) $(OBJECTS) $(PTFOBJECTS)
	@printf "$(Y)%-6s$(E) $(NAME)\n" "ranlib"
	@ranlib $(NAME)

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@if [ $(W) -eq 0 ] ; then printf "\n$(Y)%-6s$(E) -o $(R)$(OBJPATH)/%%.o$(E) $(CFLAGS) -I $(INCLUDE) -c $(SRCPATH)/%%.c\n" "$(CC)" ; fi
	$(eval W = 1)
	$(eval COUNT = $(shell echo "($(COUNT) + 1) % $(OBJPERLINES)" | bc))
	 @#printf "$(R)%-*s$(E)" $(TABLEN) "$@"
	@if [ $(COUNT) -eq 0 ] ; then printf "$(R)%s$(E)\n" "$@" ; else printf "$(R)%-*s$(E)" $(TABLEN) "$@" ; fi
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(CFLAGS) -I $(INCLUDE) -c $<

$(PTFOBJECTS): $(OBJPATH)/%.o : $(PTFSRCPATH)/%.c
	@if [ $(X) -eq 0 ] ; then printf "\n$(Y)%-6s$(E) -o $(R)$(OBJPATH)/%%.o$(E) $(CFLAGS) -I $(INCLUDE) -c $(PTFSRCPATH)/%%.c\n" "$(CC)" ; fi
	$(eval X = 1)
	$(eval PTFCOUNT = $(shell echo "($(PTFCOUNT) + 1) % $(PTFOBJPERLINES)" | bc))
	@if [ $(PTFCOUNT) -eq 0 ] ; then printf "$(G)%s$(E)\n" "$@" ; else printf "$(G)%-*s$(E)" $(PTFTABLEN) "$@" ; fi
	@mkdir -p $(dir $@)
	@$(CC) -o $@  $(CFLAGS) -I $(INCLUDE) -c $<

clean:
	@printf "$(Y)%-6s$(E) $(OBJPATH)\n" "$(RM)"
	@$(RM) $(OBJPATH)

fclean: clean
	@printf "$(Y)%-6s$(E) $(NAME)\n" "$(RM)"
	@$(RM) $(NAME)

re: fclean all

_g:
	$(eval CFLAGS = $(DEBUGFLAGS))

g: _g all

gre: _g re
