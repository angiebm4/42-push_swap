/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:53:27 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/24 23:22:18 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_nodes(t_stack *stack)
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

void	delete_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *aux;
	
	// while(stack_a)
	{
		aux = stack_a->next;
		free(stack_a);
		stack_a = aux;	
	}
	while(stack_b)
	{
		aux = stack_b->next;
		free(stack_b);
		stack_b = aux;	
	}
}

t_stack	*ft_init_stack(t_stack **stack)
{
	(*stack) = (t_stack *) malloc (1 * sizeof(t_stack));
	if (!(*stack))
		return(NULL);
	(*stack)->error = 0;
	(*stack)->nbr = 0;
	(*stack)->pos = 0;
	(*stack)->nb_mov = 0;
	(*stack)->r_a = 0;
	(*stack)->r_b = 0;
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	return(*stack);
}

void	check_ok_stack(t_stack *stack_a)
{
	while(stack_a->next != NULL && stack_a->nbr < stack_a->next->nbr)
		stack_a = stack_a->next;
	if (stack_a->next == NULL)
	{
		delete_stacks(stack_a, NULL);
		exit (0);
	}
}

int	ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return(nb);
}