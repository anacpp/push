/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:55:33 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/11 19:09:58 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (is_sorted(stack_a) || size <= 1)
		handle_error(*stack_a, NULL, 0);
	if (size == 2)
		ft_two_sort(stack_a);
	else if (size == 3)
		ft_three_sort_algo(stack_a);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (size == 5)
		ft_sort_five(stack_a, stack_b);
	else if (size > 5)
	{
		push_chunks(stack_a, stack_b, size, 5);
		return_chunks(stack_a, stack_b);
	}
	
}
