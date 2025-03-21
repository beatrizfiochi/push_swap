/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:59:19 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/21 18:52:04 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	middle(t_list **stack)
// {
// 	int	len;
// 	int	middle;

// 	len = ft_lstsize(*stack);
// 	middle = len / 2;
// 	return (middle - 1);
// }

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
