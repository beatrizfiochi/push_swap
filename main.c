/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:32:36 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/02/18 16:06:45 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	// t_stack	*a;
	// t_stack	*b;
	t_data	data;

	// a = NULL;
	// b = NULL;
	if (handle_input(argc, argv, &data) != 0)
		return (1);
	char	**s;
	s = data.args;
	while (*s != NULL)
	{
		ft_printf("arg: %s\n", *s);
		s++;
	}
	clear_data(&data);
	return (0);
}
