/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_targets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:52:34 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/27 18:28:26 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_closest_smaller(t_node *a, t_list **stack_b)
{
	t_list	*b;
	t_node	*b_node;
	t_list	*closest;
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
				closest = b;
			}
		}
		b = b->next;
	}
	return (closest);
}

void	find_target_of_a_node(t_node *a, t_list **stack_b)
{
	t_list	*min;
	t_list	*max;

	min = find_min(stack_b);
	max = find_max(stack_b);
	if (a->nbr < ((t_node *)min->content)->nbr)
	{
		a->tgt = max;
		return ;
	}
	else
		a->tgt = find_closest_smaller(a, stack_b);
	return ;
}

static t_list	*find_closest_bigger(t_node *b, t_list **stack_a)
{
	t_list	*a;
	t_node	*a_node;
	t_list	*closest;
	int		small_diff;
	int		tmp_diff;

	a = *stack_a;
	closest = NULL;
	small_diff = INT_MAX;
	while (a != NULL)
	{
		a_node = (t_node *)(a->content);
		if (a_node->nbr > b->nbr)
		{
			tmp_diff = a_node->nbr - b->nbr;
			if (tmp_diff < small_diff)
			{
				small_diff = tmp_diff;
				closest = a;
			}
		}
		a = a->next;
	}
	return (closest);
}

void	find_target_of_b_node(t_node *b, t_list **stack_a)
{
	t_list	*min;
	t_list	*max;

	min = find_min(stack_a);
	max = find_max(stack_a);
	if (b->nbr > ((t_node *)max->content)->nbr)
	{
		b->tgt = min;
		return ;
	}
	else
		b->tgt = find_closest_bigger(b, stack_a);
	return ;
}
