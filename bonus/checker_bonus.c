/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:42:52 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/04/03 13:30:53 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

static int	error_op(char *error)
{
	write(2, error, 6);
	return (0);
}

static void	clean(char *op, t_data data, t_list *a, t_list *b)
{
	free(op);
	clear_data(&data);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}

static int	check_op(char *operation, t_list **a, t_list **b)
{
	if (ft_strncmp(operation, "sa\n", 3) == 0)
		sa(a, false);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		sb(b, false);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		ss(a, b, false);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		pb(a, b, false);
	else if (ft_strncmp(operation, "pa\n", 3) == 0)
		pa(a, b, false);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		ra(a, false);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rb(b, false);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		rra(a, false);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		rrb(b, false);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		rrr(a, b, false);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
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
