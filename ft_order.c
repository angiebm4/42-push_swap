/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 06:51:20 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/26 02:47:16 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_too_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	
	size = ft_count_nodes(*stack_a);
	while (size > 3)
	{
		ft_push_b(stack_a, stack_b);
		size--;
	}
}
int is_3sorted(t_stack **stack_a)
{
    if (((*stack_a)->nbr < (*stack_a)->next->nbr) && ((*stack_a)->next->nbr < (*stack_a)->next->next->nbr))
		return (0);
    else
        return (1);
}
int find_3last(t_stack *stack_a)
{
    int i;
    int nbr;
    t_stack *temp;
    
    i = 1;
    temp = stack_a;
    nbr = stack_a->nbr;
    while(stack_a != NULL)
    {
        if (nbr < stack_a->nbr)
            nbr = stack_a->nbr;
        stack_a = stack_a->next;
    }
    while (temp != NULL)
    {
        if (nbr == temp->nbr)
            return (i);
        i++;
        temp = temp->next;
    }
    return (i);
}

void	order_three_nb(t_stack **stack_a)
{
    int i;

    if (is_3sorted(stack_a) == 0)
        return ;
    i = find_3last(*stack_a);
    //printf("%i\n", i);
    if (i == 1)
        ft_rotate_a(stack_a);
    if (i == 2)
        ft_reverse_rotate_a(stack_a);
    if ((*stack_a)->nbr > (*stack_a)->next->nbr)
        ft_swap_a(stack_a);
}

t_stack *find_cheap(t_stack *stack_b)
{
    t_stack *min;
    
    min = stack_b;
    // printf("\n---- STACK_B ----\n");
	// print_stack(stack_b);
    while(stack_b->next != NULL)
    {
        if (stack_b->nb_mov == 0)
            return(stack_b);
        if (stack_b->nb_mov < min->nb_mov)
            min = stack_b;
        stack_b = stack_b->next;
    }
    // printf("uwu ------- %ld\n", min->nbr);
    return(min);
    
}
void	move_cheap(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheap;

    cheap = find_cheap(*stack_b);
    // printf("cheap ------------------> nbr == %ld a == %d b == %d\n", cheap->nbr, cheap->r_a, cheap->r_b);
    // printf("\n---- STACK_A ----\n");
	// print_stack(*stack_a);
	// printf("\n---- STACK_B ----\n");
	// print_stack(*stack_b);
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
    while(cheap->r_a > 0)
    {
        ft_rotate_a(stack_a);
        cheap->r_a -= 1;
    }
    while(cheap->r_b > 0)
    {
        ft_rotate_b(stack_b);
        cheap->r_b -= 1;
    }
    while(cheap->r_a < 0)
    {
        ft_reverse_rotate_a(stack_a);
        cheap->r_a += 1;
    }
    while(cheap->r_b < 0)
    {
        ft_reverse_rotate_b(stack_b);
        cheap->r_b += 1;
    }
    ft_push_a(stack_a, stack_b);
}
void    init_movs(t_stack *stack_b)
{
    while(stack_b)
    {
        stack_b->nb_mov = 0;
        stack_b->r_b = 0;
        stack_b->r_a = 0;
        stack_b = stack_b->next;
    }
}
void    last_order(t_stack **stack_a)
{
    t_stack *first;
    int     size_a;
    
    size_a = ft_count_nodes(*stack_a);
    first = find_first(*stack_a);
    if (first->pos <= (size_a / 2) - 1)
    {
        while(first->prev != NULL)
            ft_rotate_a(stack_a);
    }
    else
    {
        while(first->prev != NULL)
            ft_reverse_rotate_a(stack_a);
    }
}


void	order_nodes(t_stack **stack_a, t_stack **stack_b)
{
    int size_b;
    int size_a;
    // printf("\n---- STACK_A ----\n");
    // print_stack(*stack_a);
	// printf("\n---- STACK_B ----\n");
	// print_stack(*stack_b);
    while(*stack_b != NULL)
    {
        size_b = ft_count_nodes(*stack_b);
        size_a = ft_count_nodes(*stack_a);
	    set_pos(stack_a);
	    set_pos(stack_b);
        get_movs_b(*stack_b, size_b);
        get_movs_a(*stack_b, *stack_a, size_a); 
        check_if_double_r(*stack_b);
        // printf("\n---- STACK_A ----\n");
	    // print_stack(*stack_a);
	    // printf("\n---- STACK_B ----\n");
	    // print_stack(*stack_b);
        move_cheap(stack_a, stack_b);
        init_movs(*stack_b);
        // printf("\n---- STACK_A ----\n");
	    // print_stack(*stack_a);
	    // printf("\n---- STACK_B ----\n");
	    // print_stack(*stack_b);
    }
    last_order(stack_a);
    // printf("\n---- STACK_A ----\n");
	// print_stack(*stack_a);
	// printf("\n---- STACK_B ----\n");
	// print_stack(*stack_b);
    //terminar min en toop 
}
