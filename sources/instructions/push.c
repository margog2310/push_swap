/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:29:44 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/03 21:35:14 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*temp;
	t_stack	*head_to;
	t_stack	*head_from;

	if (ft_stacksize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	temp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = temp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		temp->next = head_to;
		*stack_to = temp;
	}
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
