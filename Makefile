# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 12:29:18 by skorotko          #+#    #+#              #
#    Updated: 2018/11/30 17:40:18 by vsarapin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
PATH_SRC = ./

CC = gcc
FlAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror -I $(PATH_SRC)
SRC =							$(PATH_SRC)change_coor.c \
								$(PATH_SRC)ft_strsplit.c \
								$(PATH_SRC)create_window.c \
								$(PATH_SRC)draw_lines.c \
								$(PATH_SRC)main.c \
								$(PATH_SRC)error_management.c \
								$(PATH_SRC)read_file.c \
								$(PATH_SRC)get_next_line.c \
								$(PATH_SRC)ft_strlen.c \
								$(PATH_SRC)ft_atoi.c \
								$(PATH_SRC)ft_isdigit.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(FlAGS) $(OBJ)	-o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
