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

static int	find_max_index(t_list *stack)
{
	int max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next_node;
	}
	return max;
}

static int	find_position(t_list *stack, int index)
{
	int pos = 0;
	while (stack)
	{
		if (stack->index == index)
			break;
		pos++;
		stack = stack->next_node;
	}
	return pos;
}

static void push_chunk_elements(t_list **a, t_list **b, int chunk_min, int chunk_max, int chunk_size)
{
    int count; 
    int i;
	int idx; 

	count = ft_stack_size(*a);
	i = 0;
    while (i < count)
    {
        idx = (*a)->index;

        if (idx >= chunk_min && idx < chunk_max)
        {
            ft_push_b(a, b);
            if (idx < chunk_min + (chunk_size / 2))
                ft_rotate_b(b);
        }
        else
			ft_rotate_a(a);
        i++;
    }
}

void push_chunks(t_list **a, t_list **b, int size, int chunks)
{
    int chunk_size; 
    int current;
	int chunk_min;
	int chunk_max;

	chunk_size = size / chunks;
	current = 0;
    while (current < chunks)
    {
        chunk_min = current * chunk_size;
        chunk_max = (current + 1) * chunk_size;
        push_chunk_elements(a, b, chunk_min, chunk_max, chunk_size);
        current++;
    }
}

void	return_chunks(t_list **a, t_list **b)
{
	while (*b)
	{
		int max;
		int pos;

		max = find_max_index(*b);
		pos = find_position(*b, max);
		if (pos <= ft_stack_size(*b) / 2)
			while ((*b)->index != max)
				ft_rotate_b(b);
		else
			while ((*b)->index != max)
				ft_rev_rotate_b(b);
		ft_push_a(a, b);
	}
}
