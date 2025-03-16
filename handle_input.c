/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:27:47 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/16 20:34:12 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_integer(const char *str)
{
	long	num;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (0);
}

static int	syntax_error(t_data *data)
{
	char	**s;
	int		i;

	s = data->args;
	while (*s != NULL)
	{
		i = 0;
		if((*s)[i] == '+' || (*s)[i] == '-')
			i++;
		if((*s)[i] == '\0')
			print_error(data);
		while ((*s)[i] != '\0')
		{
			if ((*s)[i] < '0' || (*s)[i] > '9')
				print_error(data);
			i++;
		}
		is_integer(*s);
		s++;
	}
	return (0);
}

static int	is_duplicate(t_data *data, int n, char **current)
{
	char	**tmp;

	tmp = data->args;
	while (tmp != NULL && tmp != current)
	{
		if (ft_atoi(*tmp) == n)
			print_error(data);
		tmp++;
	}
	return (0);
}

//handle with the input, if its ok, init stack a
int	handle_input(int argc, char **argv, t_data *data, t_list **stack_a)
{
	char	**s;

	*stack_a = NULL;
	data->args_need_free = false;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		print_error(data);
	if (argc > 2)
		data->args = &argv[1];
	else
	{
		data->args = ft_split(argv[1], ' ');
		if (data->args == NULL || data->args[0] == NULL)
			return (1);
		data->args_need_free = true;
	}
	syntax_error(data);
	s = data->args;
	while(*s != NULL)
	{
		is_duplicate(data, ft_atol(*s), s);
		s++;
	}
	init_stack_a(stack_a, data->args);
	return (0);
}
