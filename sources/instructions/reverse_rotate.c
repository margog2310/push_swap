/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:03:44 by mganchev          #+#    #+#             */
/*   Updated: 2024/07/30 18:37:03 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	last = ft_lstlast(head);
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

int	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
