/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 01:24:15 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/05 03:35:12 by margo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_rank(t_stack **stack, int rank)
{
    t_stack *head;

    head = *stack;
    while (head)
    {
        if (head->rank == rank)
            return (head->rank);
        head = head->next;
    }
    return (-1);
}
