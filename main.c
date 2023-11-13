/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:28:23 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/13 14:53:46 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*divide_stack(t_stack **stack_a, char *str)
{
	t_stack	*head;
	int		i;
	char	**split;
	long	nb;

	i = 0;
	split = ft_split(str, ' ');
	nb = 0;
	head = ft_init_stack(stack_a);
	while (split[i])
	{
		(*stack_a)->nbr = ft_strict_atoi(split[i], *stack_a);
		if (split[++i])
		{
			(*stack_a)->next = ft_init_stack(&(*stack_a)->next);
			(*stack_a)->next->prev = (*stack_a);
			(*stack_a) = (*stack_a)->next;
		}
	}
	ft_free_split(split);
	return (head);
}

void	get_nodes(t_stack **stack_a, char *argv[])
{
	int		i;
	char	*str;

	i = 1;
	str = NULL;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '\0')
			break ;
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	(*stack_a) = divide_stack(stack_a, str);
	free(str);
}

void	leaks(void)
{
	system("leaks -q push_swap");
}
void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("NODO\n");
		printf("\tnbr - %ld\n", stack->nbr);
		printf("\terror - %d\n", stack->error);
		printf("\tnb_mov - %d\n", stack->nb_mov);
		printf("\tindex - %ld\n", stack->index);
		printf("\tpos_a - %d\n", stack->pos_a);
		printf("\tpos_b - %d\n", stack->pos_b);
		printf("\tr_b - %d\n", stack->r_b);
		printf("\tr_a - %d\n", stack->r_a);
		stack = stack->next;
	}
}
int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	atexit(leaks);
	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	get_nodes(&stack_a, argv);
	// print_stack(stack_a);
	if (check_errors(stack_a) == 1)
	{
		delete_stacks(stack_a, NULL);
		return (write(2, "Error\n", 6));
	}
	check_ok_stack(stack_a);
	ft_get_index(&stack_a);
	push_too_b(&stack_a, &stack_b);
	// print_stack(stack_a);
	order_three_nb(&stack_a, 4);
	// print_stack(stack_a);
	// printf("================\n");
	ft_order(&stack_a, &stack_b);
	// print_stack(stack_b);
	delete_stacks(stack_a, stack_b);
	return (0);
}
