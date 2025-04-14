/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/11 19:15:18 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				number;
	int				index;
	struct s_list	*next_node;
}					t_list;

// auxiliar operations
int					count_nodes(t_list *stack);
int					is_sorted(t_list **stack);
t_list				*find_smallest_node(t_list **stack);
void				free_split(char **split);
void				free_stack(t_list *stack);
void				handle_error(t_list *stack, char *msg, int code);
t_list				*new_node(int value);
int					ft_stack_size(t_list *stack);
void				add_to_stack(t_list **stack, int value);
void				print_stack(t_list *stack, char *name);
void 				index_stack(t_list *stack);

// algorithm functions
void				ft_two_sort(t_list **stack);
int					ft_sort_five(t_list **stack_a, t_list **stack_b);
int					ft_sort_four(t_list **stack_a, t_list **stack_b);
int					ft_three_sort_algo(t_list **stack);
void 				radix(t_list **a, t_list **b, int size);

// parce functions
t_list				*parse_arguments(int argc, char **argv);

// push function
void				push_swap(t_list **stack_a, t_list **stack_b);

// basic operations
int					ft_swap_a(t_list **stack_a);
int					ft_swap_b(t_list **stack_b);
int					ft_swap_ab(t_list **stack_a, t_list **stack_b);
int					ft_push_a(t_list **stack_a, t_list **stack_b);
int					ft_push_b(t_list **stack_a, t_list **stack_b);
int					ft_rotate_a(t_list **stack_a);
int					ft_rotate_b(t_list **stack_b);
int					ft_rotate_ab(t_list **stack_a, t_list **stack_b);
int					ft_rev_rotate_a(t_list **stack_a);
int					ft_rev_rotate_b(t_list **stack_b);
int					ft_rev_rotate_ab(t_list **stack_a, t_list **stack_b);
void				ft_two_sort(t_list **stack);
int					ft_sort_five(t_list **stack_a, t_list **stack_b);
int					ft_three_sort_algo(t_list **stack);



void print_stack(t_list *stack, char *name);
#endif
