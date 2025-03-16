/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:27:58 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/16 20:33:18 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct	s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_data
{
	char			**args;
	bool			args_need_free;
}	t_data;


int	handle_input(int argc, char **argv, t_data *data, t_list **stack_a);

long	ft_atol(const char *nbr);

void	clear_data(t_data *data);
void	print_error(t_data *data);
void	init_stack_a(t_list **stack, char **argv);

#endif
