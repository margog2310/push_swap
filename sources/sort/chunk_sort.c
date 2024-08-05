/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:31:06 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 21:55:56 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort_1(t_chunk *to_sort, t_data *data)
{
	if (to_sort->position == BOTTOM_A || to_sort->position == TOP_B
		|| to_sort->position == BOTTOM_B)
		move_to(data, to_sort->position, TOP_A);
}

void	chunk_sort_2(t_chunk *to_sort, t_data *data)
{
	if (to_sort->position == BOTTOM_A || to_sort->position == TOP_B
		|| to_sort->position == BOTTOM_B)
	{
		move_to(data, to_sort->position, TOP_A);
		move_to(data, to_sort->position, TOP_A);
	}
	if ((*data->a)->chunk_rank > (*data->a)->next->chunk_rank)
		sa(data);
}
