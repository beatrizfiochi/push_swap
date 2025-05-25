/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:27:58 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/28 20:48:18 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int		nbr;
	int		min;
	int		max;
	int		idx;
	t_list	*tgt;
}	t_node;

typedef struct s_data
{
	char			**args;
	bool			args_need_free;
}	t_data;

# define OP_ROTATE 0
# define OP_REVERSE 1
# define OP_ROT_REV 2
# define OP_REV_ROT 3

typedef struct s_cost
{
	t_list	*cheap;
	int		cost;
	int		operation;
}	t_cost;

int		handle_input(int argc, char **argv, t_data *data, t_list **stack_a);
int		cost(t_list *curr_a, t_list **a, t_list **b, t_cost *cheapest);
int		median(t_list **stack);
int		cost_utils(t_list **stack, int index);

t_list	*find_min(t_list **stack);
t_list	*find_max(t_list **stack);

long	ft_atol(const char *nbr);

void	clear_data(t_data *data);
void	print_error(t_data *data);
void	init_stack_a(t_list **stack_a, char **argv);
void	sa(t_list **stack_a, bool print);
void	sb(t_list **stack_b, bool print);
void	ss(t_list **stack_a, t_list **stack_b, bool print);
void	pa(t_list **stack_a, t_list **stack_b, bool print);
void	pb(t_list **stack_a, t_list **stack_b, bool print);
void	ra(t_list **stack_a, bool print);
void	rb(t_list **stack_b, bool print);
void	rr(t_list **stack_a, t_list **stack_b, bool print);
void	rra(t_list **stack_a, bool print);
void	rrb(t_list **stack_b, bool print);
void	rrr(t_list **stack_a, t_list **stack_b, bool print);
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	sort(t_list **stack_a, t_list **stack_b);
void	find_target_of_a_node(t_node *a, t_list **stack_b);
void	put_index(t_list **stack);
void	execute_step(t_list **stack_a, t_list **stack_b);
void	find_target_of_b_node(t_node *b, t_list **stack_a);
void	execute_final_steps(t_list **stack_b, t_list **stack_a);
void	fill_cost(t_cost *cost_op, t_list *current, int cost, int op);
void	do_op_c(t_list **stack, void (*func)(t_list **, bool), int cost, int p);

bool	is_sorted(t_list **stack);

#endif
