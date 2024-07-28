/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:13:34 by mganchev          #+#    #+#             */
/*   Updated: 2024/07/28 01:58:34 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_stack(t_stack **stack, int argc, char *argv[])
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], " ");
	else
		args = argv;
	while (--argc)
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(args[argc])));
    if (argc == 2)
        free_arr(args);
}

int	main(int argc, char *argv[])
{
	t_stack	**a;
	t_stack	**b;

	if (argc < 2)
		return (-1);
	// check if args are valid
    t_stack *a = NULL;
    t_stack *b = NULL;
    initialise_stack(a, argc, argv);
    // check if stack a is already sorted
    // if yes, free stacks and return stack a
    // if no, initialise stack b and continue to sorting
}
