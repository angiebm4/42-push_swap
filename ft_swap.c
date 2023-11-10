/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:24:51 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/09 12:32:45 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*aux2;

	aux = (*stack);
	aux2 = (*stack)->next->next;
	(*stack) = (*stack)->next;
	(*stack)->next = aux;
	(*stack)->prev = NULL;
	(*stack)->next->prev = (*stack);
	(*stack)->next->next = aux2;
}

void	ft_swap_a(t_stack **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_swap(stack_a);
	write(1, "ss\n", 3);
}
