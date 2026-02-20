# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yueli <yueli@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 14:37:13 by yueli             #+#    #+#              #
#    Updated: 2026/02/20 11:45:33 by yueli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC_DIRS = ft_printf get_next_line
VPATH = $(SRC_DIRS)
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strnb.c\
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c ft_ends_with.c\
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_print_char.c ft_print_hexa_low.c ft_print_hexa_upper.c ft_print_int.c ft_print_pointer.c \
		ft_print_string.c ft_print_usint.c ft_printf.c \
		get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

PRINTF_DIR = ft_printf/
PRINTF_LIB = $(PRINTF_DIR)/printf.a

GNL_DIR = get_next_line/
GNL_LIB = $(GNL_DIR)/get_next_line.a

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB) $(GNL_LIB)
	ar rcs $(NAME) $(OBJS) $(PRINTF_LIB) $(GNL_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

clean:
	rm -rf $(OBJS)
	make -C $(PRINTF_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(GNL_DIR) clean

re: fclean all

.PHONY: all clean fclean re
