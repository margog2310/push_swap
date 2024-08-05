/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:51:28 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 23:50:23 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort_3(t_chunk *to_sort, t_data *data)
{
	if (to_sort->position == TOP_A)
		sort_3_ta(to_sort, data);
	else if (to_sort->position == BOTTOM_A)
		sort_3_ba(to_sort, data);
	else if (to_sort->position == TOP_B)
		sort_3_tb(to_sort, data);
	else if (to_sort->position == BOTTOM_B)
		sort_3_bb(to_sort, data);
}

void	sort_3_ta(t_chunk *to_sort, t_data *data)
{
	int	max;

	max = chunk_max(to_sort, data);
	if ((*data->a)->chunk_rank == max)
	{
		sa(data);
		ra(data);
		sa(data);
		rra(data);
	}
	else if ((*data->a)->next->chunk_rank == max)
	{
		ra(data);
		sa(data);
		rra(data);
	}
	to_sort->position = TOP_A;
	chunk_sort_2(to_sort, data);
}

void	sort_3_tb(t_chunk *to_sort, t_data *data)
{
	int	max;

	max = chunk_max(to_sort, data);
	pa(data);
	if ((*data->b)->chunk_rank == max)
	{
		pa(data);
		sa(data);
	}
	else if ((*data->b)->next->chunk_rank == max)
	{
		sb(data);
		pa(data);
		sa(data);
	}
	else
		pa(data);
	pa(data);
	to_sort->position = TOP_A;
	chunk_sort_2(to_sort, data);
}

void	sort_3_ba(t_chunk *to_sort, t_data *data)
{
	int	max;

	max = chunk_max(to_sort, data);
	rra(data);
	rra(data);
	if ((*data->a)->chunk_rank == max)
	{
		sa(data);
		rra(data);
	}
	else if ((*data->a)->next->chunk_rank == max)
		rra(data);
	else
	{
		pb(data);
		rra(data);
		sa(data);
		pa(data);
	}
	to_sort->position = TOP_A;
	chunk_sort_2(to_sort, data);
}

void	sort_3_bb(t_chunk *to_sort, t_data *data)
{
	int	max;

	max = chunk_max(to_sort, data);
	rrb(data);
	rrb(data);
	if ((*data->b)->chunk_rank == max)
	{
		pa(data);
		rrb(data);
	}
	else if ((*data->b)->next->chunk_rank == max)
	{
		sb(data);
		pa(data);
		rrb(data);
	}
	else
	{
		rrb(data);
		pa(data);
	}
	to_sort->position = TOP_B;
	chunk_sort_2(to_sort, data);
}
