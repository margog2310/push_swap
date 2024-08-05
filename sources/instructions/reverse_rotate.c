/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:03:44 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 00:48:35 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	last = ft_stacklast(*stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
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
