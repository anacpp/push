/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/11 19:14:07 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_node_position(t_list **stack, t_list *node)
{
	t_list	*current;
	int		pos;

	current = *stack;
	pos = 0;
	while (current)
	{
		if (current == node)
			return (pos);
		current = current->next_node;
		pos++;
	}
	return (-1);
}

void	send_min_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest_node;
	int		pos;
	int		size;

	smallest_node = find_smallest_node(stack_a);
	pos = get_node_position(stack_a, smallest_node);
	size = ft_stack_size(*stack_a);
	if (pos <= size / 2)
	{
		while (*stack_a != smallest_node)
			ft_rotate_a(stack_a);
	}
	else
	{
		while (*stack_a != smallest_node)
			ft_rev_rotate_a(stack_a);
	}
	ft_push_b(stack_a, stack_b);
}

int	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	send_min_to_b(stack_a, stack_b);
	print_stack(*stack_a, "A depois do 1º send_min");
	print_stack(*stack_b, "B depois do 1º send_min");
	send_min_to_b(stack_a, stack_b);
	print_stack(*stack_a, "A depois do 2º send_min");
	print_stack(*stack_b, "B depois do 2º send_min");
	ft_three_sort_algo(stack_a);
	if (*stack_b && (*stack_b)->next_node
		&& (*stack_b)->number < (*stack_b)->next_node->number)
		ft_swap_b(stack_b);
	ft_push_a(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
	return (0);
}
