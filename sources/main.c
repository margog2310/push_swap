/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:13:34 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/02 23:25:05 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (-1);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	initialise_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_SUCCESS);
	}
	sort_stack(stack_a, stack_b);
	print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(EXIT_SUCCESS);
}
/*
	TO DO:
			1. use index of elements instead of values for sorting
			2. start implementing sorting algorithm
			3. testing + optimisation
			4. norminette(!) + check memory leaks
*/