/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:02:07 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/21 16:32:35 by bfiochi-         ###   ########.fr       */
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

t_node	*find_min(t_list **stack)
{
	t_list	*current;
	t_node	*min_node;
	t_node	*node;

	current = *stack;
	min_node = (t_node *)(current->content);
	while (current != NULL)
	{
		node = (t_node *)(current->content);
		if (node->nbr < min_node->nbr)
			min_node = node;
		current = current->next;
	}
	min_node->min = min_node->nbr;
	return (min_node);
}

t_node	*find_max(t_list **stack)
{
	t_list	*current;
	t_node	*max_node;
	t_node	*node;

	current = *stack;
	max_node = (t_node *)(current->content);
	while (current != NULL)
	{
		node = (t_node *)(current->content);
		if (node->nbr > max_node->nbr)
			max_node = node;
		current = current->next;
	}
	max_node->max = max_node->nbr;
	return (max_node);
}
