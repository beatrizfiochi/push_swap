/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_final_steps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:16:02 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/30 17:00:25 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_op_index(t_list **stack, void (*func)(t_list **, bool))
{
	func(stack, true);
	put_index(stack);
	return ;
}

// t_list *b = * to current b node
void	execute_final_steps(t_list **stack_b, t_list **stack_a)
{
	t_list	*b;
	int		median_lst;

	b = *stack_b;
	find_target_of_b_node((t_node *)(b->content), stack_a);
	put_index(stack_a);
	if (((t_node *)(((t_node *)(b->content))->tgt->content))->idx > 0)
	{
		median_lst = median(stack_a);
		if (((t_node *)(((t_node *)(b->content))->tgt->content))->idx
			> median_lst)
		{
			while (((t_node *)(((t_node *)(b->content))->tgt->content))->idx
				!= 0)
				do_op_index(stack_a, rra);
		}
		else
		{
			while (((t_node *)(((t_node *)(b->content))->tgt->content))->idx
				!= 0)
				do_op_index(stack_a, ra);
		}
	}
	pa(stack_a, stack_b, true);
}
