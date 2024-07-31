/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:43:53 by mganchev          #+#    #+#             */
/*   Updated: 2024/07/31 22:48:32 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_stack(t_stack **stack, int argc, char *argv[])
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

void	index_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*current;
	int		index;

	current = *stack;
	while (current)
	{
		index = 1;
		head = *stack;
		while (head)
		{
			if (head->value < current->value)
				index++;
			head = head->next;
		}
		current->index = index;
		current = current->next;
	}
}
