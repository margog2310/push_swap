/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:29:11 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/03 21:45:21 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_data *data)
{
	int	max;

	if (is_sorted(data->a))
		return (1);
	max = find_max(data->a);
	if ((*data->a)->value == max)
	{
		ra(data);
		if ((*data->a)->next->value < (*data->a)->value)
			sa(data);
	}
	else if ((*data->a)->next->value == max)
	{
		rra(data);
		if ((*data->a)->value > (*data->a)->next->value)
			sa(data);
	}
	else if ((*data->a)->next->next->value == max)
		sa(data);
	return (0);
}

int	sort_4(t_data *data)
{
	int	min;

	if (is_sorted(data->a))
		return (1);
	min = find_min(data->a);
	while ((*data->a)->value != min)
		ra(data);
	if (is_sorted(data->a))
		return (1);
	pb(data);
	sort_3(data);
	pa(data);
	return (0);
}

int	sort_5(t_data *data)
{
	int	min;

	if (is_sorted(data->a))
		return (1);
	min = find_min(data->a);
	while ((*data->a)->value != min)
		ra(data);
	if (is_sorted(data->a))
		return (1);
	pb(data);
	sort_4(data);
	pa(data);
	return (0);
}

int	simple_sort(t_data *data, int size)
{
	if (is_sorted(data->a))
		return (1);
	if (size == 2)
		sa(data->a);
	if (size == 3)
		sort_3(data);
	if (size == 4)
		sort_4(data);
	if (size == 5)
		sort_5(data);
	return (0);
}
