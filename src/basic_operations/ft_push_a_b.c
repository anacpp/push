/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/15 15:43:51 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_node(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next_node;
	temp->next_node = *stack_b;
	*stack_b = temp;
}

int	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	push_node(stack_b, stack_a);
	write(1, "pa\n", 3);
	return (1);
}

int	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	push_node(stack_a, stack_b);
	write(1, "pb\n", 3);
	return (1);
}
