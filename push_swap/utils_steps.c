/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:44:21 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/28 20:46:46 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op_c(t_list **stack, void (*func)(t_list **, bool), int cost, int p)
{
	cost = cost - p;
	while (cost > 0)
	{
		func(stack, true);
		cost--;
	}
	return ;
}

int	cost_utils(t_list **stack, int index)
{
	int	cost;

	cost = 0;
	if (index != 0)
		cost = ft_lstsize(*stack) - index;
	return (cost);
}
