/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:21:49 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/02 22:28:32 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_next(t_list *current, void (*del)(void *))
{
	t_list	*next;

	next = current->next;
	if (next)
	{
		current->next = next->next;
		ft_lstdelone(next, del);
	}
}

void	remove_current(t_list **ops, t_list *current, void (*del)(void *))
{
	t_list	*prev;

	prev = *ops;
	if (prev == current)
	{
		*ops = current->next;
		ft_lstdelone(current, del);
	}
	else
	{
		while (prev && prev->next != current)
			prev = prev->next;
		if (prev)
		{
			prev->next = current->next;
			ft_lstdelone(current, del);
		}
	}
}
