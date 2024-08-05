/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:12:15 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 23:14:28 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_top(t_chunk *to_sort, t_data *data)
{
	if (to_sort->position == BOTTOM_A
		&& ft_stacksize(*data->a) == to_sort->size)
		to_sort->position = TOP_A;
	if (to_sort->position == BOTTOM_B
		&& ft_stacksize(*data->b) == to_sort->size)
		to_sort->position = TOP_B;
}

void	init_split(t_split *split)
{
	split->max.size = 0;
	split->mid.size = 0;
	split->min.size = 0;
}

int	chunk_min(t_chunk *chunk, t_data *data)
{
	int		min;
	int		size;
	t_stack	*head;

	min = 0;
	size = chunk->size;
	head = return_stack(data, chunk->position);
	while (size)
	{
		if (head->chunk_rank < min)
			min = head->chunk_rank;
		head = get_next_node(head, chunk->position);
		size--;
	}
	return (min);
}

int	chunk_max(t_chunk *chunk, t_data *data)
{
	int		max;
	int		size;
	t_stack	*head;

	max = 0;
	size = chunk->size;
	head = return_stack(data, chunk->position);
	while (size)
	{
		if (head->chunk_rank > max)
			max = head->chunk_rank;
		head = get_next_node(head, chunk->position);
		size--;
	}
	return (max);
}

bool	chunk_is_sorted(t_chunk *chunk, t_data *data)
{
	int		size;
	t_stack	*head;

	size = chunk->size;
	head = return_stack(data, chunk->position);
	while (size)
	{
		if (chunk->position == TOP_A || chunk->position == BOTTOM_A)
		{
			if (head->chunk_rank > head->next->chunk_rank)
				return (false);
		}
		else if (chunk->position == TOP_B || chunk->position == BOTTOM_B)
		{
			if (head->chunk_rank < head->next->chunk_rank)
				return (false);
		}
		head = head->next;
		size--;
	}
	return (true);
}
