/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicializing_stacks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:47:22 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/02/18 19:31:02 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list **stack, char **argv)
{
	t_node	*content;
	t_list	*node;

	while (*argv != NULL)
	{
		content = malloc(sizeof(t_node));
		if(content == NULL)
			return ;
		content->nbr = ft_atoi(*argv);
		node = ft_lstnew(content);
		if(node == NULL)
		{
			free(content);
			return ;
		}
		ft_lstadd_back(stack, node);
		argv++;
	}
}
