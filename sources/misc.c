/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:44:45 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/06 00:00:51 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_next_node(t_stack *head, enum e_pos position)
{
	if (position == TOP_A || position == TOP_B)
		return (head->next);
	else if (position == BOTTOM_A || position == BOTTOM_B)
		return (head->prev);
	return (NULL);
}

void	free_memory(t_data *data)
{
	if (data)
	{
		if (data->a)
		{
			free_stack(*data->a);
			free(data->a);
		}
		if (data->b)
		{
			free_stack(*data->b);
			free(data->b);
		}
		if (data->ops)
		{
			ft_lstclear(data->ops, free);
			free(data->ops);
		}
		free(data);
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	while (i--)
		free(arr[i]);
	free(arr);
}

void	handle_error(t_data *data, char *error)
{
	free_memory(data);
	ft_putendl_fd(error, 2);
	exit(1);
}
