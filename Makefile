# *************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madufour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 13:52:35 by madufour          #+#    #+#              #
#    Updated: 2019/03/20 13:57:45 by madufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC = main.c \
	  rt_draw.c rt_clear_img.c \
	  rt_close.c

INC = -I . -I libft/

LIB = -L ./libft -lft -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = $(SRC:.c=.o)

LIBFT_NAME = ./libft/libft.a

HEAD = libft/libft.h rtv1.h

CC = gcc

all: libft $(NAME)

libft:
	make -C libft/

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): Makefile $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB)

clean:
	make clean -C libft/
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all re libft
