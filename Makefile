NAME = fdf
HEADER = fdf.h

PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = .src/libft/includes/

OBJ = $(SRCS:.c=.o)




SRCS = src/draw_lines.c         \
       src/keyboard_control.c   \
       src/main.c               \
       src/mouse_control.c      \
       src/rotate.c             \

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C src/libft
	make -C minilibx
	gcc -o $(NAME) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit src/libft/libft.a
	echo "Fdf done"

clean:
	make clean -C src/libft
	rm -f $(OBJ)
fclean: clean
	make fclean -C src/libft
	rm -f $(NAME)

re: fclean all
