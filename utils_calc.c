/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:59:19 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/26 17:36:40 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_list **stack)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *stack;
	while (current != NULL)
	{
		((t_node *)(current->content))->index = i;
		i++;
		current = current->next;
	}
	return ;
}

int	median(t_list **stack)
{
	int		lst_size;
	int		median;
	t_list	*current;

	current = *stack;
	lst_size = ft_lstsize(current);
	median = lst_size / 2;
	return (median);
}
