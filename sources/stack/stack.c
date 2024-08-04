/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:43:53 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/03 21:31:52 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data, int argc, char *argv[])
{
	data->a = malloc(sizeof(t_stack));
	data->b = malloc(sizeof(t_stack));
	fill_stack(data->a, argc, argv);
	data->b = NULL;
	data->ops = NULL;
}

void	index_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*current;
	int		rank;

	current = *stack;
	while (current)
	{
		rank = 1;
		head = *stack;
		while (head)
		{
			if (head->value < current->value)
				rank++;
			head = head->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

void	fill_stack(t_stack **stack, int argc, char *argv[])
{
	int		i;
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		i = -1;
	}
	else
	{
		args = argv;
		i = 0;
	}
	if (!check_args(args))
	{
		if (argc == 2)
			free_arr(args);
		ft_printf("Error\n");
	}
	while (args[++i])
		ft_stackadd_back(stack, ft_stacknew(ft_atoi(args[i])));
	index_stack(stack);
	if (argc == 2)
		free_arr(args);
}
