/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:06:36 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/28 21:13:31 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	error_op(char *error)
{
	write(2, error, 6);
	return (0);
}

void	clean(char *op, t_data data, t_list *a, t_list *b)
{
	free(op);
	clear_data(&data);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}
