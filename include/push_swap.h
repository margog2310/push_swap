/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:56:43 by mganchev          #+#    #+#             */
/*   Updated: 2024/07/28 22:02:55 by margo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdbool.h"

typedef struct s_stack
{
	int				*value;
	struct s_stack	*next;
}					t_stack;

// args
bool				is_number(char **args);
// stack
void				initialise_stack(t_stack **stack, int argc, char *argv[]);
// utils
void				free_arr(char **arr);

#endif