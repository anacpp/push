/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/16 18:55:36 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_node_position(t_list **stack, t_list *node)
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

static void	send_min_to_b(t_list **stack_a, t_list **stack_b)
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
	send_min_to_b(stack_a, stack_b);
	ft_three_sort_algo(stack_a);
	ft_push_a(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
	return (0);
}

int	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	send_min_to_b(stack_a, stack_b);
	ft_three_sort_algo(stack_a);
	ft_push_a(stack_a, stack_b);
	return (0);
}
