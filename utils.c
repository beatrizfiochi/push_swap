/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:02:07 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/27 17:15:23 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_data *data)
{
	clear_data(data);
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atol(const char *nbr)
{
	size_t	i;
	long	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		num = (nbr[i] - '0') + (num * 10);
		i++;
	}
	return (num * sign);
}

void	clear_data(t_data *data)
{
	char	**s;

	if (data->args_need_free == true)
	{
		s = data->args;
		while (*s != NULL)
		{
			free(*s);
			s++;
		}
		free(data->args);
	}
}

t_list	*find_min(t_list **stack)
{
	t_list	*current;
	t_list	*min_node;
	t_node	*node;

	current = *stack;
	min_node = current;
	while (current != NULL)
	{
		node = (t_node *)(current->content);
		if (node->nbr < ((t_node *)min_node->content)->nbr)
			min_node = current;
		current = current->next;
	}
	((t_node *)min_node->content)->min = ((t_node *)min_node->content)->nbr;
	return (min_node);
}

t_list	*find_max(t_list **stack)
{
	t_list	*current;
	t_list	*max_node;
	t_node	*node;

	current = *stack;
	max_node = current;
	while (current != NULL)
	{
		node = (t_node *)(current->content);
		if (node->nbr > ((t_node *)max_node->content)->nbr)
			max_node = current;
		current = current->next;
	}
	((t_node *)max_node->content)->max = ((t_node *)max_node->content)->nbr;
	return (max_node);
}
