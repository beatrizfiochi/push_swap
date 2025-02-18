/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:02:07 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/02/18 15:14:06 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_data *data)
{
	clear_data(data);
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atol(const char *nbr)
{
	size_t	i;
	long	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if(nbr[i] == '-' || nbr[i] == '+')
	{
		if(nbr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		num = (nbr[i] - '0') + (num * 10);
		i++;
	}
	return (num * sign);
}
