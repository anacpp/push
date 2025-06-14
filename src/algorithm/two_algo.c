/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-p <acesar-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:26 by acesar-p          #+#    #+#             */
/*   Updated: 2025/04/11 16:30:04 by acesar-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_two_sort(t_list **stack)
{
	if (is_sorted(stack))
		return ;
	else
		ft_swap_a(stack);
}
