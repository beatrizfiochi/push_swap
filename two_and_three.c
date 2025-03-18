/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_and_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:35:07 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/18 15:20:17 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list **stack)
{
	t_list	*stack_a;

	if ((stack == NULL) || (*stack == NULL))
		return (false);
	stack_a = *stack;
	while (stack_a->next != NULL)
	{
		if (((t_node *)(stack_a->content))->nbr
			> ((t_node *)(stack_a->next->content))->nbr)
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

static bool	need_sa(t_list **stack, t_list *h, t_list *sd, t_list *t)
{
	int		min;
	int		max;

	min = find_min(stack);
	max = find_max(stack);
	if ((min == ((t_node *)(h->content))->nbr
		&& max == ((t_node *)(sd->content))->nbr)
		|| (min == ((t_node *)(sd->content))->nbr
		&& max == ((t_node *)(t->content))->nbr))
		return (true);
	else
		return (false);
}

static bool	need_ra(t_list **stack, t_list *h, t_list *sd, t_list *t)
{
	int		min;
	int		max;

	min = find_min(stack);
	max = find_max(stack);
	if ((max == ((t_node *)(h->content))->nbr
		&& min == ((t_node *)(sd->content))->nbr)
		|| (max == ((t_node *)(h->content))->nbr
		&& min == ((t_node *)(t->content))->nbr))
		return (true);
	else
		return (false);
}

void	sort_three(t_list **stack)
{
	t_list	*h;
	t_list	*sd;
	t_list	*t;
	int		min;
	int		max;

	min = find_min(stack);
	max = find_max(stack);
	while (is_sorted(stack) == false)
	{
		h = *stack;
		sd = h->next;
		t = ft_lstlast(*stack);
		if (need_sa(stack, h, sd, t) == true)
			sa(stack);
		else if (need_ra(stack, h, sd, t) == true)
			ra(stack);
		else if (min == ((t_node *)(t->content))->nbr
			&& max == ((t_node *)(sd->content))->nbr)
			rra(stack);
	}
	return ;
}
