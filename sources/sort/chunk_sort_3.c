/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:51:28 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 00:36:58 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort_3(t_chunk *to_sort, t_data *data)
{
	if (to_sort->position == TOP_A)
		sort_3_TA(to_sort, data);
	else if (to_sort->position == BOTTOM_A)
		sort_3_BA(to_sort, data);
	else if (to_sort->position == TOP_B)
		sort_3_TB(to_sort, data);
	else if (to_sort->position == BOTTOM_B)
		sort_3_BB(to_sort, data);
}

void	sort_3_TA(t_chunk *to_sort, t_data *data)
{
	int	max;

	max = chunk_max(to_sort, data);
	if ((*data->a)->rank == max)
	{
		sa(data);
		ra(data);
		sa(data);
		rra(data);
	}
	else if ((*data->a)->next->rank == max)
	{
		ra(data);
		sa(data);
		rra(data);
	}
	to_sort->position = TOP_A;
	chunk_sort_2(to_sort, data);
}

void	sort_3_TB(t_chunk *to_sort, t_data *data)
{
	int	max;

	max = chunk_max(to_sort, data);
	pa(data);
	if ((*data->b)->rank == max)
	{
		pa(data);
		sa(data);
	}
	else if ((*data->b)->next->rank == max)
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

void	sort_3_BA(t_chunk *to_sort, t_data *data)
{
	int	max;

	max = chunk_max(to_sort, data);
	rra(data);
	rra(data);
	if ((*data->a)->rank == max)
	{
		sa(data);
		rra(data);
	}
	else if ((*data->a)->next->rank == max)
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

void	sort_3_BB(t_chunk *to_sort, t_data *data)
{
	int	max;

	max = chunk_max(to_sort, data);
	rrb(data);
	rrb(data);
	if ((*data->b)->rank == max)
	{
		pa(data);
		rrb(data);
	}
	else if ((*data->b)->next->rank == max)
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
