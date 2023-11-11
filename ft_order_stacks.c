/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:52:54 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/11 20:36:45 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos_b(t_stack **stack_b)
{
	int		pos;
	t_stack	*aux;

	pos = 1;
	aux = (*stack_b);
	while((*stack_b) != NULL)
	{
		(*stack_b)->pos_b = pos;
		(*stack_b) = (*stack_b)->next;
		pos++;
	}
	(*stack_b) = aux;
}

t_stack	*find_cheap(t_stack **stack_b)
{
	
}

void	ft_order(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	t_stack	*aux;

	size = ft_count_nodes(stack_b);
	aux = (*stack_b);
	while((*stack_b))
	{
		set_pos_b(stack_b);
		while((*stack_b) != NULL)
		{
			if ((*stack_b)->pos_b <= (size / 2))
				(*stack_b)->nb_mov += ((*stack_b)->pos_b - 1);
			else
				(*stack_b)->nb_mov += ((size - (*stack_b)->pos_b) + 1);
			(*stack_b) = (*stack_b)->next;
		}
		(*stack_b) = aux;
		while(((*stack_b) != NULL))
		{
			
		}
	}
}
