/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:29:44 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 00:33:45 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*temp;

	if (ft_stacksize(*stack_from) == 0)
		return (-1);
	temp = *stack_from;
	*stack_from = temp->next;
	if (*stack_from)
		(*stack_from)->prev = NULL;
	if (!*stack_to)
	{
		temp->next = NULL;
		temp->prev = NULL;
	}
	else
	{
		temp->next = *stack_to;
		(*stack_to)->prev = temp;
	}
	*stack_to = temp;
	return (0);
}

int	pa(t_data *data)
{
	if (push(data->a, data->b) == -1)
		return (-1);
	apply_op(data->ops, "pa");
	return (0);
}

int	pb(t_data *data)
{
	if (push(data->b, data->a) == -1)
		return (-1);
	apply_op(data->ops, "pb");
	return (0);
}
