/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:54:36 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/18 14:49:00 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*head;
	t_list	*second;

	head = *stack;
	second = head->next;
	if(second == NULL)
		return ;
	head->next = second->next;
	second->next = head;
	*stack = second;
	return ;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	return ;
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	return ;
}
