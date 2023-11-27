/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:38:17 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/27 10:13:21 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_nbr_ps(t_stack *stack_a)
{
	t_stack	*aux;

	aux = stack_a;
	while (stack_a)
	{
		if (stack_a->error == -1)
		{
			stack_a = aux;
			return (1);
		}
		stack_a = stack_a->next;
	}
	stack_a = aux;
	return (0);
}

static int	check_duplicate(t_stack *stack_a)
{
	long	nb1;
	long	nb2;
	t_stack	*aux;

	while (stack_a != NULL)
	{
		nb1 = stack_a->nbr;
		aux = stack_a->next;
		while (aux != NULL)
		{
			nb2 = aux->nbr;
			if (nb1 == nb2)
				return (1);
			aux = aux->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	check_errors(t_stack *stack_a)
{
	if (!stack_a)
		return (1);
	if (check_nbr_ps(stack_a) == 1)
		return (1);
	if (check_duplicate(stack_a) == 1)
		return (1);
	return (0);
}
