/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/15 16:15:40 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_sort_thr(t_list **stack, int first, int middle, int last)
{
	int	i;

	i = 0;
	if (first > middle && middle < last && last > first)
		i += ft_swap_a(stack);
	else if (first > middle && middle > last && last < first)
	{
		i += ft_swap_a(stack);
		i += ft_rev_rotate_a(stack);
	}
	else if (first > middle && middle < last && last < first)
		i += ft_rotate_a(stack);
	else if (first < middle && middle > last && last > first)
	{
		i += ft_swap_a(stack);
		i += ft_rotate_a(stack);
	}
	else if (first < middle && middle > last && last < first)
		i += ft_rev_rotate_a(stack);
	return (i);
}

int	ft_three_sort_algo(t_list **stack)
{
	int	first;
	int	middle;
	int	last;

	first = (*stack)->number;
	middle = (*stack)->next_node->number;
	last = (*stack)->next_node->next_node->number;
	ft_sort_thr(stack, first, middle, last);
	return (0);
}
