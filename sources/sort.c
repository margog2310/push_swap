/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:29:11 by mganchev          #+#    #+#             */
/*   Updated: 2024/07/31 00:02:41 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_stack **stack)
{
	t_stack	*head;
	int		max;

	head = *stack;
	max = find_max(head);
	if (is_sorted(stack))
		return (1);
	if (head->value == max)
	{
		ra(stack);
		if (head->next->value > head->value)
			sa(stack);
	}
	else if (head->next->value == max)
	{
		rra(stack);
		if (head->value > head->next->value)
			sa(stack);
	}
	else if (head->next->next->value != max)
		sa(stack);
	return (0);
}

int	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	int		min;

	if (is_sorted(stack_a))
		return ;
	head = *stack_a;
	min = find_min(head);
	while (head->value != min)
	{
		ra(stack_a);
		head = head->next;
	}
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	return (0);
}

int	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	if (is_sorted(stack_a))
		return ;
	min = find_min(stack_a);
	if ((*stack_a)->next->value == min)
		rra(stack_a);
	else
	{
		while ((*stack_a)->value != min)
			ra(stack_a);
	}
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (0);
}

int simple_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
    if (is_sorted(stack_a))
        return ;
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
