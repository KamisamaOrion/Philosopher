# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 13:55:03 by mhervoch          #+#    #+#              #
#    Updated: 2024/03/19 22:51:03 by mhervoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

SRCS =	./philosopher.c \

HEAD =	philosopher.h

OBJS = $(SRCS:.c=.o)

all:$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I ./  -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lm

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean re
