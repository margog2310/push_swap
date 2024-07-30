/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:39:12 by margo             #+#    #+#             */
/*   Updated: 2024/07/30 23:38:35 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// args are a list of integers (can't be more/less than MAX_INT and MIN_INT)
// can be multiple strings or one long string with all ints
// if no args, program should display nothing and return prompt
// must print "Error\n" if args aren't ints,
//	if bigger/smaller than int and if there's duplicates

bool	is_number(char **args)
{
	int	i;
	int	j;

	j = 0;
	while (args[j])
	{
		i = 0;
		while (args[j][i])
		{
			if (!ft_isdigit(args[j][i]))
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}

bool	is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}
