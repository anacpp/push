/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:55:33 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/15 15:44:41 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		handle_error(NULL, NULL, 0);
	if (!has_valid_numbers(argv))
		handle_error(NULL, " ", 1);
	stack_a = parse_arguments(argc, argv);
	index_stack(stack_a);
	push_swap(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
