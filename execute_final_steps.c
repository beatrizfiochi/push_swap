/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_final_steps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:16:02 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/27 17:16:21 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list *b = * to current b node
void	execute_final_steps(t_list **stack_b, t_list **stack_a)
{
	t_list	*b;
	int		median_lst;

	b = *stack_b;
	find_target_of_b_node((t_node *)(b->content), stack_a);
	// ft_printf("\n\n\nTARGET OF: %d, is %d\n", ((t_node *)(b->content))->nbr, ((t_node *)(((t_node *)(b->content))->target->content))->nbr); //APAGAR
	put_index(stack_a);
	if (((t_node *)(((t_node *)(b->content))->tgt->content))->idx > 0)
	{
		median_lst = median(stack_a);
		if (((t_node *)(((t_node *)(b->content))->tgt->content))->idx
			>= median_lst)
		{
			while (((t_node *)(((t_node *)(b->content))->tgt->content))->idx
				!= 0)
			{
				rra(stack_a);
				put_index(stack_a);
			}
		}
		else
		{
			while (((t_node *)(((t_node *)(b->content))->tgt->content))->idx
				!= 0)
			{
				ra(stack_a);
				put_index(stack_a);
			}
		}
	}
	pa(stack_a, stack_b);
	return ;
}
