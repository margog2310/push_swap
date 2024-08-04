/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:06:37 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/04 18:27:14 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3_b(t_data *data)
{
	int	min;

	if (is_sorted(data->b, 'b'))
		return (1);
	min = find_min(data->b);
	if ((*data->b)->value == min)
	{
		rb(data);
		if ((*data->b)->next->value > (*data->b)->value)
			sb(data);
	}
	else if ((*data->b)->next->value == min)
	{
		rrb(data);
		if ((*data->b)->value < (*data->b)->next->value)
			sb(data);
	}
	else if ((*data->b)->next->next->value == min)
		sb(data);
	return (0);
}

int	sort_4_b(t_data *data)
{
	int	max;

	if (is_sorted(data->b, 'b'))
		return (1);
	max = find_max(data->b);
	while ((*data->b)->value != max)
		rb(data);
	if (is_sorted(data->b, 'b'))
		return (1);
	pa(data);
	sort_3_b(data);
	pb(data);
	return (0);
}

int	sort_5_b(t_data *data)
{
	int	max;

	if (is_sorted(data->b, 'b'))
		return (1);
	max = find_max(data->b);
	while ((*data->b)->value != max)
		rb(data);
	if (is_sorted(data->b, 'b'))
		return (1);
	pa(data);
	sort_4_b(data);
	pb(data);
	return (0);
}

int	simple_sort_b(t_data *data, int size)
{
	if (is_sorted(data->b, 'b'))
		return (1);
	if (size == 2)
		sb(data->b);
	if (size == 3)
		sort_3_b(data);
	if (size == 4)
		sort_4_b(data);
	if (size == 5)
		sort_5_b(data);
	return (0);
}
