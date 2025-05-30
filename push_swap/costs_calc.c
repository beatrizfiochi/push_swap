/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:26:46 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/27 18:35:21 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cost_rot_all(t_list *current_a, int size_list_a, int size_list_b)
{
	t_node	*node;
	t_node	*target_node;
	int		a_cost;
	int		target_cost;
	int		total_cost;

	(void)size_list_a;
	(void)size_list_b;
	node = (t_node *)(current_a->content);
	target_node = (t_node *)(node->tgt->content);
	a_cost = node->idx;
	target_cost = target_node->idx;
	if (a_cost >= target_cost)
		total_cost = a_cost;
	else
		total_cost = target_cost;
	return (total_cost);
}

static int	cost_rev_all(t_list *current_a, int size_list_a, int size_list_b)
{
	t_node	*node;
	t_node	*target_node;
	int		a_cost;
	int		target_cost;
	int		total_cost;

	node = (t_node *)(current_a->content);
	target_node = (t_node *)(node->tgt->content);
	a_cost = 0;
	target_cost = 0;
	if (node->idx != 0)
		a_cost = size_list_a - node->idx;
	if (target_node->idx != 0)
		target_cost = size_list_b - target_node->idx;
	if (a_cost >= target_cost)
		total_cost = a_cost;
	else
		total_cost = target_cost;
	return (total_cost);
}

static int	cost_rot_rev(t_list *current_a, int size_list_a, int size_list_b)
{
	t_node	*node;
	t_node	*target_node;
	int		a_cost;
	int		target_cost;
	int		total_cost;

	(void)size_list_a;
	node = (t_node *)(current_a->content);
	target_node = (t_node *)(node->tgt->content);
	a_cost = node->idx;
	target_cost = 0;
	if (target_node->idx != 0)
		target_cost = size_list_b - target_node->idx;
	total_cost = a_cost + target_cost;
	return (total_cost);
}

static int	cost_rev_rot(t_list *current_a, int size_list_a, int size_list_b)
{
	t_node	*node;
	t_node	*target_node;
	int		a_cost;
	int		target_cost;
	int		total_cost;

	(void)size_list_b;
	node = (t_node *)(current_a->content);
	target_node = (t_node *)(node->tgt->content);
	a_cost = 0;
	if (node->idx != 0)
		a_cost = size_list_a - node->idx;
	target_cost = target_node->idx;
	total_cost = a_cost + target_cost;
	return (total_cost);
}

int	cost(t_list *curr_a, t_list **a, t_list **b, t_cost *cheapest)
{
	int		sz_l_a;
	int		sz_l_b;
	int		cost;

	put_index(a);
	put_index(b);
	sz_l_a = ft_lstsize(*a);
	sz_l_b = ft_lstsize(*b);
	cheapest->cost = INT_MAX;
	cost = cost_rot_all(curr_a, sz_l_a, sz_l_b);
	if (cost < cheapest->cost)
		fill_cost(cheapest, curr_a, cost, OP_ROTATE);
	cost = cost_rev_all(curr_a, sz_l_a, sz_l_b);
	if (cost < cheapest->cost)
		fill_cost(cheapest, curr_a, cost, OP_REVERSE);
	cost = cost_rot_rev(curr_a, sz_l_a, sz_l_b);
	if (cost < cheapest->cost)
		fill_cost(cheapest, curr_a, cost, OP_ROT_REV);
	cost = cost_rev_rot(curr_a, sz_l_a, sz_l_b);
	if (cost < cheapest->cost)
		fill_cost(cheapest, curr_a, cost, OP_REV_ROT);
	return (cheapest->cost);
}
