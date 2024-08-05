/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:29:11 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 23:27:57 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3_a(t_data *data)
{
	int	max;

	if (is_sorted(data->a, 'a'))
		return (1);
	max = find_max(data->a);
	if ((*data->a)->rank == max)
	{
		ra(data);
		if ((*data->a)->next->rank < (*data->a)->rank)
			sa(data);
	}
	else if ((*data->a)->next->rank == max)
	{
		rra(data);
		if ((*data->a)->rank > (*data->a)->next->rank)
			sa(data);
	}
	else if ((*data->a)->next->next->rank == max)
		sa(data);
	return (0);
}

int	sort_4_a(t_data *data)
{
	t_stack	*last;
	int		min;

	if (is_sorted(data->a, 'a'))
		return (1);
	min = find_min(data->a);
	last = ft_stacklast(*data->a);
	if (last->rank == min)
		rra(data);
	else
	{
		while ((*data->a)->rank != min)
			ra(data);
	}
	if (is_sorted(data->a, 'a'))
		return (1);
	pb(data);
	sort_3_a(data);
	pa(data);
	return (0);
}

int	sort_5_a(t_data *data)
{
	t_stack	*last;
	int		min;

	if (is_sorted(data->a, 'a'))
		return (1);
	min = find_min(data->a);
	last = ft_stacklast(*data->a);
	if (last->rank == min || last->prev->rank == min)
	{
		while ((*data->a)->rank != min)
			rra(data);
	}
	else
	{
		while ((*data->a)->rank != min)
			ra(data);
	}
	if (is_sorted(data->a, 'a'))
		return (1);
	pb(data);
	sort_4_a(data);
	pa(data);
	return (0);
}

int	simple_sort_a(t_data *data, int size)
{
	if (is_sorted(data->a, 'a'))
		return (1);
	if (size == 2)
		sa(data);
	if (size == 3)
		sort_3_a(data);
	if (size == 4)
		sort_4_a(data);
	if (size == 5)
		sort_5_a(data);
	return (0);
}
