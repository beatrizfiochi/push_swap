/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:06:33 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/21 17:21:51 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
		pb(stack_a, stack_b);
	while (*stack_a != NULL)
	{
			find_target_of_a_node((t_node *)(*stack_a)->content, stack_b);
			ft_printf("TARGET OF: %d, is %d\n", ((t_node *)(*stack_a)->content)->nbr,  ((t_node *)(*stack_a)->content)->target->nbr);
			stack_a = &(*stack_a)->next;
	}
	return ;
}
