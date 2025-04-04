/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/03 16:31:09 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_rotate(t_list **stack)
{
	t_list	*first_node;
	t_list	*current_node;

	if (!stack || !*stack)
		return ;
	first_node = *stack;
	current_node = *stack;
	*stack = (*stack)->next_node;
	while (current_node->next_node)
	{
		current_node = current_node->next_node;
	}
	current_node->next_node = first_node;
	first_node->next_node = NULL;
}

int	ft_rotate_a(t_list **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
	return (1);
}

int	ft_rotate_b(t_list **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
	return (1);
}

int	ft_rotate_ab(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
	return (2);
}
