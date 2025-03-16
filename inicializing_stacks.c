/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicializing_stacks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:47:22 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/16 16:21:56 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_list **stack, char **argv)
{
	t_node	*content;
	t_list	*list;

	while(*argv != NULL)
	{
		content = (t_node *)malloc(sizeof(t_node));
		if(content == NULL)
			return ;
		content->nbr = ft_atoi(*argv);
		list = ft_lstnew(content);
		if(list == NULL)
		{
			free(content);
			return ;
		}
		ft_lstadd_back(stack, list);
		argv++;
	}
}

void	init_stack(t_list **stack, char **argv)
{

}
