/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_and_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:35:07 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/18 14:49:46 by bfiochi-         ###   ########.fr       */
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

void	sort_two(t_list **stack)
{
	sa(stack);
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

int	find_max(t_list **stack)
{
	t_list	*current;
	t_node	*max_node;
	t_node	*node;

	current = *stack;
	max_node = (t_node *)(current->content);
	while(current != NULL)
	{
		node = (t_node *)(current->content);
		if(node->nbr > max_node->nbr)
			max_node = node;
		current = current->next;
	}
	max_node->max = max_node->nbr;
	return(max_node->max);
}

void	sort_three(t_list **stack)
{
	int		min;
	int		max;
	t_list	*head;
	t_list	*second;
	t_list	*tail;

	min = find_min(stack);
	max = find_max(stack);
	while(is_sorted(stack) == false)
	{
		head = *stack;
		second = head->next;
		tail = ft_lstlast(*stack);
		if ((min == ((t_node *)(head->content))->nbr && max == ((t_node *)(second->content))->nbr)
			|| (min == ((t_node *)(second->content))->nbr && max == ((t_node *)(tail->content))->nbr))
			sa(stack);
		else if ((max == ((t_node *)(head->content))->nbr && min == ((t_node *)(second->content))->nbr)
			|| (max == ((t_node *)(head->content))->nbr && min == ((t_node *)(tail->content))->nbr))
			ra(stack);
		else if (min == ((t_node *)(tail->content))->nbr && max == ((t_node *)(second->content))->nbr)
			rra(stack);
	}
	return ;
}


