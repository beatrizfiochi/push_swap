/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_and_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:35:07 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/18 11:57:47 by bfiochi-         ###   ########.fr       */
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

int	find_min(t_list **stack)
{
	t_list	*current;
	t_node	*min_node;
	t_node	*node;

	current = *stack;
	min_node = (t_node *)(current->content);
	while(current != NULL)
	{
		node = (t_node *)(current->content);
		if(node->nbr < min_node->nbr)
			min_node = node;
		current = current->next;
	}
	min_node->min = min_node->nbr;
	return(min_node->min);
}

