# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 11:28:01 by cmaxime           #+#    #+#              #
#    Updated: 2019/01/29 14:22:09 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PRINTF = ft_printf.c \
		ft_realloc_mem.c \
		pf_arg_arg.c \
		pf_arg_chr.c \
		pf_arg_def.c \
		pf_arg_flt.c \
		pf_arg_int.c \
		pf_arg_ptr.c \
		pf_arg_str.c \
		pf_arg_uint.c \
		pf_arg_uint2.c \
		pf_collapse_buff.c \
		pf_core_parse.c \
		pf_declarations.c \
		pf_exception_zero.c \
		pf_init_t_print.c \
		pf_ltoa.c \
		pf_op1.c \
		pf_op2.c \
		pf_precision.c \
		pf_size.c \
		pf_t_print_cleaning.c \
		pf_va_arg.c \
		pf_wchar_to_char.c

BASIC = ft_atof.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_dabs.c \
		ft_degal.c \
		ft_deltab.c \
		ft_ftoa.c \
		ft_in.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_list_pushback.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_newmatrix.c \
		ft_pow.c \
		ft_powof.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_realloc.c \
		ft_round.c \
		ft_sqrtof.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tablen.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_ulstadd_head.c \
		ft_ulstadd_tail.c \
		ft_ulstdel.c \
		ft_ulstdelone.c \
		ft_ulstnew.c \
		ft_ulstset_head.c \
		ft_ulstset_tail.c \
		ft_ulstsize.c \
		ft_ulsttsize.c \
		get_next_line.c

ALGEBRE = ft_addmatrix.c \
		ft_addvector.c \
		ft_crossproductvector.c \
		ft_fillvector.c \
		ft_getvalmatrix.c \
		ft_matrixdel.c \
		ft_matrixnew.c \
		ft_multmatrix.c \
		ft_multvector.c \
		ft_scalarproductmatrix.c \
		ft_scalarproductvector.c \
		ft_setvalmatrix.c \
		ft_setvalvector.c \
		ft_vectordel.c \
		ft_vectornew.c

OBJBASIC = $(BASIC:%.c=.obj/%.o)
OBJPRINTF = $(PRINTF:%.c=.obj/%.o)
OBJALGEBRE = $(ALGEBRE:%.c=.obj/%.o)

OBJS = $(OBJBASIC) $(OBJPRINTF) $(OBJALGEBRE)

DEPS = ./Makefile \
	   ./include/libft.h

INCLUDE = -I include
GCC = gcc
FLAG = -Wall -Wextra -Werror -Weverything

# Formating
NORMAL=\x1b[0m
BOLD=\x1b[40m\x1b[1m

all: $(NAME)

$(NAME): .obj $(OBJS) $(DEPS)
	ar rc $(NAME) $(OBJS)
	@echo "$(BOLD)[ $(NAME) ] compiled$(NORMAL)"

.obj:
	mkdir .obj

.obj/%.o: basic/%.c
	$(GCC) $(INCLUDE) -c $< -o $@ $(FLAG)

.obj/%.o: printf/%.c
	$(GCC) $(INCLUDE) -c $< -o $@ $(FLAG)

.obj/%.o: algebre/%.c
	$(GCC) $(INCLUDE) -c $< -o $@ $(FLAG)

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re target
