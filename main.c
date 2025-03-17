/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:32:36 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/17 18:31:20 by bfiochi-         ###   ########.fr       */
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
	t_list	*b;
	t_data	data;

	a = NULL;
	b = NULL;
	if (handle_input(argc, argv, &data, &a) != 0)
		return (1);
	ft_printf("A:\n");
	ft_lstiter(a, print_node);
	ft_printf("B:\n");
	ft_lstiter(b, print_node);
	pb(&a, &b);
	ft_printf("A:\n");
	ft_lstiter(a, print_node);
	ft_printf("B:\n");
	ft_lstiter(b, print_node);
	pb(&a, &b);
	pb(&a, &b);
	ft_printf("A:\n");
	ft_lstiter(a, print_node);
	ft_printf("B:\n");
	ft_lstiter(b, print_node);
	rrr(&a, &b);
	ft_printf("A depois:\n");
	ft_lstiter(a, print_node);
	ft_printf("B depois:\n");
	ft_lstiter(b, print_node);
	clear_data(&data);
	ft_lstclear(&a, free);
	return (0);
}
