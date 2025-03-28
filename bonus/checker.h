/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:43:02 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/28 21:10:09 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../push_swap.h"
# include "get_next_line/get_next_line.h"

int		error_op(char *error);

void	clean(char *op, t_data data, t_list *a, t_list *b);
void	trim_newline(char *str);

#endif
