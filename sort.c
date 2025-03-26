/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:06:33 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/26 17:54:09 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		lst_size_a;
	int		lst_size_b;
	int		median_of_lst;
	t_list	*min_node;

	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
		pb(stack_a, stack_b);
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
	put_index(stack_a);
	min_node = find_min(stack_a);
	if (((t_node *)(min_node->content))->index != 0)
	{
		median_of_lst = median(stack_a);
		if (((t_node *)(min_node->content))->index >= median_of_lst)
		{
			while (((t_node *)(min_node->content))->index != 0)
			{
				rra(stack_a);
				put_index(stack_a);
			}
		}
		else
		{
			while (((t_node *)(min_node->content))->index != 0)
			{
				ra(stack_a);
				put_index(stack_a);
			}
		}
	}
	return ;
}
