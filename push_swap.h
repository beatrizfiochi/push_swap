/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:27:58 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/02/04 14:20:50 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct	s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

typedef struct s_data
{
	char			**args;
	bool			args_need_free;
}	t_data;


int	handle_input (int argc, char **argv, t_data *data);

long	ft_atol(const char *nbr);

void	clear_data(t_data *data);
void	print_error(t_data *data);

#endif
