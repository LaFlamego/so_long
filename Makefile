# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yueli <yueli@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/20 11:32:37 by yueli             #+#    #+#              #
#    Updated: 2026/02/27 12:12:52 by yueli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./includes

SRC_DIRS = src
VPATH = $(SRC_DIRS)
SRCS =  main.c error_free_exit.c init_all.c read_map.c load_map.c \
		map_basic_check.c map_valid_check.c render_map.c close_window.c \
		handle_move_and_key.c handle_events.c load_sprites.c clear_exit.c\

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = lib/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = lib/minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext -lXrandr -lm
MLX_LIB_FILE = $(MLX_DIR)/libmlx.a

BONUS_NAME = so_long_bonus
BONUS_SRC = bonus/main_bonus.c bonus/anm_move_bonus.c bonus/tiles_map_bonus.c
BONUS_OBJ = bonus/main_bonus.o bonus/anm_move_bonus.o bonus/tiles_map_bonus.o

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB_FILE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)

OBJS_NO_MAIN = $(filter-out main.o, $(OBJS))

$(BONUS_NAME): $(BONUS_OBJ) $(OBJS_NO_MAIN) $(LIBFT_LIB) $(MLX_LIB_FILE)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJS_NO_MAIN) $(LIBFT_LIB) $(MLX_LIB) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MLX_LIB_FILE):
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJS)
	rm -f $(BONUS_OBJ) clean
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus