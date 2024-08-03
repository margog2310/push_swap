/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:56:43 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/03 01:44:48 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "limits.h"
# include "stdbool.h"

enum				pos
{
	TOP_A,
	TOP_B,
	BOTTOM_A,
	BOTTOM_B
};

typedef struct s_chunk
{
	enum pos		position;
	int				size;
	int				*indexes;
}					t_chunk;

typedef struct s_split
{
	t_chunk			*min;
	t_chunk			*mid;
	t_chunk			*max;
}					t_split;

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}					t_stack;

typedef int			(*t_func)(t_stack **, t_stack **, t_list **);

typedef struct s_op
{
	char			*key;
	t_func			function;
}					t_op;

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
int					sa(t_stack **stack_a, t_stack **stack_b, t_list **ops);
int					sb(t_stack **stack_b, t_stack **stack_a, t_list **ops);
int					ss(t_stack **stack_a, t_stack **stack_b, t_list **ops);
int					push(t_stack **stack_to, t_stack **stack_from);
int					pa(t_stack **stack_a, t_stack **stack_b, t_list **ops);
int					pb(t_stack **stack_a, t_stack **stack_b, t_list **ops);
int					rotate(t_stack **stack);
int					ra(t_stack **stack_a, t_stack **stack_b, t_list **ops);
int					rb(t_stack **stack_b, t_stack **stack_a, t_list **ops);
int					rr(t_stack **stack_a, t_stack **stack_b, t_list **ops);
int					reverse_rotate(t_stack **stack);
int					rra(t_stack **stack_a, t_stack **stack_b, t_list **ops);
int					rrb(t_stack **stack_b, t_stack **stack_a, t_list **ops);
int					rrr(t_stack **stack_a, t_stack **stack_b, t_list **ops);
// sort
bool				is_sorted(t_stack **stack);
void				apply_op(t_list **ops, char *key);
int					sort_3(t_stack **stack, t_list **ops);
int					sort_4(t_stack **stack_a, t_stack **stack_b, t_list **ops);
int					sort_5(t_stack **stack_a, t_stack **stack_b, t_list **ops);
int					simple_sort(t_stack **stack_a, t_stack **stack_b, int size,
						t_list **ops);
int					sort_stack(t_stack **stack_a, t_stack **stack_b);
// optimisation
void				remove_op(t_list **ops, t_list **head, char *new_op,
						char *key);
void				optimise(t_list **ops);
// utils
void				remove_next(t_list *current, void (*del)(void *));
void				remove_current(t_list **ops, t_list *current,
						void (*del)(void *));
int					find_min(t_stack **stack);
int					find_max(t_stack **stack);
int					get_value(t_stack **stack, int rank);
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
void				print_list(t_list **lst);

#endif