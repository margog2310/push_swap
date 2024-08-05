/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:56:31 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 04:23:28 by margo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*temp;

	if (ft_stacksize(*stack) <= 1)
		return (-1);
	temp = (*stack)->next;
	if (!temp)
		ft_printf("Error: Swap\n");
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	if (temp->next)
		temp->next->prev = *stack;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
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
	if (ft_stacksize(*data->a) < 2 || ft_stacksize(*data->b) < 2)
		return (-1);
	swap(data->a);
	swap(data->b);
	apply_op(data->ops, "ss");
	return (0);
}
