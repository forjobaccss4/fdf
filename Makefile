NAME = fdf
PATH_SRC = ./

CC = gcc
FLAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror -I $(PATH_SRC)

SRC = 			$(PATH_SRC)ft_strlen.c \
				$(PATH_SRC)ft_strcpy.c \
				$(PATH_SRC)ft_strsplit.c \
	 			$(PATH_SRC)count_file.c \
				$(PATH_SRC)ft_atoi.c \
				$(PATH_SRC)drow_lines.c \
				$(PATH_SRC)get_next_line.c \
				$(PATH_SRC)fdf_main.c \
				$(PATH_SRC)help_functions.c \



OBJ		= $(SRC:.c=.o)
				
all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
