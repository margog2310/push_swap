/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:09:25 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 23:57:33 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_op(t_list **ops, char *key)
{
	int			i;
	static t_op	ops_table[] = {{"sa", &sa}, {"sb", &sb}, {"ss", &ss}, {"pa",
		&pa}, {"pb", &pb}, {"ra", &ra}, {"rb", &rb}, {"rr", &rr}, {"rra",
		&rra}, {"rrb", &rrb}, {"rrr", &rrr}, {NULL, NULL}};

	i = 0;
	while (ops_table[i].key)
	{
		if (ft_strncmp(ops_table[i].key, key, ft_strlen(key)) == 0)
		{
			ft_lstadd_back(ops, ft_lstnew(ft_strdup(ops_table[i].key)));
			return ;
		}
		i++;
	}
}

void	remove_op(t_list **ops, t_list **head, char *new_op, char *key)
{
	t_list	*next_node;

	if (key && new_op)
	{
		free(key);
		(*head)->content = ft_strdup(new_op);
	}
	if (ops)
	{
		next_node = (*head)->next;
		remove_current(ops, *head, free);
		*head = NULL;
		*head = next_node;
	}
	if (*head && (*head)->next)
	{
		next_node = (*head)->next->next;
		remove_next(*head, free);
		(*head)->next = NULL;
		(*head)->next = next_node;
	}
	*head = (*head)->next;
}

void	optimise(t_list **ops)
{
	t_list	*head;
	char	*op1;
	char	*op2;

	head = *ops;
	while (head && head->next)
	{
		op1 = (char *)head->content;
		op2 = (char *)head->next->content;
		if ((ft_strcmp(op1, "sa") == 0 && ft_strcmp(op2, "sb") == 0)
			|| (ft_strcmp(op1, "sb") == 0 && ft_strcmp(op2, "sa") == 0))
			remove_op(NULL, &head, "ss", op1);
		else if ((ft_strcmp(op1, "ra") == 0 && ft_strcmp(op2, "rb") == 0)
			|| (ft_strcmp(op1, "rb") == 0 && ft_strcmp(op2, "ra") == 0))
			remove_op(NULL, &head, "rr", op1);
		else if ((ft_strcmp(op1, "rra") == 0 && ft_strcmp(op2, "rrb") == 0)
			|| (ft_strcmp(op1, "rrb") == 0 && ft_strcmp(op2, "rra") == 0))
			remove_op(NULL, &head, "rrr", op1);
		else if ((ft_strcmp(op1, "pa") == 0 && ft_strcmp(op2, "pb") == 0)
			|| (ft_strncmp(op1, "sa", 2) == 0 && ft_strcmp(op2, "sa") == 0)
			|| (ft_strcmp(op1, "ra") == 0 && ft_strncmp(op2, "rra", 3) == 0))
			remove_op(ops, &head, NULL, NULL);
		else
			head = head->next;
	}
}

void	easy_sort(t_data *data, t_chunk *to_sort)
{
	if (to_sort->size <= 5)
	{
		if ((to_sort->position == TOP_A || to_sort->position == BOTTOM_A)
			&& to_sort->size == ft_stacksize(*data->a))
			simple_sort_a(data, to_sort->size);
		else if ((to_sort->position == TOP_B || to_sort->position == BOTTOM_B)
			&& to_sort->size == ft_stacksize(*data->b))
			simple_sort_b(data, to_sort->size);
	}
}

int	sort_stack(t_data *data)
{
	int	size;

	size = ft_stacksize(*data->a);
	if (size <= 1)
		return (1);
	if (size <= 5)
		simple_sort_a(data, size);
	else
		first_split(data);
	print_list(data->ops);
	return (0);
}

// optimise(data->ops);