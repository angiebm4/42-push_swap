/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:26:57 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/11 20:29:15 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_index(t_stack **stack_a)
{
	long	nb1;
	long	nb2;
	t_stack *aux;
	t_stack	*aux2;
	
	(*stack_a)->index = 1;
	aux2 = (*stack_a);
	while (aux2 != NULL)
	{
		nb1 = aux2->nbr;
		aux = (*stack_a);
		while (aux != NULL)
		{
			nb2 = aux->nbr;
			if (nb1 > nb2)
				(*stack_a)->index += 1;
			aux = aux->next;
		}
		aux = (*stack_a);
		(*stack_a)->index = 1;
		aux2 = aux2->next;
	}
}

static int	ft_count_nodes(t_stack *stack)
{
	int	nb;

	nb = 0;
	if (!(stack))
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		nb++;
	}
	return (nb);
}

void	push_too_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	
	size = ft_count_nodes(*stack_a);
	while (size > 3)
	{
		ft_push_b(stack_a, stack_b);
		size--;
	}
}

void	order_three_nb(t_stack **stack_a, int i)
{
	while (i > 0)
	{
		if ((*stack_a)->nbr < (*stack_a)->next->nbr)
		{
			if ((*stack_a)->next->nbr < (*stack_a)->next->next->nbr)
				return ;
			else
			{
				ft_reverse_rotate_a(stack_a);
				ft_swap_a(stack_a);
			}
		}
		else
		{
			if ((*stack_a)->nbr > (*stack_a)->next->next->nbr)
				ft_rotate_a(stack_a);
			else
			{
				if ((*stack_a)->next->nbr < (*stack_a)->next->next->nbr)
					ft_swap_a(stack_a);
			}
		}
		i--;
	}
}
