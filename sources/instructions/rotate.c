/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:48:41 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 00:47:27 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	head = *stack;
	last = ft_stacklast(head);
	*stack = head->next;
	(*stack)->prev = NULL;
	head->next = NULL;
	head->prev = last;
	last->next = head;
	return (0);
}

int	ra(t_data *data)
{
	if (rotate(data->a) == -1)
		return (-1);
	apply_op(data->ops, "ra");
	return (0);
}

int	rb(t_data *data)
{
	if (rotate(data->b) == -1)
		return (-1);
	apply_op(data->ops, "rb");
	return (0);
}

int	rr(t_data *data)
{
	if (ft_stacksize(*data->a) < 2 || ft_stacksize(*data->b) < 2)
		return (-1);
	rotate(data->a);
	rotate(data->b);
	apply_op(data->ops, "rr");
	return (0);
}
