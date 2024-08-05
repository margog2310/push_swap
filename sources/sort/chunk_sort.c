/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:31:06 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/04 21:05:44 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort_1(t_chunk *to_sort, t_data *data)
{
	if (to_sort->position != TOP_A)
		move_to(data, to_sort->position, TOP_A);
	to_sort->size -= 1;
}

void	chunk_sort_2(t_chunk *to_sort, t_data *data)
{
	if (to_sort->position != TOP_A)
	{
		move_to(data, to_sort->position, TOP_A);
		move_to(data, to_sort->position, TOP_A);
	}
	if ((*data->a)->rank > (*data->a)->next->rank)
		sa(data);
	to_sort->size -= 2;
}
