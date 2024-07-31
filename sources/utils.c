/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:10:12 by mganchev          #+#    #+#             */
/*   Updated: 2024/07/31 21:46:08 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack **stack)
{
	int		min;
	t_stack	*temp;

	temp = *stack;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	find_max(t_stack **stack)
{
	int		max;
	t_stack	*temp;

	temp = *stack;
	max = temp->value;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

void	print_stack(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head)
	{
		ft_printf("%d\n", head->value);
		head = head->next;
	}
}
