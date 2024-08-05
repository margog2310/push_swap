/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:13:34 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 01:57:26 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc < 2)
		return (-1);
	data = NULL;
	init_data(&data, argc, argv);
	if (is_sorted(data->a, 'a'))
	{
		free_memory(data);
		exit(EXIT_SUCCESS);
	}
	sort_stack(data);
	print_stack(data->a);
	free_memory(data);
	exit(EXIT_SUCCESS);
}
/*
	TO DO:
			1. use index of elements instead of ranks for sorting
			2. start implementing sorting algorithm
				- figure out reranking of the chunks while splitting
				- try optimising base case for 4 and 5 numbers
			3. testing + optimisation
			4. norminette(!) + check memory leaks
*/