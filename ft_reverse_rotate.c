/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:01:46 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/27 12:16:52 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	// t_stack	*aux;
	// t_stack	*head;

	// head = (*stack);
	// while ((*stack)->next != NULL)
	// 	(*stack) = (*stack)->next;
	// aux = (*stack)->prev;
	// head->prev = (*stack);
	// (*stack)->prev = NULL;
	// (*stack)->next = head;
	// aux->next = NULL;

	t_stack	*aux1;
	t_stack	*aux2;
	
	if (!(*stack) || !(*stack)->next)
		return ;
	aux1 = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	aux2 = (*stack)->next;
	(*stack)->next = NULL;
	aux2->next = aux1;
	aux2->prev = NULL;
	aux2->next->prev = aux2;
	(*stack) = aux2;
}

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	//printf("size --> %d\n", ft_count_nodes(*stack_a));
	ft_reverse_rotate(stack_a);
	//printf("size --> %d\n", ft_count_nodes(*stack_a));
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