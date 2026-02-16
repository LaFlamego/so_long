# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yueli <yueli@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 13:40:41 by yueli             #+#    #+#              #
#    Updated: 2025/12/05 16:14:55 by yueli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I .
SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.cc
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re