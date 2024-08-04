/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:13:34 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/04 18:13:48 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc < 2)
		return (-1);
	init_data(data, argc, argv);
	if (is_sorted(data->a, 'a'))
	{
		free_stack(data->a);
		free_stack(data->b);
		exit(EXIT_SUCCESS);
	}
	sort_stack(data);
	print_stack(data->a);
	free_stack(data->a);
	free_stack(data->b);
	ft_lstclear(data->ops, free);
	exit(EXIT_SUCCESS);
}
/*
	TO DO:
			1. use index of elements instead of values for sorting
			2. start implementing sorting algorithm
				- add function that checks if chunk is sorted and then moves it to TOP_A based on size
				- try optimising base case for 4 and 5 numbers
			3. testing + optimisation
			4. norminette(!) + check memory leaks
*/