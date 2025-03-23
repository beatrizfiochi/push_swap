/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:33:59 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/23 12:19:07 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_step(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;

	current_a = *stack_a;
	while (current_a != NULL)
	{
			find_target_of_a_node((t_node *)(current_a->content), stack_b);
			ft_printf("\n\n\nTARGET OF: %d, is %d\n", ((t_node *)(current_a->content))->nbr, ((t_node *)(((t_node *)(current_a->content))->target->content))->nbr); //APAGAR
			cost(current_a, stack_a, stack_b);
			current_a = current_a->next;
	}
	return ;
}
