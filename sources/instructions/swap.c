/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:56:31 by mganchev          #+#    #+#             */
/*   Updated: 2024/07/31 18:34:24 by mganchev         ###   ########.fr       */
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

int	sa(t_stack **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_stack **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) < 2 || ft_stacksize(*stack_b) < 2)
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
