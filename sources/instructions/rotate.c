/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:48:41 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/02 22:00:56 by mganchev         ###   ########.fr       */
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
	head->next = NULL;
	last->next = head;
	return (0);
}

int	ra(t_stack **stack_a, t_stack **stack_b, t_list **ops)
{
	(void)stack_b;
	if (rotate(stack_a) == -1)
		return (-1);
	apply_op(ops, "ra");
	return (0);
}

int	rb(t_stack **stack_b, t_stack **stack_a, t_list **ops)
{
	(void)stack_a;
	if (rotate(stack_b) == -1)
		return (-1);
	apply_op(ops, "rb");
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b, t_list **ops)
{
	if (ft_stacksize(*stack_a) < 2 || ft_stacksize(*stack_b) < 2)
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	apply_op(ops, "rr");
	return (0);
}
