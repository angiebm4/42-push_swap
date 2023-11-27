/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_movs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:18:03 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/27 16:21:31 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_stack **stack_)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = (*stack_);
	while ((*stack_) != NULL)
	{
		(*stack_)->pos = i;
		(*stack_) = (*stack_)->next;
		i++;
	}
	(*stack_) = aux;
}

void	get_movs_b(t_stack *stack_b, int size_b)
{
	while (stack_b != NULL)
	{
		if (stack_b->pos <= (size_b / 2))
			stack_b->r_b = stack_b->pos;
		else
			stack_b->r_b = -1 * (size_b - stack_b->pos);
		stack_b = stack_b->next;
	}
}

t_stack	*find_first(t_stack *stack_a)
{
	t_stack	*min;

	min = stack_a;
	while (stack_a != NULL)
	{
		if (stack_a->nbr < min->nbr)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}
void	how_many_rr_a(t_stack *stack_b, t_stack *first_a, int size_a)
{
	if (first_a->pos <= (size_a / 2))
		stack_b->r_a = first_a->pos;
	else
		stack_b->r_a = -1 * (size_a - first_a->pos);
}

void	get_movs_a(t_stack *stack_b, t_stack *stack_a, int size_a)
{
	t_stack	*first;
	t_stack	*aux;
	int		size;

	first = find_first(stack_a);
    // printf("numero menor ---> %ld\n", first->nbr);
    // printf("size --> %d\n", size_a);
	aux = first;
	size = size_a;
	while (stack_b != NULL)
	{
		first = aux;
		size_a = size;
		while (size_a > 0)
		{
			if (stack_b->nbr < first->nbr)
				break ;
            else if (first->next == NULL)
            {  
                if (stack_b->nbr < first->nbr)
                    break ;
				first = stack_a;
            }
			else if (stack_b->nbr > first->nbr)
			{
				if (size_a == 1)
				{
					first = aux;
					break ;
				}
				first = first->next;
			}
			size_a--;
		}
        // printf("numero que deberia estar en head ---> %ld\n", first->nbr);
		how_many_rr_a(stack_b, first, size);
		stack_b = stack_b->next;
	}
}

void	check_if_double_r(t_stack *stack_b)
{
	int	nb;

	while (stack_b != NULL)
	{
		nb = ft_abs(stack_b->r_a) + ft_abs(stack_b->r_b);
		if (stack_b->r_a < 0 && stack_b->r_b < 0)
		{
			if (ft_abs(stack_b->r_a) > ft_abs(stack_b->r_b))
				stack_b->nb_mov = ft_abs(stack_b->r_a);
			else if (ft_abs(stack_b->r_a) < ft_abs(stack_b->r_b))
				stack_b->nb_mov = ft_abs(stack_b->r_b);
			else
				stack_b->nb_mov = (nb / 2) + (nb % 2);
		}			
		else if (stack_b->r_a > 0 && stack_b->r_b > 0)
		{
			if (ft_abs(stack_b->r_a) > ft_abs(stack_b->r_b))
				stack_b->nb_mov = ft_abs(stack_b->r_a);
			else if (ft_abs(stack_b->r_a) < ft_abs(stack_b->r_b))
				stack_b->nb_mov = ft_abs(stack_b->r_b);
			else
				stack_b->nb_mov = (nb / 2) + (nb % 2);
		}
		else
			stack_b->nb_mov = ft_abs(stack_b->r_a) + ft_abs(stack_b->r_b);
		stack_b = stack_b->next;
	}
}
