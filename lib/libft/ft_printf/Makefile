# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yueli <yueli@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 14:15:09 by yueli             #+#    #+#              #
#    Updated: 2026/02/02 16:12:48 by yueli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I .
SRCS = ft_print_char.c ft_print_int.c ft_print_string.c ft_print_usint.c \
		ft_print_pointer.c ft_print_hexa_low.c ft_print_hexa_upper.c ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
	
