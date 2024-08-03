/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:29:44 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/02 21:52:23 by mganchev         ###   ########.fr       */
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

int	pa(t_stack **stack_a, t_stack **stack_b, t_list **ops)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	apply_op(ops, "pa");
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b, t_list **ops)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	apply_op(ops, "pb");
	return (0);
}
