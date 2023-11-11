/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:12:50 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/11 17:22:17 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*new_head1;
	t_stack	*new_head2;
	
	new_head2 = (*stack1);
	new_head1 = (*stack1)->next;
	if ((*stack2) == NULL)
	{
		(*stack2) = new_head2;
		(*stack2)->prev = NULL;
		(*stack2)->next = NULL;
	}
	else
	{
		(*stack2)->prev = new_head2;
		new_head2->next = (*stack2);
		(*stack2) = new_head2;
	}
	if ((*stack2) != NULL)
		(*stack2)->prev = NULL;
	(*stack1) = new_head1;
	if ((*stack1) != NULL)
		(*stack1)->prev = NULL;
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b)
	{
		write(2, "Error\n", 6);
		return ;
	}
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return ;
	}
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
