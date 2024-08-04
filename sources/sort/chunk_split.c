/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:41:28 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/04 18:59:12 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk	*init_chunk(int size, enum pos position)
{
	t_chunk	*chunk;

	chunk->size = size;
	chunk->position = position;
	return (chunk);
}

void	first_split(t_data *data)
{
	t_chunk	first_chunk;

	first_chunk.position = TOP_A;
	first_chunk.size = ft_stacksize(*data->a);
	sort_chunk(&first_chunk, data);
}

void	assign_position(t_chunk *to_sort, t_split *split)
{
	if (to_sort->position == TOP_A)
	{
		split->max->position = BOTTOM_A;
		split->mid->position = TOP_B;
		split->min->position = BOTTOM_B;
	}
	else if (to_sort->position == BOTTOM_A)
	{
		split->max->position = TOP_A;
		split->mid->position = TOP_B;
		split->min->position = BOTTOM_B;
	}
	else if (to_sort->position == TOP_B)
	{
		split->max->position = TOP_A;
		split->mid->position = BOTTOM_A;
		split->min->position = BOTTOM_B;
	}
	else if (to_sort->position == BOTTOM_B)
	{
		split->max->position = TOP_A;
		split->mid->position = BOTTOM_A;
		split->mid->position = TOP_B;
	}
}

void	split_chunk(t_chunk *to_sort, t_split *split)
{
	int	size;

	size = to_sort->size;
	split->max->size = size / 3;
	split->mid->size = size / 3;
	split->min->size = size - split->max->size - split->mid->size;
	assign_position(to_sort, split);
}

void	sort_chunk(t_chunk *to_sort, t_data *data)
{
	t_split	split;

	to_top(to_sort, data);
	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
			chunk_sort_3(to_sort, data);
		else if (to_sort->size == 2)
			chunk_sort_2(to_sort, data);
		else if (to_sort->size == 1)
			chunk_sort_1(to_sort, data);
		return ;
	}
	split_chunk(to_sort, &split);
	sort_chunk(&split.max, data);
	sort_chunk(&split.mid, data);
	sort_chunk(&split.min, data);
}
