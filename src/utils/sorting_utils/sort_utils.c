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

int	find_pivot1(t_list *stack, int size)
{
	int	*arr;
	int	pivot;

	arr = stack_to_array(stack, size);
	quick_sort(arr, 0, size - 1);
	pivot = arr[size / 3];
	free(arr);
	return (pivot);
}
int	find_pivot2(t_list *stack, int size)
{
	int	*arr;
	int	pivot;

	arr = stack_to_array(stack, size);
	quick_sort(arr, 0, size - 1);
	pivot = arr[(2 * size) / 3];
	free(arr);
	return (pivot);
}

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
void	quick_sort(int *arr, int low, int high)
{
	int	pivot;
	
	if (low < high)
	{
		pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = (low - 1);
	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}
