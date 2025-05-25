/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:33:59 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/28 20:49:16 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	step_rt(t_cost *cheap_cost, t_list **a, t_list *target, t_list **b)
{
	int		cheapest_node_cost;
	int		target_cost;
	int		performed_op;
	int		min;
	t_list	*cheapest_node;

	min = 0;
	cheapest_node = cheap_cost->cheap;
	cheapest_node_cost = ((t_node *)(cheapest_node->content))->idx;
	target_cost = ((t_node *)(target->content))->idx;
	performed_op = 0;
	if (cheapest_node_cost <= target_cost)
		min = cheapest_node_cost;
	if (target_cost < cheapest_node_cost)
		min = target_cost;
	while (min > 0)
	{
		rr(a, b, true);
		min--;
		performed_op++;
	}
	if (cheapest_node_cost > target_cost)
		do_op_c(a, ra, cheapest_node_cost, performed_op);
	if (cheapest_node_cost < target_cost)
		do_op_c(b, rb, target_cost, performed_op);
}

static void	step_rv(t_cost *cheap_cost, t_list **a, t_list *target, t_list **b)
{
	int		cheap_node_cost;
	int		target_cost;
	int		performed_op;
	int		min;
	t_list	*chp_nd;

	min = 0;
	chp_nd = cheap_cost->cheap;
	cheap_node_cost = cost_utils(a, ((t_node *)(chp_nd->content))->idx);
	target_cost = cost_utils(b, ((t_node *)(target->content))->idx);
	performed_op = 0;
	if (cheap_node_cost <= target_cost)
		min = cheap_node_cost;
	if (target_cost < cheap_node_cost)
		min = target_cost;
	while (min > 0)
	{
		rrr(a, b, true);
		min--;
		performed_op++;
	}
	if (cheap_node_cost > target_cost)
		do_op_c(a, rra, cheap_node_cost, performed_op);
	if (cheap_node_cost < target_cost)
		do_op_c(b, rrb, target_cost, performed_op);
}

static void	step_rt_rv(t_cost *cheap_cost, t_list **a, t_list *tgt, t_list **b)
{
	int		cheapest_node_cost;
	int		target_cost;
	int		size_list_b;
	t_list	*cheapest_node;

	cheapest_node = cheap_cost->cheap;
	size_list_b = ft_lstsize(*b);
	target_cost = 0;
	cheapest_node_cost = ((t_node *)(cheapest_node->content))->idx;
	if (((t_node *)(tgt->content))->idx != 0)
		target_cost = size_list_b - ((t_node *)(tgt->content))->idx;
	while (cheapest_node_cost > 0)
	{
		ra(a, true);
		cheapest_node_cost--;
	}
	while (target_cost > 0)
	{
		rrb(b, true);
		target_cost--;
	}
	return ;
}

static void	step_rv_rt(t_cost *cheap_cost, t_list **a, t_list *tgt, t_list **b)
{
	int		cheap_node_cost;
	int		target_cost;
	int		size_list_a;
	t_list	*cheap_node;

	cheap_node = cheap_cost->cheap;
	size_list_a = ft_lstsize(*a);
	cheap_node_cost = 0;
	if (((t_node *)(cheap_node->content))->idx != 0)
		cheap_node_cost = size_list_a - ((t_node *)(cheap_node->content))->idx;
	target_cost = ((t_node *)(tgt->content))->idx;
	while (cheap_node_cost > 0)
	{
		rra(a, true);
		cheap_node_cost--;
	}
	while (target_cost > 0)
	{
		rb(b, true);
		target_cost--;
	}
	return ;
}

void	execute_step(t_list **a, t_list **b)
{
	t_list	*current_a;
	t_cost	chp_node;
	t_cost	current_node;

	current_a = *a;
	chp_node.cost = INT_MAX;
	while (current_a != NULL)
	{
		find_target_of_a_node((t_node *)(current_a->content), b);
		cost(current_a, a, b, &current_node);
		if (current_node.cost < chp_node.cost)
			chp_node = current_node;
		current_a = current_a->next;
	}
	if (chp_node.operation == OP_ROTATE)
		step_rt(&chp_node, a, ((t_node *)(chp_node.cheap->content))->tgt, b);
	if (chp_node.operation == OP_REVERSE)
		step_rv(&chp_node, a, ((t_node *)(chp_node.cheap->content))->tgt, b);
	if (chp_node.operation == OP_ROT_REV)
		step_rt_rv(&chp_node, a, ((t_node *)(chp_node.cheap->content))->tgt, b);
	if (chp_node.operation == OP_REV_ROT)
		step_rv_rt(&chp_node, a, ((t_node *)(chp_node.cheap->content))->tgt, b);
	pb(a, b, true);
	return ;
}
