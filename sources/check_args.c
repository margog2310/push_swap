/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:39:12 by margo             #+#    #+#             */
/*   Updated: 2024/08/05 19:15:12 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack **stack, char key)
{
	t_stack	*head;

	head = *stack;
	while (head && head->next)
	{
		if (key == 'a')
		{
			if (head->rank > head->next->rank)
				return (false);
		}
		else if (key == 'b')
		{
			if (head->rank < head->next->rank)
				return (false);
		}
		head = head->next;
	}
	return (true);
}

bool	is_number(char **args)
{
	int	i;
	int	j;

	j = 1;
	while (args[j])
	{
		i = 0;
		while (args[j][i])
		{
			if (args[j][i] == '-' || args[j][i] == '+')
				i++;
			if (!ft_isdigit(args[j][i]))
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}

bool	in_range(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_atoi(args[i]) > INT_MAX || ft_atoi(args[i]) < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

bool	is_duplicate(char **args)
{
	int	i;
	int	j;
	int	len;

	j = 1;
	while (args[j])
	{
		i = j + 1;
		while (args[i])
		{
			if (ft_strlen(args[j]) > ft_strlen(args[i]))
				len = ft_strlen(args[j]);
			else
				len = ft_strlen(args[i]);
			if (ft_strncmp(args[j], args[i], len) == 0)
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}

bool	check_args(char **args)
{
	if (!is_number(args))
		return (false);
	if (!in_range(args))
		return (false);
	if (!is_duplicate(args))
		return (false);
	return (true);
}
