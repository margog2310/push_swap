/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:56:43 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 23:59:43 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "limits.h"
# include "stdbool.h"

enum				e_pos
{
	TOP_A,
	TOP_B,
	BOTTOM_A,
	BOTTOM_B
};

typedef struct s_chunk
{
	enum e_pos		position;
	int				size;
}					t_chunk;

typedef struct s_split
{
	t_chunk			min;
	t_chunk			mid;
	t_chunk			max;
}					t_split;

typedef struct s_stack
{
	struct s_stack	*prev;
	int				value;
	int				rank;
	int				chunk_rank;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack			**a;
	t_stack			**b;
	t_list			**ops;
}					t_data;

typedef int			(*t_func)(t_data *);

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
void				init_data(t_data **data, int argc, char *argv[]);
void				fill_stack(t_data *data, t_stack **stack, int argc,
						char *argv[]);
void				index_stack(t_stack **stack);
// instructions
int					swap(t_stack **stack);
int					sa(t_data *data);
int					sb(t_data *data);
int					ss(t_data *data);
int					push(t_stack **stack_to, t_stack **stack_from);
int					pa(t_data *data);
int					pb(t_data *data);
int					rotate(t_stack **stack);
int					ra(t_data *data);
int					rb(t_data *data);
int					rr(t_data *data);
int					reverse_rotate(t_stack **stack);
int					rra(t_data *data);
int					rrb(t_data *data);
int					rrr(t_data *data);
// chunks
t_chunk				init_chunk(int size, enum e_pos position);
void				init_split(t_split *split);
void				rank_chunk(t_data *data, t_chunk *chunk);
void				first_split(t_data *data);
void				assign_position(t_chunk *to_sort, t_split *split);
void				split_chunk(t_data *data, t_chunk *to_sort, t_split *split);
void				sort_chunk(t_chunk *to_sort, t_data *data);
void				to_top(t_chunk *to_sort, t_data *data);
void				move_ta(t_data *data, enum e_pos dest);
void				move_ba(t_data *data, enum e_pos dest);
void				move_tb(t_data *data, enum e_pos dest);
void				move_bb(t_data *data, enum e_pos dest);
void				move_to(t_data *data, enum e_pos pos, enum e_pos dest);
int					chunk_min(t_chunk *chunk, t_data *data);
int					chunk_max(t_chunk *chunk, t_data *data);
bool				chunk_is_sorted(t_chunk *chunk, t_data *data);
t_stack				*return_stack(t_data *data, enum e_pos position);
// sort
bool				is_sorted(t_stack **stack, char key);
int					sort_3_a(t_data *data);
int					sort_4_a(t_data *data);
int					sort_5_a(t_data *data);
int					sort_3_b(t_data *data);
int					sort_4_b(t_data *data);
int					sort_5_b(t_data *data);
void				easy_sort(t_data *data, t_chunk *to_sort);
int					simple_sort_b(t_data *data, int size);
int					simple_sort_a(t_data *data, int size);
int					sort_stack(t_data *data);
void				move_chunks(t_data *data, t_chunk *to_sort, t_split *split);
void				chunk_sort_1(t_chunk *to_sort, t_data *data);
void				chunk_sort_2(t_chunk *to_sort, t_data *data);
void				chunk_sort_3(t_chunk *to_sort, t_data *data);
void				sort_3_ta(t_chunk *to_sort, t_data *data);
void				sort_3_tb(t_chunk *to_sort, t_data *data);
void				sort_3_ba(t_chunk *to_sort, t_data *data);
void				sort_3_bb(t_chunk *to_sort, t_data *data);
// optimisation
void				apply_op(t_list **ops, char *key);
void				remove_op(t_list **ops, t_list **head, char *new_op,
						char *key);
void				optimise(t_list **ops);
// utils
void				remove_next(t_list *current, void (*del)(void *));
void				remove_current(t_list **ops, t_list *current,
						void (*del)(void *));
int					find_min(t_stack **stack);
int					find_max(t_stack **stack);
int					get_rank(t_stack **stack, int rank);
t_stack				*get_next_node(t_stack *head, enum e_pos position);
// lst
t_stack				*ft_stacknew(int rank);
void				ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack				*ft_stacklast(t_stack *stack);
int					ft_stacksize(t_stack *stack);
// misc
void				free_stack(t_stack *stack);
void				free_memory(t_data *data);
void				free_arr(char **arr);
void				handle_error(t_data *data, char *error);
void				print_stack(t_stack **stack);
void				print_list(t_list **lst);

#endif