/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:27:03 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/13 12:16:58 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "color.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_stack
{
    long            nbr;
    long            index;
    int             error;
    int             pos_b;
    int             pos_a;
    int             nb_mov;
	int				r_a;
	int				r_b;
   
    struct s_stack  *next;
    struct s_stack  *prev;
}               t_stack;

int		ft_strict_atoi(char *str, t_stack *stack_a);
void	print_stack(t_stack *stack);

//check errors
int		check_errors(t_stack *stack_a);

//utils
void	delete_stacks(t_stack *stack_a, t_stack *stack_b);
t_stack	*ft_init_stack(t_stack **stack);
int		ft_count_nodes(t_stack *stack);
void	check_ok_stack(t_stack *stack_a);

//algoritmo
void	ft_get_index(t_stack **stack_a);
void	push_too_b(t_stack **stack_a, t_stack **stack_b);
void	order_three_nb(t_stack **stack_a, int i);
void    ft_order(t_stack **stack_a, t_stack **stack_b);

//mov swap
void	ft_swap(t_stack **stack);
void	ft_swap_a(t_stack **stack_a);
void	ft_swap_b(t_stack **stack_b);
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b);

//mov push
void	ft_push(t_stack **stack1, t_stack **stack2);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);

//mov rotate
void	ft_rotate(t_stack **stack);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);

//mov reverse rotate
void	ft_reverse_rotate(t_stack **stack);
void	ft_reverse_rotate_a(t_stack **stack_a);
void	ft_reverse_rotate_b(t_stack **stack_b);
void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

#endif




