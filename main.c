/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:28:23 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/09 18:55:09 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *aux;
	
	while(stack_a)
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
	(*stack)->index = 0;
	(*stack)->nbr = 0;
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	return(*stack);
}
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

void	leaks()
{
	system("leaks -q push_swap");
}

int main(int argc, char *argv[])
{
	atexit(leaks);

	t_stack *stack_a;
	t_stack *stack_b;
	t_stack	*aux;
	
	if (argc <= 1)
		return(0);
	stack_a = NULL;
	stack_b = NULL;
	get_nodes(&stack_a, argv);
	// aux = stack_a;
	// ft_reverse_rotate(&stack_a);
	// while(stack_a != NULL)
	// {
	// 	printf("%ld\n", stack_a->nbr);
	// 	stack_a = stack_a->next;
	// }
	// stack_a = aux;
	
	if (check_errors(stack_a) == 1)
	{
		delete_stacks(stack_a, NULL);
		return(write(2, "Error\n", 6));
	}
	ft_get_index(&stack_a);
	push_too_b(&stack_a, &stack_b);
	aux = stack_b;
	while(stack_b != NULL)
	{
		printf("%ld\n", stack_b->nbr);
		stack_b = stack_b->next;
	}
	stack_b = aux;
	delete_stacks(stack_a, stack_b);
	return (0);
}
