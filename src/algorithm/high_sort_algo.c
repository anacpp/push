/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_sort_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/11 16:56:22 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_to_b_optimized(t_list **stack_a, t_list **stack_b, int pivot1, int pivot2)
{
	int	size;
	int	i;

	size = ft_stack_size(*stack_a);
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->number < pivot1)
		{
			ft_push_b(stack_a, stack_b);
			ft_rotate_b(stack_b);
		}
		else if ((*stack_a)->number < pivot2)
		{
			ft_push_b(stack_a, stack_b);
		}
		else
		{
			ft_rotate_a(stack_a);
		}
		i++;
	}
}
void	move_max_to_top(t_list **stack_b, int max_index)
{
	int	pos;
	int	size;

	size = ft_stack_size(*stack_b);
	pos = find_position(*stack_b, max_index);
	while ((*stack_b)->index != max_index)
	{
		if (pos < size / 2)
			ft_rotate_b(stack_b);
		else
			ft_rev_rotate_b(stack_b);
	}
}

void	merge_stacks(t_list **stack_a, t_list **stack_b)
{
	int	max_index;

	while (*stack_b)
	{
		max_index = find_max_index(*stack_b);
		move_max_to_top(stack_b, max_index);
		ft_push_a(stack_a, stack_b);
	}
}
void	partition_and_move(t_list **stack_a, t_list **stack_b)
{
	int	pivot1;
	int	pivot2;
	int	size;

	size = ft_stack_size(*stack_a);
	pivot1 = find_pivot1(*stack_a, size);
	pivot2 = find_pivot2(*stack_a, size);
	move_to_b_optimized(stack_a, stack_b, pivot1, pivot2);
}
