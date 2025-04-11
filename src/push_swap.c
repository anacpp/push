/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:55:33 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/03 17:03:31 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (is_sorted(*stack_a) || size <= 1)
		return ;
	if (size == 2)
		ft_two_sort(stack_a);
	else if (size == 3)
		ft_three_sort_algo(stack_a);
	else if (size <= 5)
		ft_sort_five(stack_a, stack_b);
	else
	{
		partition_and_move(stack_a, stack_b);
		ft_three_sort_algo(stack_a);
		merge_stacks(stack_a, stack_b);
	}
}
