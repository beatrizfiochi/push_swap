/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:06:33 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/21 19:52:20 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	len_a;
	int	len_b;
	int	total_cost;
	int	cost_a;
	int	cost_target_a;

	total_cost = 0;
	cost_a = 0;
	cost_target_a = 0;
	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
		pb(stack_a, stack_b);
	put_index(stack_a);                                                    //lembrar de atualizar quando mudar as listas
	put_index(stack_b);                                                    //lembrar de atualizar quando mudar as listas
	len_a = ft_lstsize(*stack_a);                                          //lembrar de atualizar quando mudar as listas
	len_b = ft_lstsize(*stack_b);                                          //lembrar de atualizar quando mudar as listas
	while (*stack_a != NULL)
	{
			find_target_of_a_node((t_node *)(*stack_a)->content, stack_b);
			ft_printf("\n\n\nTARGET OF: %d, is %d\n", ((t_node *)(*stack_a)->content)->nbr, ((t_node *)(((t_node *)(*stack_a)->content)->target->content))->nbr); //apagar
			cost_a = cost(stack_a, len_a);
			cost_target_a = cost(&(((t_node *)(*stack_a)->content)->target), len_b);
			total_cost = cost_a + cost_target_a + 1;
			ft_printf("cost to: %d, is %d\n", ((t_node *)(*stack_a)->content)->nbr, cost_a); //apagar
			ft_printf("cost of target: %d, is %d\n", ((t_node *)(*stack_a)->content)->nbr, cost_target_a); //apagar
			ft_printf("total cost of: %d, is %d\n\n\n", ((t_node *)(*stack_a)->content)->nbr, total_cost); //apagar
			stack_a = &(*stack_a)->next;
	}
	return ;
}
