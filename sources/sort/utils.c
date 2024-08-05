/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:21:49 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 01:47:59 by mganchev         ###   ########.fr       */
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

int	get_current_rank(t_stack *head, int size)
{
	int		i;
	int		rank;
	t_stack	*temp;

	i = size;
	rank = 1;
	temp = head->next;
	while (i-- && temp != NULL)
	{
		if (temp->value < head->value)
			rank++;
		temp = temp->next;
	}
	return (rank);
}

void	move_chunks(t_data *data, t_chunk *to_sort, t_split *split)
{
	int		size;
	float	rank;
	t_stack	*head;
	t_stack	*next;

	next = NULL;
	size = to_sort->size;
	head = return_stack(data, to_sort->position);
	if (to_sort->position == BOTTOM_A || to_sort->position == BOTTOM_B)
		head = ft_stacklast(head);
	while (size--)
	{
		rank = get_current_rank(head, to_sort->size);
		if (to_sort->position == TOP_A || to_sort->position == TOP_B)
			next = head->next;
		else if (to_sort->position == BOTTOM_A || to_sort->position == BOTTOM_B)
			next = head->prev;
		if (rank <= split->min.size)
			move_to(data, to_sort->position, split->min.position);
		else if (rank <= split->min.size * 2)
			move_to(data, to_sort->position, split->mid.position);
		else if (rank <= split->max.size * 3)
			move_to(data, to_sort->position, split->max.position);
		head = next;
	}
}
