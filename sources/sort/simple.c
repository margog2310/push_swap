/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:29:11 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/02 23:24:28 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_stack **stack, t_list **ops)
{
	int	max;

	if (is_sorted(stack))
		return (1);
	max = find_max(stack);
	if ((*stack)->value == max)
	{
		ra(stack, NULL, ops);
		if ((*stack)->next->value < (*stack)->value)
			sa(stack, NULL, ops);
	}
	else if ((*stack)->next->value == max)
	{
		rra(stack, NULL, ops);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack, NULL, ops);
	}
	else if ((*stack)->next->next->value == max)
		sa(stack, NULL, ops);
	return (0);
}

int	sort_4(t_stack **stack_a, t_stack **stack_b, t_list **ops)
{
	int	min;

	if (is_sorted(stack_a))
		return (1);
	min = find_min(stack_a);
	while ((*stack_a)->value != min)
		ra(stack_a, NULL, ops);
	if (is_sorted(stack_a))
		return (1);
	pb(stack_a, stack_b, ops);
	sort_3(stack_a, ops);
	pa(stack_a, stack_b, ops);
	return (0);
}

int	sort_5(t_stack **stack_a, t_stack **stack_b, t_list **ops)
{
	int	min;

	if (is_sorted(stack_a))
		return (1);
	min = find_min(stack_a);
	while ((*stack_a)->value != min)
		ra(stack_a, NULL, ops);
	if (is_sorted(stack_a))
		return (1);
	pb(stack_a, stack_b, ops);
	sort_4(stack_a, stack_b, ops);
	pa(stack_a, stack_b, ops);
	return (0);
}

int	simple_sort(t_stack **stack_a, t_stack **stack_b, int size, t_list **ops)
{
	if (is_sorted(stack_a))
		return (1);
	if (size == 2)
		sa(stack_a, NULL, ops);
	if (size == 3)
		sort_3(stack_a, ops);
	if (size == 4)
		sort_4(stack_a, stack_b, ops);
	if (size == 5)
		sort_5(stack_a, stack_b, ops);
	return (0);
}
