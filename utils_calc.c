/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:59:19 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/27 17:15:01 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_list **stack)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *stack;
	while (current != NULL)
	{
		((t_node *)(current->content))->idx = i;
		i++;
		current = current->next;
	}
	return ;
}

void	fill_cost(t_cost *cost_op, t_list *current, int cost, int op)
{
	cost_op->operation = op;
	cost_op->cost = cost;
	cost_op->cheapest = current;
}

int	median(t_list **stack)
{
	int		lst_size;
	int		median;
	t_list	*current;

	current = *stack;
	lst_size = ft_lstsize(current);
	median = lst_size / 2;
	return (median);
}
