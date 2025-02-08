/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:27:47 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/02/04 14:29:34 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_integer(const char *str)
{
	long	num;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_printf("Error\n");
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

static int	is_duplicate(t_data *data, int n)
{
	char	**tmp;

	tmp = data->args;
	while (*tmp != NULL)
	{
		if (ft_atoi(*tmp) == n)
			print_error(data);
		tmp++;
	}
	return (0);
}

int	handle_input(int argc, char **argv, t_data *data)
{
	char	**s;

	data->args_need_free = false;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		print_error(data);
	if (argc > 2)
		data->args = &argv[1];
	else
	{
		data->args_need_free = true;
		data->args = ft_split(argv[1], ' ');
		if (data->args == NULL)
			print_error(data);
	}
	syntax_error(data);
	s = data->args;
	while(*s != NULL)
		is_duplicate(data, ft_atol(*s++));
	return (0);
}

void	clear_data(t_data *data)
{
	char	**s;

	if(data->args_need_free == true)
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
