/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cheap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:19:04 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/29 10:25:32 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_cheap(t_stack *stack_b)
{
	t_stack	*min;

	min = stack_b;
	while (stack_b->next != NULL)
	{
		if (stack_b->nb_mov == 0)
		{
			min = stack_b;
			return (min);
		}
		if (stack_b->nb_mov < min->nb_mov)
			min = stack_b;
		stack_b = stack_b->next;
	}
	return (min);
}

static void	make_ab_movs(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while (cheap->r_a < 0 && cheap->r_b < 0)
	{
		ft_reverse_rotate_ab(stack_a, stack_b);
		cheap->r_a += 1;
		cheap->r_b += 1;
	}
	while (cheap->r_a > 0 && cheap->r_b > 0)
	{
		ft_rotate_ab(stack_a, stack_b);
		cheap->r_a -= 1;
		cheap->r_b -= 1;
	}
}

static void	make_a_movs(t_stack **stack_a, t_stack *cheap)
{
	while (cheap->r_a > 0)
	{
		ft_rotate_a(stack_a);
		cheap->r_a -= 1;
	}
	while (cheap->r_a < 0)
	{
		ft_reverse_rotate_a(stack_a);
		cheap->r_a += 1;
	}
}

static void	make_b_movs(t_stack **stack_b, t_stack *cheap)
{
	while (cheap->r_b > 0)
	{
		ft_rotate_b(stack_b);
		cheap->r_b -= 1;
	}
	while (cheap->r_b < 0)
	{
		ft_reverse_rotate_b(stack_b);
		cheap->r_b += 1;
	}
}

void	move_cheap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	cheap = find_cheap(*stack_b);
	make_ab_movs(stack_a, stack_b, cheap);
	make_a_movs(stack_a, cheap);
	make_b_movs(stack_b, cheap);
	ft_push_a(stack_a, stack_b);
}
