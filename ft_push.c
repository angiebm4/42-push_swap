/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:12:50 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/09 19:07:37 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*aux;
	t_stack	*aux2;

	aux = (*stack1);
	(*stack2) = (*stack2)->next;
	if ((*stack2) != NULL)
		(*stack2)->prev = NULL;
	aux2 = (*stack1);
	(*stack1) = aux;
	(*stack1)->next = aux2;
	(*stack1)->next->prev = (*stack1);
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b)
	{
		write(2, "Error\n", 6);
		return ;
	}
	ft_push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return ;
	}
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}