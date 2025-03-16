/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:32:36 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/16 20:44:15 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//apagar
void	print_node(void *vnode)
{
	t_node	*node;
	node = (t_node *)vnode;
	ft_printf("nbr: %d\n", node->nbr);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	// t_stack	*b;
	t_data	data;

	a = NULL;
	// b = NULL;
	if (handle_input(argc, argv, &data, &a) != 0)
		return (1);
	ft_lstiter(a, print_node);
	clear_data(&data);
	ft_lstclear(&a, free);
	return (0);
}
