/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/11 16:43:03 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int    count_nodes(t_list *stack)
{
    int counter;

    counter = 0;
    while (stack != NULL)
    {
        counter++;
        stack = stack->next_node;
    }
    return (counter);
}

t_list  *find_smallest_node(t_list **stack)
{
    t_list *min_node;
    t_list *current;

    if (!stack || !(*stack))
        handle_error(*stack, "Error.\n", 1); 
    min_node = *stack;
    current = *stack;
    while (current)
    {
        if (current->number < min_node->number)
            min_node = current;
        current = current->next_node;
    }
    return (min_node);
}

int	is_sorted(t_list **stack)
{
	while (stack && (*stack)->next_node)
	{
		if ((*stack)->number > (*stack)->next_node->number)
			return (0);
		stack = &(*stack)->next_node;
	}
	return (1);
}

