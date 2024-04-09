# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 11:32:58 by cgaratej          #+#    #+#              #
#    Updated: 2024/04/09 15:20:10 by cgaratej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_MAKE= make --no-print-directory -C libft
LIBFT= int/libft/libft.a

NAME = so_long
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -L./minilibx
INCLUDE = Makefile
CC = gcc
RM = rm -f
OBJ_DIR= obj/

GREEN=\033[0;32m
NONE=\033[0m

SRC = src/main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJ) $(INCLUDE)
	@$(FLGS) $(MLXFLAGS) $(SRCS) -o $(NAME)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	@echo "$(GREEN)File $< compiled ✔$(NONE)"

libft:
	$(LIBFT_MAKE)

clean:
	@$(RM) $(OBJ)
	@$(LIBFT_MAKE) clean
	@echo "$(RED)Deleted .o files$(NONE)"
	
fclean: clean
	$(RM) $(NAME)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re libft