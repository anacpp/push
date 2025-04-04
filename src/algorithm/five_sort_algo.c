/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/03 16:31:47 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	send_min_to_b(t_list **stack_a, t_list *stack_b)
{
	t_list	*smallest_node;
	t_list	**current_node;

	smallest_node = find_smallest_node(stack_a);
	current_node = stack_a;
	while (current_node && current_node != smallest_node)
	{
		current_node = &((*current_node))->next_node;
		if (*current_node)
		{
			*current_node = (*current_node)->next_node;
			smallest_node->next_node = NULL;
		}
	}
	ft_push_a(&smallest_node, stack_b);
}

int	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	send_min_to_b(stack_a, stack_b);
	send_min_to_b(stack_a, stack_b);
	ft_three_sort_algo(stack_a);
	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	return (0);
}