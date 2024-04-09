# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 11:06:32 by cgaratej          #+#    #+#              #
#    Updated: 2024/02/05 15:25:15 by cgaratej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRC=ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_strlen.c \
	ft_putnbr.c \
	ft_putnbr_nosig.c \
	ft_puthex.c \
	ft_putmem.c

GREEN=\033[0;32m

OBJ=$(SRC:.c=.o)

CC=cc

CFLGS=-Wall -Wextra -Werror

LIB=ar rcs

INCLUDE=Makefile ft_printf.h

RM=rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)
	@echo "\n$(GREEN)Create $(NAME) ✔\n"

%.o: %.c $(INCLUDE)
	$(CC) $(CFLGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY=all clean fclean re