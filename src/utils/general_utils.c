/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/15 15:44:37 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	handle_error(t_list *stack, char *msg, int code)
{
	if (msg)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, msg, ft_strlen(msg));
	}
	if (stack)
		free_stack(stack);
	exit(code);
}

t_list	*new_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		handle_error(NULL, "Fail memmory allocation\n", 1);
	node->number = value;
	node->index = 0;
	node->next_node = NULL;
	return (node);
}

void	add_to_stack(t_list **stack, int value)
{
	t_list	*new;
	t_list	*temp;

	new = new_node(value);
	temp = *stack;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	while (temp->next_node)
		temp = temp->next_node;
	temp->next_node = new;
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next_node;
		free(temp);
	}
}

int	ft_stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next_node;
	}
	return (size);
}
