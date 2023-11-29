/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:03:42 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/29 12:38:19 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_stack *stack_a)
{
	long	nb1;
	long	nb2;
	t_stack	*aux;
	t_stack	*head;

	head = stack_a;
	while(stack_a)
	{
		nb1 = stack_a->nbr;
		aux = head;
		while(aux)
		{
			nb2 = aux->nbr;
			if (nb1 > nb2)
				stack_a->index += 1;
			aux = aux->next;
		}
		stack_a = stack_a->next;
	}
}

void	push_too_b_5(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_count_nodes(*stack_a);
	while (size > 3)
	{
		ft_push_b(stack_a, stack_b);
		size--;
	}
}

int	find_pivot(t_stack **stack_a, int size_a)
{
	int	one;
	int two;
	int	three;
	t_stack	*aux;
	
	aux = (*stack_a);
	size_a = size_a / 2;
	one = ft_abs((*stack_a)->index - size_a);
	two = ft_abs((*stack_a)->next->index - size_a);
	while(aux->next)
		aux = aux->next;
	three = ft_abs(aux->index - size_a);
	if (three < two && three < one)
		ft_reverse_rotate_a(stack_a);
	else if (two < one && two < three)
		ft_swap_a(stack_a);
	return((*stack_a)->index);
	
}
void	push_too_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pivot;
	int size_a;

	

	//buscar de los dos primeros y el ultimo cual seria el mas optimo para quedarnos con el
	//contar nodos y seria el que mas cerca este de la mitad
	//el primero que hay que mover a b es ese
	// ir pusheando hasta que queden 3 en el stack a si el numero tiene un index menor solo pb si tiene un index mayor pb y rb
	// si el que he elegido de ivote es menor que la mitad colocar los mayores arriba si el que he elegido de pivote es mayor a la mitad colocar los menores arriba 
	size = ft_count_nodes(*stack_a);
	if (size <= 3)
		return;
	else if (size > 3 && size <= 5)
	{
		push_too_b_5(stack_a, stack_b);
		return ;
	}
	size_a = size;
	pivot = find_pivot(stack_a, size);
	// printf("pivot ---> %d\n", pivot);
	// printf("size_a ---> %d\n", size_a / 2);

	if (size-- > 3)
		ft_push_b(stack_a, stack_b);
	while (size > 3)
	{
		ft_push_b(stack_a, stack_b);
		if (size_a / 2 < pivot && (*stack_b)->index < pivot)
			ft_rotate_b(stack_b);
		else if (size_a / 2 > pivot && (*stack_b)->index > pivot)
			ft_rotate_b(stack_b);
		size--;
		// printf("\n---- STACK_A----\n");
		// print_stack(*stack_a);
		// printf("\n---- STACK_B ----\n");
		// print_stack(*stack_b);
	}
}
