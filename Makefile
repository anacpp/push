# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 19:01:15 by acesar-p          #+#    #+#              #
#    Updated: 2025/04/03 17:02:05 by acesar-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT_DIR = libft
INCLUDE = -I$(LIBFT_DIR) -Iinclude

LIBFT_SRC = $(LIBFT_DIR)/libft.a

SRC = src/basic_operations/ft_reverse_rotate.c src/basic_operations/ft_rotate.c src/basic_operations/ft_swap.c src/basic_operations/ft_push_a_b.c \
		src/algorithm/five_sort_algo.c src/algorithm/high_sort_algo.c src/algorithm/three_sort_algo.c src/algorithm/two_algo.c \
		src/parce_functions/parce_func.c src/utils/parce_utils/utils.c src/utils/sorting_utils/sort_utils_2.c \
		src/utils/sorting_utils/sort_utils.c src/utils/general_utils_2.c src/utils/general_utils.c src/main.c \
		src/push_swap.c

OBJ = $(SRC:.c=.o)
DIRS = $(sort $(dir $(OBJ)))

all: $(LIBFT_SRC) $(NAME)

$(NAME): create_dirs $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_SRC) -o $(NAME)

create_dirs:
	@mkdir -p $(DIRS)

$(LIBFT_SRC):
	make -C $(LIBFT_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re create_dirs

