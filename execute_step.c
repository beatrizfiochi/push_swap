/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:33:59 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/26 14:44:15 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	step_rot(t_cost *cheapest_cost, t_list **a, t_list *target, t_list **b)
{
	int	cheapest_node_cost;
	int	target_cost;
	int	real_cost;
	int	performed_op;
	int	sum_cost;
	t_list *cheapest_node;

	cheapest_node = cheapest_cost->cheapest;
	cheapest_node_cost = ((t_node *)(cheapest_node->content))->index;
	target_cost = ((t_node *)(target->content))->index;
	real_cost = cheapest_cost->cost;
	sum_cost = cheapest_node_cost + target_cost;
	performed_op = 0;
	while (real_cost != 0 && real_cost <= sum_cost)
	{
		rr(a, b);
		sum_cost--;
		performed_op++;
	}
	cheapest_node_cost = cheapest_node_cost - performed_op;
	while (cheapest_node_cost > 0)
	{
		ra(a);
		cheapest_node_cost--;
	}
	target_cost = target_cost - performed_op;
	while (target_cost > 0)
	{
		rb(b);
		target_cost--;
	}
	return ;
}

static void	step_rev(t_cost *cheapest_cost, t_list **a, t_list *target, t_list **b)
{
	int	cheapest_node_cost;
	int	target_cost;
	int	real_cost;
	int	performed_op;
	int	sum_cost;
	t_list *cheapest_node;

	cheapest_node = cheapest_cost->cheapest;
	cheapest_node_cost = ((t_node *)(cheapest_node->content))->index;
	target_cost = ((t_node *)(target->content))->index;
	real_cost = cheapest_cost->cost;
	sum_cost = cheapest_node_cost + target_cost;
	performed_op = 0;
	while (real_cost != 0 && real_cost <= sum_cost)
	{
		rrr(a, b);
		sum_cost--;
		performed_op++;
	}
	cheapest_node_cost = cheapest_node_cost - performed_op;
	while (cheapest_node_cost > 0)
	{
		rra(a);
		cheapest_node_cost--;
	}
	target_cost = target_cost - performed_op;
	while (target_cost > 0)
	{
		rrb(b);
		target_cost--;
	}
	return ;
}

static void	step_rot_rev(t_cost *cheapest_cost, t_list **a, t_list *target, t_list **b)
{
	int	cheapest_node_cost;
	int	target_cost;
	t_list *cheapest_node;

	cheapest_node = cheapest_cost->cheapest;
	cheapest_node_cost = ((t_node *)(cheapest_node->content))->index;
	target_cost = ((t_node *)(target->content))->index;
	while (cheapest_node_cost > 0)
	{
		ra(a);
		cheapest_node_cost--;
	}
	while (target_cost > 0)
	{
		rrb(b);
		target_cost--;
	}
	return ;
}

static void	step_rev_rot(t_cost *cheapest_cost, t_list **a, t_list *target, t_list **b)
{
	int	cheapest_node_cost;
	int	target_cost;
	t_list *cheapest_node;

	cheapest_node = cheapest_cost->cheapest;
	cheapest_node_cost = ((t_node *)(cheapest_node->content))->index;
	target_cost = ((t_node *)(target->content))->index;
	while (cheapest_node_cost > 0)
	{
		rra(a);
		cheapest_node_cost--;
	}
	while (target_cost > 0)
	{
		rb(b);
		target_cost--;
	}
	return ;
}

void	execute_step(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_cost	cheapest_node;
	t_cost	current_node;

	current_a = *stack_a;
	cheapest_node.cost = INT_MAX;
	while (current_a != NULL)
	{
			find_target_of_a_node((t_node *)(current_a->content), stack_b);
			ft_printf("\n\n\nTARGET OF: %d, is %d\n", ((t_node *)(current_a->content))->nbr, ((t_node *)(((t_node *)(current_a->content))->target->content))->nbr); //APAGAR
			cost(current_a, stack_a, stack_b, &current_node);
			if (current_node.cost < cheapest_node.cost)
				cheapest_node = current_node;
			current_a = current_a->next;
	}
	ft_printf("\n\n\nThe cheapest node is: %d, the cost is %d\n", ((t_node *)(cheapest_node.cheapest->content))->nbr, cheapest_node.cost); //APAGAR
	ft_printf("Chosen operation: %d\n", cheapest_node.operation);
	if (cheapest_node.operation == OP_ROTATE)
	{
		step_rot(&cheapest_node, stack_a, ((t_node *)(cheapest_node.cheapest->content))->target, stack_b);
	}
	if (cheapest_node.operation == OP_REVERSE)
	{
		step_rev(&cheapest_node, stack_a, ((t_node *)(cheapest_node.cheapest->content))->target, stack_b);
	}
	if (cheapest_node.operation == OP_ROT_REV)
	{
		step_rot_rev(&cheapest_node, stack_a, ((t_node *)(cheapest_node.cheapest->content))->target, stack_b);
	}
	if (cheapest_node.operation == OP_REV_ROT)
	{
		step_rev_rot(&cheapest_node, stack_a, ((t_node *)(cheapest_node.cheapest->content))->target, stack_b);
	}
	pb(stack_a, stack_b);
	return ;
}
