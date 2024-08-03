/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:03:44 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/02 22:02:50 by mganchev         ###   ########.fr       */
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

int	rra(t_stack **stack_a, t_stack **stack_b, t_list **ops)
{
	(void)stack_b;
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	apply_op(ops, "rra");
	return (0);
}

int	rrb(t_stack **stack_b, t_stack **stack_a, t_list **ops)
{
	(void)stack_a;
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	apply_op(ops, "rrb");
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b, t_list **ops)
{
	if (ft_stacksize(*stack_a) < 2 || ft_stacksize(*stack_b) < 2)
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	apply_op(ops, "rrr");
	return (0);
}
