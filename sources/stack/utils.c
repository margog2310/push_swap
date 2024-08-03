/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 01:24:15 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/03 01:44:15 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_value(t_stack **stack, int rank)
{
    int i;
    t_stack *head;

    i = 0;
    head = *stack;
    while (head)
    {
        if (head->rank == rank)
            return (head->value);
        head = head->next;
    }
    return (-1);
}
