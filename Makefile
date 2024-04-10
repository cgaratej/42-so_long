# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 11:32:58 by cgaratej          #+#    #+#              #
#    Updated: 2024/04/10 10:55:48 by cgaratej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = inc/libft/libft.a
LIBFT_MAKE = make --no-print-directory -C inc/libft
MINILIBX =	minilibx/libmlx.a
MINILIBX_MAKE =  make --no-print-directory -C minilibx

NAME = so_long
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -L./minilibx
INCLUDE = Makefile
CC = gcc
RM = rm -f
OBJ_DIR= obj/

GREEN=\033[0;32m
ORANGE=\033[33m
RED = \033[1;91m
NONE=\033[0m

SRC = src/main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft minilib $(OBJ) $(INCLUDE)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT) $(MINILIBX) $(SRC) -o $(NAME)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	@echo "$(GREEN)File $< compiled ✔$(NONE)"

libft:
	@echo "$(ORANGE)\nCompilando libft$(NONE)"
	@$(LIBFT_MAKE)

minilib:
	@echo "\nCompilando minilib"
	@$(MINILIBX_MAKE)

clean:
	@$(RM) $(OBJ)
	@$(LIBFT_MAKE) clean
	@$(MINILIBX_MAKE) clean
	@echo "$(RED)Deleted .o files$(NONE)"
	
fclean: clean
	@$(RM) $(NAME)
	@$(LIBFT_MAKE) fclean
	@echo "$(RED)$(NAME) Deleted$(NONE)"

re: fclean all

.PHONY: all clean fclean re libft minilib