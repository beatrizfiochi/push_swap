/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:48:35 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/18 15:04:45 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*second;

	head = *stack;
	tail = ft_lstlast(*stack);
	second = head->next;
	if (second == NULL)
		return ;
	tail->next = head;
	head->next = NULL;
	*stack = second;
	return ;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	return ;
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
	return ;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	return ;
}
