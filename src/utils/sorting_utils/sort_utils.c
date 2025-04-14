/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/11 16:36:54 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/push_swap.h"

int	*stack_to_array(t_list *stack, int size)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i++] = stack->number;
		stack = stack->next_node;
	}
	return (arr);
}

void index_stack(t_list *stack)
{
	t_list *current;
	t_list *compare;
	int index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->number < current->number)
				index++;
			compare = compare->next_node;
		}
		current->index = index;
		current = current->next_node;
	}
}



