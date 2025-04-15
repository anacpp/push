/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/15 15:48:40 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(t_list *stack)
{
	t_list	*outer;
	t_list	*inner;

	outer = stack;
	while (outer)
	{
		inner = outer->next_node;
		while (inner)
		{
			if (outer->number == inner->number)
				return (1);
			inner = inner->next_node;
		}
		outer = outer->next_node;
	}
	return (0);
}

static int	convert_to_int(char *str, int *num)
{
	long	val;

	val = ft_atol(str);
	if (val < INT_MIN || val > INT_MAX)
		return (0);
	*num = (int)val;
	return (1);
}

static void	process_arg(char *arg, t_list **stack)
{
	char	**split_args;
	int		j;
	int		num;

	split_args = ft_split(arg, ' ');
	j = 0;
	if (!split_args)
		handle_error(*stack, "Error on spliting arguments.\n", 1);
	while (split_args[j])
	{
		if (!is_number(split_args[j]) || !convert_to_int(split_args[j], &num))
		{
			free_split(split_args);
			handle_error(*stack, "", 1);
		}
		add_to_stack(stack, num);
		j++;
	}
	free_split(split_args);
}

t_list	*parse_arguments(int argc, char **argv)
{
	t_list	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
		process_arg(argv[i++], &stack);
	if (has_duplicates(stack))
		handle_error(stack, "", 1);
	return (stack);
}
