/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/03 18:06:03 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_three_sort_algo(t_list **stack)
{
	int first;
	int middle;
	int last;
	int i;

	first = (*stack)->number;
	middle = (*stack)->next_node->number;
	last = (*stack)->next_node->next_node->number;
	i = 0;
	if (first > middle && middle < last && last > first)
		i += ft_swap_a(&stack);
	if (first > middle && middle > last && last < first)
	{
		i += ft_swap_a(&stack);
		i += ft_rev_rotate_a(&stack);
	}
	if (first > middle && middle < last && last < first)
		i += ft_rotate_a(&stack);
	if (first < middle && middle > last && last > first)
	{
		i += ft_swap_a(&stack);
		i += ft_rotate_a(&stack);
		return (i);
	}
	if (first < middle && middle > last && last < first)
		i += ft_rev_rotate_a(&stack);
	return (i);
}