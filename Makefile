# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yueli <yueli@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/20 11:32:37 by yueli             #+#    #+#              #
#    Updated: 2026/02/25 17:20:26 by yueli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./includes

SRC_DIRS = src
VPATH = $(SRC_DIRS)
SRCS =  main.c error_free_exit.c init_all.c read_map.c load_map.c \
		map_basic_check.c map_valid_check.c render_map.c close_window.c \
		handle_move.c handle_clctb_and_win.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = lib/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = lib/minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext -lXrandr -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re 