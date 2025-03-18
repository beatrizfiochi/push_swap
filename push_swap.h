/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:27:58 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/18 14:10:42 by bfiochi-         ###   ########.fr       */
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
	int	nbr;
	int	min;
	int	max;
}	t_node;

typedef struct s_data
{
	char			**args;
	bool			args_need_free;
}	t_data;


int	handle_input(int argc, char **argv, t_data *data, t_list **stack_a);
int	find_min(t_list **stack);
int	find_max(t_list **stack);

long	ft_atol(const char *nbr);

void	clear_data(t_data *data);
void	print_error(t_data *data);
void	init_stack_a(t_list **stack_a, char **argv);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);

bool	is_sorted(t_list **stack);

#endif
