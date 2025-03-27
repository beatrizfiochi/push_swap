/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:32:36 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/27 18:36:14 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_data	data;
	int		list_size;

	a = NULL;
	b = NULL;
	if (handle_input(argc, argv, &data, &a) != 0)
		return (1);
	if (is_sorted(&a) == true)
	{
		clear_data(&data);
		ft_lstclear(&a, free);
		return (0);
	}
	list_size = ft_lstsize(a);
	if (list_size == 2)
		sort_two(&a);
	if (list_size == 3)
		sort_three(&a);
	if (list_size > 3)
		sort(&a, &b);
	clear_data(&data);
	ft_lstclear(&a, free);
	return (0);
}
