/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicializing_stacks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:47:22 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/17 17:17:59 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_list **stack_a, char **argv)
{
	t_node	*content;
	t_list	*list_item;

	while(*argv != NULL)
	{
		content = (t_node *)malloc(sizeof(t_node));
		if(content == NULL)
			return ;
		content->nbr = ft_atoi(*argv);
		list_item = ft_lstnew(content);
		if(list_item == NULL)
		{
			free(content);
			return ;
		}
		ft_lstadd_back(stack_a, list_item);
		argv++;
	}
}
