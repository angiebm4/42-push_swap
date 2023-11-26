/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strict_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:59:44 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/25 23:59:31 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	get_nb(char *str, int i, t_stack *stack_a)
{
	int		sign;
	long	nb;

	nb = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		stack_a->error = -1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			stack_a->error = -1;
		nb = ((str[i] - '0') + (nb * 10));
		i++;
	}
	return(nb * sign);
}

int	ft_strict_atoi(char *str, t_stack *stack_a)
{
	long	i;
	long	nb;

	nb = 0;
	i = 0;
	if (str[i] == '\0')
		return (stack_a->error = -1, 0);
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	nb = get_nb(str, i, stack_a);
	if (nb < INT_MIN || nb > INT_MAX)
		stack_a->error = -1;
	return (nb);
}
