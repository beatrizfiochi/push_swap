/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_targets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:52:34 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/21 17:16:14 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_closest_smaller(t_node *a, t_list **stack_b)
{
	t_list	*b;
	t_node	*b_node;
	t_node	*closest;
	int		small_diff;
	int		tmp_diff;

	b = *stack_b;
	closest = NULL;
	small_diff = INT_MAX;
	while (b != NULL)
	{
		b_node = (t_node *)(b->content);
		if (b_node->nbr < a->nbr)
		{
			tmp_diff = a->nbr - b_node->nbr;
			if (tmp_diff < small_diff)
			{
				small_diff = tmp_diff;
				closest = b_node;
			}
		}
		b = b->next;
	}
	return (closest);
}

void	find_target_of_a_node(t_node *a, t_list **stack_b)
{
	t_node	*min;
	t_node	*max;

	min = find_min(stack_b);
	max = find_max(stack_b);
	if (a->nbr < min->nbr)
	{
		a->target = max;
		return ;
	}
	else
		a->target = find_closest_smaller(a, stack_b);
	return ;
}
