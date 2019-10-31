NAME = rtv1

OBJ := $(subst src,.obj,$(subst .c,.o,$(wildcard src/*.c)))

CXX := gcc
INCLUDES :=  -I include -I libft/include 
FLAGS := -Wall -Wextra -Werror # -Weverything
LIB := -L libft -lft
LIB := $(LIB) -lm
LIB := $(LIB) -lmlx -framework OpenGL -framework AppKit

CXXFLAGS := $(INCLUDES) $(FLAGS) -MD

all : $(NAME)

$(NAME): .obj $(OBJ)
	$(MAKE) -C libft
	$(CXX) $(OBJ) -o $@ $(LIB)

libft:
	$(MAKE) -C libft

.obj:
	mkdir .obj

.obj/%.o: src/%.c
	$(CXX) -o $@ -c $< $(CXXFLAGS)

#add dependencies files (*.d)
DEP_FILES = $(SRC:%.c=%.d)
-include $(DEP_FILES)

clean:
	$(MAKE) clean -C libft
	rm -rf .obj

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
