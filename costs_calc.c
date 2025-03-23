/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:26:46 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/23 12:55:20 by bfiochi-         ###   ########.fr       */
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
	target_node = (t_node *)(node->target->content);
	a_cost = node->index;
	target_cost = target_node->index;
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
	target_node = (t_node *)(node->target->content);
	a_cost = 0;
	target_cost = 0;
	if (node->index != 0)
		a_cost = size_list_a - node->index;
	if (target_node->index != 0)
		target_cost = size_list_b - target_node->index;
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
	target_node = (t_node *)(node->target->content);
	a_cost = node->index;
	target_cost = 0;
	if (target_node->index != 0)
		target_cost = size_list_b - target_node->index;
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
	target_node = (t_node *)(node->target->content);
	a_cost = 0;
	if (node->index != 0)
		a_cost = size_list_a - node->index;
	target_cost = target_node->index;
	total_cost = a_cost + target_cost;
	return (total_cost);
}

int	cost(t_list *current_a, t_list **stack_a, t_list **stack_b)
{
	int		sz_l_a;
	int		sz_l_b;
	int		rot;
	int		rev;
	int		rot_rev;
	int		rev_rot;

	put_index(stack_a);
	put_index(stack_b);
	sz_l_a = ft_lstsize(*stack_a);
	sz_l_b = ft_lstsize(*stack_b);
	rot = cost_rot_all(current_a, sz_l_a, sz_l_b);
	rev = cost_rev_all(current_a, sz_l_a, sz_l_b);
	rot_rev = cost_rot_rev(current_a, sz_l_a, sz_l_b);
	rev_rot = cost_rev_rot(current_a, sz_l_a, sz_l_b);
	if (rot <= rev && rot <= rot_rev && rot <= rev_rot)
	{
		ft_printf("total cost of: %d, is %d\n\n\n", ((t_node *)(current_a->content))->nbr, rot); /////APAGAR
		return (rot);
	}
	else if (rev <= rot && rev <= rot_rev && rev <= rev_rot)
	{
		ft_printf("total cost of: %d, is %d\n\n\n", ((t_node *)(current_a->content))->nbr, rev); /////APAGAR
		return (rev);
	}
	else if (rot_rev <= rot && rot_rev <= rev && rot_rev <= rev_rot)
	{
		ft_printf("total cost of: %d, is %d\n\n\n", ((t_node *)(current_a->content))->nbr, rot_rev); /////APAGAR
		return (rot_rev);
	}
	else if (rev_rot <= rot && rev_rot <= rev && rev_rot <= rot_rev)
	{
		ft_printf("total cost of: %d, is %d\n\n\n", ((t_node *)(current_a->content))->nbr, rev_rot); /////APAGAR
		return (rev_rot);
	}
	return (0);
}
