/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:05:22 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/06 00:04:08 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_ta(t_data *data, enum e_pos dest)
{
	if (dest == BOTTOM_A)
		ra(data);
	else if (dest == TOP_B)
		pb(data);
	else if (dest == BOTTOM_B)
	{
		pb(data);
		rb(data);
	}
}

void	move_ba(t_data *data, enum e_pos dest)
{
	if (dest == TOP_A)
		rra(data);
	else if (dest == TOP_B)
	{
		rra(data);
		pb(data);
	}
	else if (dest == BOTTOM_B)
	{
		rra(data);
		pb(data);
		rb(data);
	}
}

void	move_tb(t_data *data, enum e_pos dest)
{
	if (dest == TOP_A)
		pa(data);
	else if (dest == BOTTOM_A)
	{
		pa(data);
		ra(data);
	}
	else if (dest == BOTTOM_B)
		rb(data);
}

void	move_bb(t_data *data, enum e_pos dest)
{
	if (dest == TOP_A)
	{
		rrb(data);
		pa(data);
	}
	else if (dest == BOTTOM_A)
	{
		rrb(data);
		pa(data);
		ra(data);
	}
	else if (dest == TOP_B)
		rrb(data);
}

void	move_to(t_data *data, enum e_pos pos, enum e_pos dest)
{
	if (pos == TOP_A)
		move_ta(data, dest);
	else if (pos == BOTTOM_A)
		move_ba(data, dest);
	else if (pos == TOP_B)
		move_tb(data, dest);
	else if (pos == BOTTOM_B)
		move_bb(data, dest);
}
