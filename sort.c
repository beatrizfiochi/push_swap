/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:06:33 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/23 17:03:28 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	lst_size;

	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
		pb(stack_a, stack_b);
	lst_size = ft_lstsize(*stack_a);
	while (lst_size > 3)
	{
		execute_step(stack_a, stack_b);
		lst_size = ft_lstsize(*stack_a);
	}
	return ;
}
