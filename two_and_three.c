/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_and_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:35:07 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/17 23:32:12 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list **stack)
{
	t_list	*stack_a;

	if ((stack == NULL) || (*stack == NULL))
		return (false);
	stack_a = *stack;
	while(stack_a->next != NULL)
	{
		if(((t_node *)(stack_a->content))->nbr > ((t_node *)(stack_a->next->content))->nbr)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void	just_two(t_list **stack)
{
	sa(stack);
	ft_printf("sa\n");
	return ;
}

