/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:32:36 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/30 16:14:40 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	main_sort(t_list **a, t_list **b)
{
	int		list_size;

	list_size = ft_lstsize(*a);
	if (list_size == 2)
		sort_two(a);
	if (list_size == 3)
		sort_three(a);
	if (list_size > 3)
		sort(a, b);
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_data	data;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (handle_input(argc, argv, &data, &a) != 0)
		return (1);
	if (is_sorted(&a) == true)
	{
		clear_data(&data);
		ft_lstclear(&a, free);
		return (0);
	}
	main_sort(&a, &b);
	clear_data(&data);
	ft_lstclear(&a, free);
	return (0);
}
