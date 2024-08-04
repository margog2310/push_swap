/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:19:58 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/03 23:50:50 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->rank = -1;
	new->next = NULL;
	return (new);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		new->prev = NULL;
		return ;
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*next;
	t_stack	*last;

	last = NULL;
	if (stack == NULL)
		return (NULL);
	next = stack;
	while (next)
	{
		if (next->next == NULL)
		{
			last = next;
			break ;
		}
		next = next->next;
	}
	return (last);
}

int	ft_stacksize(t_stack *stack)
{
	int		count;
	t_stack	*next;

	next = stack;
	count = 0;
	while (next)
	{
		next = next->next;
		count++;
	}
	return (count);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!stack)
		return ;
	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
