/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 01:24:15 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 23:58:10 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rank(t_stack **stack, int rank)
{
	t_stack	*head;

	head = *stack;
	while (head)
	{
		if (head->rank == rank)
			return (head->rank);
		head = head->next;
	}
	return (-1);
}

void	rank_chunk(t_data *data, t_chunk *chunk)
{
	t_stack	*head;
	t_stack	*current;
	int		rank;
	int		size;
	int		counter;

	size = chunk->size;
	current = return_stack(data, chunk->position);
	while (size && current)
	{
		rank = 1;
		counter = chunk->size;
		head = return_stack(data, chunk->position);
		while (counter-- && head)
		{
			if (head->value < current->value)
				rank++;
			head = get_next_node(head, chunk->position);
		}
		current->chunk_rank = rank;
		current = get_next_node(current, chunk->position);
		size--;
	}
}
