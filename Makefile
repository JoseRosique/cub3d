# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 11:38:25 by joslopez          #+#    #+#              #
#    Updated: 2024/01/08 19:42:31 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = Cub3D

PRINTF = LC_NUMERIC="en_US.UTF-8" printf

GCC_FLAG = -Wall -Wextra -Werror -Wno-deprecated-declarations

SRCS = ./srcs/mandatory/map.c \
	   ./srcs/mandatory/cub3d.c \
	   ./srcs/mandatory/utils.c \
	   ./srcs/mandatory/utils2.c \
	   ./srcs/mandatory/utils3.c \
	   ./srcs/mandatory/initializer.c \
	   ./srcs/mandatory/parser.c \
	   ./srcs/mandatory/parser_orientation.c \
	   ./srcs/mandatory/events.c \
	   ./srcs/mandatory/movement.c \
	   ./srcs/mandatory/display.c \
	   ./srcs/mandatory/free.c \
	   ./srcs/mandatory/controls.c \
	   ./srcs/mandatory/floor_ceil.c \
	   ./srcs/mandatory/raycasting.c \
	   ./srcs/mandatory/rendering.c \
	   ./srcs/mandatory/textures.c \
	   ./srcs/get_next_line/get_next_line.c \
	   ./srcs/get_next_line/get_next_line_utils.c \
	   ./srcs/mandatory/dot_conversion.c


OBJS = $(SRCS:.c=.o)

all: libft minilibx $(NAME)

libft:
	@make -C libft/

minilibx:
	@make -C srcs/minilibx/


%.o: %.c
	@$(CC) $(GCC_FLAG) -o $@ -c $^

$(NAME): $(OBJS)
	@$(CC) $(GCC_FLAG) -o $@ $^ -Lsrcs/minilibx/ -lmlx -framework OPENGL -framework Appkit -Llibft -lft
	@$(PRINTF) "\r%100s\r$(GREEN)Cub3d is up to date!$(DEFAULT)\n"

clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files in Cub3D...$(DEFAULT)\n"
	@rm -f $(OBJS)
	@make -Clibft/ clean
	@make -C srcs/minilibx/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@make -C srcs/minilibx/ clean
	@$(PRINTF) "$(CYAN)Removed Cub3D$(DEFAULT)\n"

re: fclean all

.PHONY: libft minilibx