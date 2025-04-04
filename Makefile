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

NAME = push_swap.a

SRC = src/basic_operation/ft_reverse_rotate.c src/basic_operation/ft_rotate.c src/basic_operation/ft_swap.c src/basic_operation/ft_push_a_b.c \
		src/algorithm/five_sort_algo.c src/algorithm/high_sort_algo.c src/algorithm/three_sort_algo.c src/algorithm/two_sort_algo.c\
		src/parce_functions/parce_func.c src/utils/parce_utils/utils.c src/utils/sorting_utils/sort_utils_2.c \
		src/utils/sorting_utils/sort_utils.c src/utils/general_utils_2.c src/utils/general_utils.c src/main.c 

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	
.c.o: 
	$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm -rf $(OBJ) $(OBJBON)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re