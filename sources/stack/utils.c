/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 01:24:15 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 00:36:58 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_rank(t_stack **stack, int rank)
{
    int i;
    t_stack *head;

    i = 0;
    head = *stack;
    while (head)
    {
        if (head->rank == rank)
            return (head->rank);
        head = head->next;
    }
    return (-1);
}
