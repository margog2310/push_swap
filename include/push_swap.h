/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:56:43 by mganchev          #+#    #+#             */
/*   Updated: 2024/07/31 00:04:34 by mganchev         ###   ########.fr       */
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
// instructions
int					swap(t_stack **stack);
int					sa(t_stack **stack_a);
int					sb(t_stack **stack_b);
int					ss(t_stack **stack_a, t_stack **stack_b);
int					push(t_stack **stack_to, t_stack **stack_from);
int					pa(t_stack **stack_a, t_stack **stack_b);
int					pb(t_stack **stack_a, t_stack **stack_b);
int					rotate(t_stack **stack);
int					ra(t_stack **stack_a);
int					rb(t_stack **stack_b);
int					rr(t_stack **stack_a, t_stack **stack_b);
int					reverse_rotate(t_stack **stack);
int					rra(t_stack **stack_a);
int					rrb(t_stack **stack_b);
int					rrr(t_stack **stack_a, t_stack **stack_b);
// sort
int					sort_3(t_stack **stack);
int					sort_4(t_stack **stack_a, t_stack **stack_b);
int					sort_5(t_stack **stack_a, t_stack **stack_b);
int					simple_sort(t_stack **stack_a, t_stack **stack_b, int size);
// utils
int					find_min(t_stack **stack);
int					find_max(t_stack **stack);
// misc
void				free_arr(char **arr);
void				handle_error(char *error);

#endif