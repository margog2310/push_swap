/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:44:45 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 04:40:13 by margo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_next_node(t_stack *head, enum pos position)
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
}

void	handle_error(t_data *data, char *error)
{
	free_memory(data);
	ft_putendl_fd(error, 1);
	exit(0);
}
