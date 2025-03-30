/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:42:52 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/30 16:08:58 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_op(char *operation, t_list **a, t_list **b)
{
	if (ft_strncmp(operation, "sa\0", 3) == 0)
		sa(a, false);
	else if (ft_strncmp(operation, "sb\0", 3) == 0)
		sb(b, false);
	else if (ft_strncmp(operation, "ss\0", 3) == 0)
		ss(a, b, false);
	else if (ft_strncmp(operation, "pb\0", 3) == 0)
		pb(a, b, false);
	else if (ft_strncmp(operation, "pa\0", 3) == 0)
		pa(a, b, false);
	else if (ft_strncmp(operation, "ra\0", 3) == 0)
		ra(a, false);
	else if (ft_strncmp(operation, "rb\0", 3) == 0)
		rb(b, false);
	else if (ft_strncmp(operation, "rra\0", 4) == 0)
		rra(a, false);
	else if (ft_strncmp(operation, "rrb\0", 4) == 0)
		rrb(b, false);
	else if (ft_strncmp(operation, "rrr\0", 4) == 0)
		rrr(a, b, false);
	else if (ft_strncmp(operation, "rr\0", 3) == 0)
		rr(a, b, false);
	else
		return (error_op("Error\n"));
	return (1);
}

void	print_checker(t_list **a, t_list **b)
{
	if (is_sorted(a) == true && (b == NULL || *b == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_data	data;
	char	*operation;

	a = NULL;
	b = NULL;
	if (handle_input(argc, argv, &data, &a) != 0)
		return (1);
	operation = get_next_line(STDIN_FILENO);
	while (operation != NULL && *operation != '\n')
	{
		if (check_op(operation, &a, &b) == 0)
		{
			clean(operation, data, a, b);
			return (1);
		}
		free(operation);
		operation = get_next_line(STDIN_FILENO);
	}
	print_checker(&a, &b);
	clean(operation, data, a, b);
	return (0);
}
