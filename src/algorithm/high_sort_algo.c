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


void radix(t_list **a, t_list **b, int size)
{
	int bit;
	int i;
	int max_bits;
	int max_index;

	bit = 0;
	max_bits = 0;
	max_index = size - 1;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	while (bit < max_bits)
	{
		i = 0;
		while (i++ < size)
		{
			if (((*a)->index >> bit) & 1)
				ft_rotate_a(a);
			else
				ft_push_b(a, b);
		}
		while (*b)
			ft_push_a(a, b);
		bit++;
	}
}



