/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:43:53 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 04:22:35 by margo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data **data, int argc, char *argv[])
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return ;
	(*data)->a = malloc(sizeof(t_stack));
	(*data)->b = malloc(sizeof(t_stack));
	(*data)->ops = malloc(sizeof(t_list));
	if (!(*data)->a || !(*data)->b || !(*data)->ops)
		return (free(*data));
	*((*data)->a) = NULL;
	*((*data)->b) = NULL;
	*((*data)->ops) = NULL;
	fill_stack(*data, (*data)->a, argc, argv);
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

void	fill_stack(t_data *data, t_stack **stack, int argc, char *argv[])
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
		handle_error(data, "Error");
		return ;
	}
	while (args[++i])
		ft_stackadd_back(stack, ft_stacknew(ft_atoi(args[i])));
	index_stack(stack);
	if (argc == 2)
		free_arr(args);
}
