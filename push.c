/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:34:47 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/18 14:47:16 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*second_b;

	head_a = *stack_a;
	head_b = *stack_b;
	second_b = head_b->next;
	if(head_b == NULL)
		return ;
	head_b->next = head_a;
	*stack_a = head_b;
	*stack_b = second_b;
	ft_printf("pa\n");
	return ;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*second_a;
	t_list	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	second_a = head_a->next;
	if(head_a == NULL)
		return ;
	head_a->next = head_b;
	*stack_b = head_a;
	*stack_a = second_a;
	ft_printf("pb\n");
	return ;
}
