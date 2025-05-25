/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:06:33 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/28 20:38:41 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	last_op(t_list **stack)
{
	int		median_of_lst;
	t_list	*min_node;

	put_index(stack);
	min_node = find_min(stack);
	if (((t_node *)(min_node->content))->idx != 0)
	{
		median_of_lst = median(stack);
		if (((t_node *)(min_node->content))->idx >= median_of_lst)
		{
			while (((t_node *)(min_node->content))->idx != 0)
			{
				rra(stack, true);
				put_index(stack);
			}
		}
		else
		{
			while (((t_node *)(min_node->content))->idx != 0)
			{
				ra(stack, true);
				put_index(stack);
			}
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		lst_size_a;
	int		lst_size_b;

	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
		pb(stack_a, stack_b, true);
	lst_size_a = ft_lstsize(*stack_a);
	while (lst_size_a > 3)
	{
		execute_step(stack_a, stack_b);
		lst_size_a = ft_lstsize(*stack_a);
	}
	sort_three(stack_a);
	lst_size_b = ft_lstsize(*stack_b);
	while (lst_size_b > 0)
	{
		execute_final_steps(stack_b, stack_a);
		lst_size_b = ft_lstsize(*stack_b);
	}
	last_op(stack_a);
	return ;
}
