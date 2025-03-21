/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:34:54 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/21 18:48:01 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(t_list **stack, int size_list)
{
	t_list	*current;
	t_node	*node;
	int		cost;

	current = *stack;
	node = (t_node *)(current->content);
	cost = 0;
	if (node->index <= (size_list / 2))
		cost = node->index;
	if (node->index > (size_list / 2))
		cost = size_list - node->index;
	return (cost);
}



