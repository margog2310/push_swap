/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:10:12 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 00:36:58 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*return_stack(t_data *data, enum pos position)
{
	if (position == TOP_A || position == BOTTOM_A)
		return (*(data->a));
	else
		return (*(data->b));
}

int	find_min(t_stack **stack)
{
	int		min;
	t_stack	*temp;

	temp = *stack;
	min = temp->rank;
	while (temp)
	{
		if (temp->rank < min)
			min = temp->rank;
		temp = temp->next;
	}
	return (min);
}

int	find_max(t_stack **stack)
{
	int		max;
	t_stack	*temp;

	temp = *stack;
	max = temp->rank;
	while (temp)
	{
		if (temp->rank > max)
			max = temp->rank;
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
		ft_printf("%d\n", head->rank);
		head = head->next;
	}
}

void	print_list(t_list **lst)
{
	t_list	*head;

	head = *lst;
	while (head)
	{
		ft_printf("%s\n", head->content);
		head = head->next;
	}
}
