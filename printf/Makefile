# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marianof <marianof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 10:09:25 by marianof          #+#    #+#              #
#    Updated: 2023/11/03 13:29:38 by marianof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_putchar_p.c ft_putstr_p.c ft_putnbr_p.c \
		ft_puthexmay_p.c ft_puthexmin_p.c ft_putnbr_un_p.c \
		ft_putp_p.c \

CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM = rm -rf
CC = gcc


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
