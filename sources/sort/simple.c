/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:29:11 by mganchev          #+#    #+#             */
/*   Updated: 2024/07/31 22:27:53 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_stack **stack)
{
	int		max;

	if (is_sorted(stack))
		return (1);
	max = find_max(stack);
	if ((*stack)->value == max)
	{
		ra(stack);
		if ((*stack)->next->value < (*stack)->value)
			sa(stack);
	}
	else if ((*stack)->next->value == max)
	{
		rra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
	else if ((*stack)->next->next->value == max)
		sa(stack);
	return (0);
}

int	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int		min;

	if (is_sorted(stack_a))
		return (1);
	min = find_min(stack_a);
	while ((*stack_a)->value != min)
		ra(stack_a);
	if (is_sorted(stack_a))
		return (1);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	return (0);
}

int	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	if (is_sorted(stack_a))
		return (1);
	min = find_min(stack_a);
	while ((*stack_a)->value != min)
		ra(stack_a);
	if (is_sorted(stack_a))
		return (1);
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (0);
}

int simple_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
    if (is_sorted(stack_a))
        return (1);
    if (size == 2)
        sa(stack_a);
    if (size == 3)
        sort_3(stack_a);
    if (size == 4)
        sort_4(stack_a, stack_b);
    if (size == 5)
        sort_5(stack_a, stack_b);
    return (0);
}
