# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madufour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 23:15:01 by madufour          #+#    #+#              #
#    Updated: 2019/03/14 14:10:29 by madufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
	  ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c\
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c\
	  ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	  ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c ft_realloc.c ft_concat.c ft_lstpushback.c ft_putnbr_base.c \
	  ft_swap.c ft_lst_size.c ft_lst_at.c ft_lst_reverse.c ft_lst_find.c \
	  get_next_line.c ft_strjoin_free.c ft_power.c ft_f_abs.c
HEADER = libft.h
FLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = $(SRC:.c=.o)
DEPENDENCIES = Makefile libft.h

all: $(NAME)

$(NAME): $(OBJS) $(DEPENDENCIES)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I $(HEADER)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all re
