/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:27:47 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/02/02 23:47:33 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_input (int argc, char **argv, t_data *data)
{
	data->args_need_free = false;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (argc > 2)
		data->args = &argv[1];
	else
	{
		data->args_need_free = true;
		data->args = ft_split(argv[1], ' ');
		if (data->args == NULL)
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
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

int	syntax_error (t_data *data)
{
	char	**s;
	int		i;

	s = data->args;
	while (*s != NULL)
	{
		i = 0;
		while ((*s)[i] == '+' || (*s)[i] == '-')
			i++;
		if((*s)[i] == '\0')
		{
			ft_printf("Error\n");
			exit(1);
		}
		while ((*s)[i] != '\0')
		{
			if ((*s)[i] < '0' || (*s)[i] > '9')
			{
				ft_printf("Error\n");
				exit(1);
			}
			i++;
		}
		s++;
	}
	return (0);
}
