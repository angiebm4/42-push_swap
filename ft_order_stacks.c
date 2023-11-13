/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:52:54 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/13 20:33:06 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_pos_b(t_stack **stack_b)
{
    int     pos;
    t_stack *aux;


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

void    set_pos_a(t_stack **stack_a)
{
    int     pos;
    t_stack *aux;


    pos = 1;
    aux = (*stack_a);
    while((*stack_a) != NULL)
    {
        (*stack_a)->pos_a = pos;
        (*stack_a) = (*stack_a)->next;
        pos++;
    }
    (*stack_a) = aux;
}

t_stack *find_cheap(t_stack *stack_b)
{
    t_stack *min;
    
    min = stack_b;
    while(stack_b->next != NULL)
    {
        if (stack_b->nb_mov == 1)
            return(stack_b);
        else if (stack_b->nb_mov < min->nb_mov)
            min = stack_b;
        stack_b = stack_b->next;
    }
    return(min);
}

int find_min_index(t_stack *stack_a, int size)
{
    t_stack *min;
    int mov;

    min = stack_a;
    while(stack_a != NULL)
    {
        if (stack_a->index < min->index)
            min = stack_a;
        stack_a = stack_a->next;
    }
    if (min->pos_a <= (size / 2))
        mov = min->pos_a - 1;
    else
        mov = (size - min->pos_a) + 1;
    return(mov);
}

void	get_movs_b(t_stack *stack_b, int size_b)
{
    while(stack_b != NULL)
	{
        if (stack_b->pos_b <= (size_b / 2) + 1)
		{
			stack_b->r_b = stack_b->pos_b - 1;
	        stack_b->nb_mov += stack_b->pos_b - 1;
		}
        else
		{
			stack_b->r_b = -((size_b - stack_b->pos_b) + 1);
            stack_b->nb_mov += ((size_b - stack_b->pos_b) + 1);
		}
        stack_b = stack_b->next;
    }
}
void    get_movs_a(t_stack **stack_b, int size_b, t_stack **stack_a, int size_a)
{
    t_stack *head_a;
    t_stack *head_b;

    head_a = (*stack_a);
    head_b = (*stack_b);
    while(((*stack_b) != NULL))
    {
        head_a = (*stack_a);
        while (((*stack_a) != NULL))
        {
            if ((*stack_a)->next && (*stack_b)->nbr < (*stack_a)->nbr && (*stack_b)->nbr > (*stack_a)->next->nbr)
            {
                
                if ((*stack_a)->pos_a <= (size_a / 2))
				{
					(*stack_b)->r_a = (*stack_a)->pos_a - 1;
                    (*stack_b)->nb_mov += (*stack_a)->pos_a - 1;
				}
                else
                {
                    (*stack_b)->r_a = -((size_b - (*stack_b)->pos_b) + 1);
                    (*stack_b)->nb_mov += ((size_b - (*stack_b)->pos_b) + 1);
                }
            }
            print_stack(*stack_b);
            if ((*stack_a)->next == NULL)
            {
                if ((*stack_a)->nbr < (*stack_b)->nbr && head_a->nbr > (*stack_b)->nbr)
                {
                    (*stack_b)->r_a = -find_min_index(head_a, size_a);
                    (*stack_b)->nb_mov += find_min_index(head_a, size_a);
                }
            }
            (*stack_a) = (*stack_a)->next;
        }
		(*stack_a) = head_a;
        (*stack_b) = (*stack_b)->next;
    }
   (*stack_b) = head_b;
}
// void    move_cheap(t_stack *cheap, t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack *head_b;
//     t_stack *head_a;
//     int i;
//     int size_b;
//     int size_a;

//     size_b = ft_count_nodes(*stack_b);
//     size_a = ft_count_nodes(*stack_a);
//     i = 0;
//     head_b = (*stack_b);
//     while(head_b != cheap)
//     {
//         head_b = head_b->next;
//         i++;
//     }
//     if (head_b->r_b == -1)
//         i = size_b - i + 1;
//     while(i > 0)
//     {
//         if (cheap->r_b == 1)
//             ft_rotate(stack_b);
//         else if (cheap->r_b == -1)
//             ft_reverse_rotate(stack_b);
//         i--;
//     }
//     head_a = (*stack_a);
//     i = 0;
//     while(head_a != NULL)
//     {
//         if (head_a->next && (*stack_b)->nbr < head_a->nbr && (*stack_b)->nbr > head_a->next->nbr)
//             break ;
//         if (head_a->next == NULL)
//             break ;
//         head_a = head_a->next;
//         i++;
//     }
//     if (head_a->r_a == -1)
//         i = size_a - i + 1;
//     while(i > 0)
//     {
//         if (head_a->r_a == 1)
//             ft_rotate(stack_a);
//         else if (head_a->r_a == -1)
//             ft_reverse_rotate(stack_a);
//         i--;
//     }
//     ft_push_a(stack_b, stack_a);
    
// }
// void    move_cheap(t_stack *cheap, t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack *min;
//     int     movs;
    
//     movs = 1;
//     min = (*stack_b);
//     while((*stack_b)->next != NULL)
//     {
//         if ((*stack_b)->nb_mov == movs)
//         {
//             while ((*stack_b)->prev != NULL)
//             {
//                 if ((*stack_b)->r_b == 1)
//                     ft_rotate(stack_b);
//                 else if ((*stack_a)->r_b == -1)
//                     ft_reverse_rotate(stack_b);
//             }
//             while ((*stack_a)->)
//             {
//                 if ((*stack_b)->r_b == 1)
//                     ft_rotate(stack_b);
//                 else if ((*stack_a)->r_b == -1)
//                     ft_reverse_rotate(stack_b);
//             }           
//         }
//         movs++;
//         (*stack_a) = (*stack_b)->next;
//     }

// }

void    ft_order(t_stack **stack_a, t_stack **stack_b)
{
    int size_b;
    int size_a;
   // t_stack *cheap;

    size_b = ft_count_nodes(*stack_b);
    size_a = ft_count_nodes(*stack_a);
    int n = 1;
    while((*stack_b) && n > 0)
    {
        set_pos_b(stack_b);
        set_pos_a(stack_a);
		get_movs_b(*stack_b, size_b);
        get_movs_a(stack_b, size_b, stack_a, size_a);
        //cheap = find_cheap(*stack_b);
        //move_cheap(cheap, stack_a, stack_b);
       // print_stack(cheap);
		print_stack(*stack_b);
        n--;
    }
	
}
