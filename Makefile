# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 16:34:37 by hulescur          #+#    #+#              #
#    Updated: 2026/02/10 19:24:57 by hulescur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/ft_atoi.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_split.c \

FT_PRINTF = printf/ft_printf.c printf/utils.c printf/utils2.c \

SRCS =	$(LIBFT) $(FT_PRINTF) src/main.c src/parser.c src/cleanup.c \
		src/stack.c src/sorttab.c src/ops.c src/radix.c \

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap
OBJS = $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
