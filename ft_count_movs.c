// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_count_movs.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/11/23 06:47:32 by abarrio-          #+#    #+#             */
// /*   Updated: 2023/11/24 23:22:00 by abarrio-         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "push_swap.h"

void    set_pos(t_stack **stack_)
{
    int     i;
    t_stack *aux;


    i = 1;
    aux = (*stack_);
    while((*stack_) != NULL)
    {
        (*stack_)->pos = i;
        (*stack_) = (*stack_)->next;
        i++;
    }
    (*stack_) = aux;
}

void	get_movs_b(t_stack *stack_b, int size_b)
{
    while(stack_b != NULL)
	{
        if (stack_b->pos <= (size_b / 2) + 1)
		{
			stack_b->r_b = stack_b->pos - 1;
	        stack_b->nb_mov += stack_b->pos - 1;
		}
        else
		{
			stack_b->r_b = -((size_b - stack_b->pos) + 1);
            stack_b->nb_mov += ((size_b - stack_b->pos) + 1);
		}
        stack_b = stack_b->next;
    }
}

t_stack *find_first(t_stack *stack_a)
{
    t_stack *first;

    first = stack_a;
    while(first != NULL)
    {
        if (first->next && first->nbr < first->next->nbr)
            break ;
        else
        {
            first = (stack_a);
            break ;
        }
        first = first->next;
    }
    return(first);
}
int	how_many_rr_a(t_stack *stack_b, t_stack *stack_a, int size_a)
{
    int movs;

    movs = 0;
    if (stack_a->pos <= (size_a / 2) + 1)
    {
        stack_b->r_a = stack_a->pos - 1;
        movs = stack_a->pos - 1;
        
    }
    else
    {
        stack_b->r_a = -(size_a - stack_a->pos + 1);
        movs = size_a - stack_a->pos + 1;
        // printf("%s%d%s\n", GREENFOSFI, stack_b->r_a, CLEAR);
        // printf("%s%d%s\n", GREENFOSFI, stack_a->pos, CLEAR);
        // printf("%s%d%s\n", GREENFOSFI, size_a, CLEAR);
    }
    return(movs);
}

void	get_movs_a(t_stack *stack_b, t_stack *stack_a, int size_a)
{
    t_stack *first;
    t_stack *aux;
    t_stack *head_a;
    int     size;

    head_a = stack_a;
    first = find_first(stack_a);
    aux = first;
    size = size_a;
    while(stack_b != NULL)
    {
        first = aux;
        while(size_a >= 0)
        {
            if (stack_b->nbr < first->nbr)
                break ;
            if (first->next == NULL)
                first = head_a;
            else
                first = first->next;
            size_a--;
        }
        stack_b->nb_mov += how_many_rr_a(stack_b, first, size);
        stack_b = stack_b->next;
    }
}

void	check_if_double_r(t_stack *stack_b)
{
    while (stack_b != NULL)
    {
        if (stack_b->r_a < 0 && stack_b->r_b < 0)
            stack_b->nb_mov -= (ft_abs(ft_abs(stack_b->r_a) - ft_abs(stack_b->r_b)));
        else if (stack_b->r_a > 0 && stack_b->r_b > 0)
            stack_b->nb_mov -= (ft_abs((stack_b->r_a - stack_b->r_b)));
        stack_b = stack_b->next;
    }
}
