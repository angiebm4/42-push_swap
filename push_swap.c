/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:26:57 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/09 19:07:10 by abarrio-         ###   ########.fr       */
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

static int	ft_count_nodes(t_stack *stack_a)
{
	int	nb;

	nb = 0;
	if (!(stack_a))
		return (0);
	while (stack_a != NULL)
	{
		stack_a = stack_a->next;
		nb++;
	}
	return (nb);
}

void	push_too_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	
	size = ft_count_nodes(*stack_a);
	printf("%d\n", size);
	(*stack_b) = ft_init_stack(stack_b);
	printf("owowo ---> %ld\n", (*stack_b)->nbr);
	while (size > 3)
	{
		ft_push(stack_a, stack_b);
		(*stack_b)->next = ft_init_stack(stack_b);
		size--;
	}
	(*stack_b)->next = NULL;
	printf("%d\n", size);
	printf("uwu\n");
}