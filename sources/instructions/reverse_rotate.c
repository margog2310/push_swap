/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:03:44 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/03 21:36:33 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	head = *stack;
	last = ft_stacklast(head);
	while (head)
	{
		if (head->next->next == NULL)
			head->next = NULL;
		head = head->next;
	}
	last->next = *stack;
	*stack = last;
	return (0);
}

int	rra(t_data *data)
{
	if (reverse_rotate(data->a) == -1)
		return (-1);
	apply_op(data->ops, "rra");
	return (0);
}

int	rrb(t_data *data)
{
	if (reverse_rotate(data->b) == -1)
		return (-1);
	apply_op(data->ops, "rrb");
	return (0);
}

int	rrr(t_data *data)
{
	if (ft_stacksize(*data->a) < 2 || ft_stacksize(*data->b) < 2)
		return (-1);
	reverse_rotate(data->a);
	reverse_rotate(data->b);
	apply_op(data->ops, "rrr");
	return (0);
}
