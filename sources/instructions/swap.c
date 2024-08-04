/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:56:31 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/03 21:39:15 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		temp;

	if (ft_stacksize(*stack) <= 1)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		handle_error("Error: Swap\n");
	temp = head->value;
	head->value = next->value;
	next->value = temp;
	return (0);
}

int	sa(t_data *data)
{
	if (swap(data->a) == -1)
		return (-1);
	apply_op(data->ops, "sa");
	return (0);
}

int	sb(t_data *data)
{
	if (swap(data->b) == -1)
		return (-1);
	apply_op(data->ops, "sb");
	return (0);
}

int	ss(t_data *data)
{
	if (ft_stacksize(data->a) < 2 || ft_stacksize(data->b) < 2)
		return (-1);
	swap(data->a);
	swap(data->b);
	apply_op(data->ops, "ss");
	return (0);
}
