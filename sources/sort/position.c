/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:12:15 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/02 20:10:05 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_value(t_stack **stack_a, t_stack **stack_b, int value,
		enum pos position)
{
	if (position == TOP_A)
	{
		while ((*stack_a)->value != value)
			ra(stack_a);
	}
	else if (position == TOP_B)
	{
		while ((*stack_a)->value != value)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (position == BOTTOM_A)
	{
		while ((*stack_a)->value != value)
			ra(stack_a);
		rra(stack_a);
	}
	else if (position == BOTTOM_B)
	{
		while ((*stack_a)->value != value)
			ra(stack_a);
		pb(stack_a, stack_b);
		while ((*stack_b)->value != value)
			rrb(stack_b);
	}
}
