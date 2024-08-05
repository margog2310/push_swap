/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:44:45 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/04 22:51:23 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_memory(t_data *data)
{
	if (data)
	{
		if (data->a)
		{
			free(*data->a);
			free(data->a);
		}
		if (data->b)
		{
			free(*data->b);
			free(data->b);
		}
		if (data->ops)
			ft_lstclear(data->ops, free);
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

void handle_error(char *error)
{
	ft_putendl_fd(error, 1);
	exit(0);
}
