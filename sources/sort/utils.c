/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:21:49 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 05:00:44 by margo            ###   ########.fr       */
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
// use temp_rank + index_chunk instead
void	set_pivots(t_data *data, t_chunk *to_sort, int *min_pivot,
		int *mid_pivot)
{
	int		size;
	int		step;
	t_stack	*head;

	size = to_sort->size;
	head = return_stack(data, to_sort->position);
	if (to_sort->position == BOTTOM_A || to_sort->position == BOTTOM_B)
		head = ft_stacklast(head);
	step = 1;
	while (step <= 2 * (size / 3))
	{
		if (step == size / 3)
			*min_pivot = head->rank;
		if (step == 2 * (size / 3))
			*mid_pivot = head->rank;
		head = get_next_node(head, to_sort->position);
		step++;
	}
}

void	move_chunks(t_data *data, t_chunk *to_sort, t_split *split)
{
	int		size;
	int		min_pivot;
	int		mid_pivot;
	t_stack	*head;
	t_stack	*next;

	next = NULL;
	size = to_sort->size;
	head = return_stack(data, to_sort->position);
	if (to_sort->position == BOTTOM_A || to_sort->position == BOTTOM_B)
		head = ft_stacklast(head);
	set_pivots(data, to_sort, &min_pivot, &mid_pivot);
	while (size--)
	{
		next = get_next_node(head, to_sort->position);
		if (head->rank <= min_pivot)
			move_to(data, to_sort->position, split->min.position);
		else if (head->rank <= mid_pivot)
			move_to(data, to_sort->position, split->mid.position);
		else
			move_to(data, to_sort->position, split->max.position);
		head = next;
	}
}
