/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/11 18:49:58 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*last_node;

	if (!stack || !*stack || !(*stack)->next_node)
		return ;
	last_node = *stack;
	prev = NULL;
	while (last_node->next_node)
	{
		prev = last_node;
		last_node = last_node->next_node;
	}
	prev->next_node = NULL;
	last_node->next_node = *stack;
	*stack = last_node;
}


int	ft_rev_rotate_a(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	return (1);
}

int	ft_rev_rotate_b(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	return (1);
}

int	ft_rev_rotate_ab(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	return (2);
}
