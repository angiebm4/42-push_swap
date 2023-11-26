/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:01:46 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/24 18:24:05 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*head;

	head = (*stack); 
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	aux = (*stack)->prev;
	aux->next = NULL;
	head->prev = (*stack);
	(*stack)->prev = NULL;
	(*stack)->next = head;
}

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}