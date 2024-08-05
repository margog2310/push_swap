/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:13:34 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/06 00:15:45 by mganchev         ###   ########.fr       */
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
	free_memory(data);
	exit(EXIT_SUCCESS);
}
/*
	TO DO:
			1. clean up code
			2. further optimisation??
			3. final norminette(!) + check memory leaks
*/