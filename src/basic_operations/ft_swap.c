/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/03 16:31:19 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_node(t_list **stack)
{
	int	temp;

	if (!stack || *stack == NULL || (*stack)->next_node == NULL)
		return ;
	temp = (*stack)->number;
	(*stack)->number = (*stack)->next_node->number;
	(*stack)->next_node->number = temp;
	temp = (*stack)->index;
	(*stack)->index = (*stack)->next_node->index;
	(*stack)->next_node->index = temp;
}

int	ft_swap_a(t_list **stack_a)
{
	if ((*stack_a) && count_nodes < 2)
		return ;
	swap_node(stack_a);
	write(1, "sa\n", 3);
	return (1);
}

int	ft_swap_b(t_list **stack_b)
{
	if ((*stack_b) && count_nodes < 2)
		return ;
	swap_node(stack_b);
	write(1, "sb\n", 3);
	return (1);
}

int	ft_swap_ab(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b && count_nodes(stack_a) < 2
		&& count_nodes(stack_b) < 2)
		return ;
	swap_node(stack_a);
	swap_node(stack_b);
	write(1, "ss\n", 3);
	return (2);
}