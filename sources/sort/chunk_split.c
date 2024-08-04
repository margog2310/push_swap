/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:41:28 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/04 02:22:00 by mganchev         ###   ########.fr       */
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
// not in header
void	split_chunk(t_data *data, int chunk_size)
{
	int	i;

	i = 0;
	while (i <= ft_stacksize(*data->a))
	{
		if ((*data->a)->rank <= chunk_size)
			move_to(data, TOP_A, BOTTOM_B);
		else if ((*data->a)->rank <= (chunk_size * 2))
			move_to(data, TOP_A, TOP_B);
		else
			move_to(data, TOP_A, BOTTOM_A);
		i++;
	}
}
// not in header
void	sort_chunk(t_chunk *to_sort, t_data *data)
{
	t_split	*dest;

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
	// continue splitting
	// sort chunk rec for max
	// sort chunk rec for mid
	// sort chunk rec for min
}

t_split	first_split(t_data *data)
{
	t_chunk	first_chunk;

	first_chunk.position = TOP_A;
	first_chunk.size = ft_stacksize(*data->a);
	sort_chunks(&first_chunk, data);
}
