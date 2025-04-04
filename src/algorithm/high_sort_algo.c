/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_sort_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/03 16:20:08 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_to_b_optimized(t_list **stack_a, t_list **stack_b, int pivot1,
		int pivot2)
{
	int	size;
	int	i;

	size = ft_stack_size(*stack_a);
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->number < pivot1)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if ((*stack_a)->number < pivot2)
		{
			pb(stack_a, stack_b);
		}
		else
		{
			ra(stack_a);
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
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	merge_stacks(t_list **stack_a, t_list **stack_b)
{
	int	max_index;

	while (*stack_b)
	{
		max_index = find_max_index(*stack_b);
		move_max_to_top(stack_b, max_index);
		pa(stack_a, stack_b);
	}
}
void	partition_and_move(t_list **stack_a, t_list **stack_b)
{
	int	pivot1;
	int	pivot2;
	int	size;

	size = stack_size(*stack_a);
	pivot1 = find_pivot1(*stack_a, size);
	pivot2 = find_pivot2(*stack_a, size);
	move_to_b_optimized(stack_a, stack_b, pivot1, pivot2);
}
