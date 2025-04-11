/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_sort_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/11 19:06:47 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list *smallest;

	smallest = find_smallest_node(stack_a);
	send_min_to_b(stack_a, stack_b); 
	ft_push_a(stack_a, stack_b);
	return (0);
}