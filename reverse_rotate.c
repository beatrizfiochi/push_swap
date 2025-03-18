/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:12:08 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/18 14:47:04 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_second_last_node(t_list **stack)
{
	t_list	*second_last_node;

	if(*stack == NULL || (*stack)->next == NULL)
		return (NULL);
	second_last_node = *stack;
	while(second_last_node->next->next != NULL)
		second_last_node = second_last_node->next;
	return (second_last_node);
}

static void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*second_last;

	head = *stack;
	tail = ft_lstlast(*stack);
	second_last = find_second_last_node(stack);
	if(second_last == NULL)
		return;
	tail->next = head;
	second_last->next = NULL;
	*stack = tail;
	return ;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
	return ;
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
	return ;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
	return ;
}
