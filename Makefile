# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 15:02:29 by moouali           #+#    #+#              #
#    Updated: 2024/05/25 22:12:48 by moouali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

PREFIX = ./Mandatory/

SOURCES = $(addprefix $(PREFIX), \
			main.c check.c exit.c check_path.c check_2.c \
			init_windows.c moves.c moves_2.c) \
			./utils/gnl/get_next_line.c ./utils/gnl/get_next_line_utils.c

INCLUDES = ./MLX42/build/libmlx42.a ./utils/printf/libftprintf.a \
			-Iinclude -lglfw -L"/Users/moouali/.brew/opt/glfw/lib/"

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c $(PREFIX)/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME) :  $(OBJECTS)
	@make -C ./utils/printf
	$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDES) -o $(NAME)

bonus: 
	@make -C ./Bonus
	@make clean
	
clean:
	rm -rf $(OBJECTS)
	@make clean -C ./utils/printf
	@make clean -C ./Bonus
	
fclean: clean
	rm -rf $(NAME)
	@make fclean -C ./utils/printf
	@make fclean -C ./Bonus

re: fclean all
	
.PHONY:  all clean fclean re bonus
