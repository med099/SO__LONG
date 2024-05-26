# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 15:02:29 by moouali           #+#    #+#              #
#    Updated: 2024/05/26 10:50:35 by moouali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = ../so_long_bonus

PREFIX = ./

SOURCES = $(addprefix $(PREFIX), \
			main_bonus.c check_bonus.c exit_bonus.c check_path_bonus.c check_2_bonus.c \
			init_windows_bonus.c moves_bonus.c moves_2_bonus.c move_enemy_bonus.c) \
			../utils/gnl/get_next_line.c ../utils/gnl/get_next_line_utils.c

INCLUDES = ../MLX42/build/libmlx42.a ../utils/printf/libftprintf.a \
			-Iinclude -lglfw -L"/Users/moouali/.brew/opt/glfw/lib/" \

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c $(PREFIX)/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME) :  $(OBJECTS)
	@make -C ../utils/printf
	$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDES) -o $(NAME)

clean:
	rm -rf $(OBJECTS)
	@make clean -C ../utils/printf
	
fclean: clean
	rm -rf $(NAME)
	@make fclean -C ../utils/printf

re: fclean all
	
.PHONY:  all clean fclean re bonus
