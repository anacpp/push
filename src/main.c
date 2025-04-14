/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:55:33 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/11 19:14:48 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_list *stack, char *name)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", stack->number);
		stack = stack->next_node;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		handle_error(NULL, NULL, 0);
	stack_a = parse_arguments(argc, argv);
	index_stack(stack_a);
	push_swap(&stack_a, &stack_b);
	print_stack(stack_a, "Stack A");
	print_stack(stack_b, "Stack B");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}


