/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:56:43 by mganchev          #+#    #+#             */
/*   Updated: 2024/07/31 21:46:49 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "limits.h"
# include "stdbool.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// args
bool				is_number(char **args);
bool				in_range(char **args);
bool				is_duplicate(char **args);
bool				check_args(char **args);
// stack
void				initialise_stack(t_stack **stack, int argc, char *argv[]);
void				index_stack(t_stack **stack);
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
bool				is_sorted(t_stack **stack);
int					sort_3(t_stack **stack);
int					sort_4(t_stack **stack_a, t_stack **stack_b);
int					sort_5(t_stack **stack_a, t_stack **stack_b);
int					simple_sort(t_stack **stack_a, t_stack **stack_b, int size);
// utils
int					find_min(t_stack **stack);
int					find_max(t_stack **stack);
// lst
t_stack				*ft_stacknew(int value);
void				ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack				*ft_stacklast(t_stack *stack);
int					ft_stacksize(t_stack *stack);
void				free_stack(t_stack **stack);
// misc
void				free_arr(char **arr);
void				handle_error(char *error);
void				print_stack(t_stack **stack);

#endif