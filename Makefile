# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 19:01:15 by acesar-p          #+#    #+#              #
#    Updated: 2025/04/11 19:07:58 by acesar-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -Iinclude

SRC = \
	src/basic_operations/ft_reverse_rotate.c \
	src/basic_operations/ft_rotate.c \
	src/basic_operations/ft_swap.c \
	src/basic_operations/ft_push_a_b.c \
	src/algorithm/five_sort_algo.c \
	src/algorithm/high_sort_algo.c \
	src/algorithm/three_sort_algo.c \
	src/algorithm/two_algo.c \
	src/parce_functions/parce_func.c \
	src/utils/parce_utils/utils.c \
	src/utils/sorting_utils/sort_utils.c \
	src/utils/general_utils_2.c \
	src/utils/general_utils.c \
	src/main.c \
	src/push_swap.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "Linking done."

$(LIBFT):
	@echo "Building libft..."
	$(MAKE) -C $(LIBFT_DIR)
	@echo "libft built."

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning objects files..."
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing $(NAME)..."
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
