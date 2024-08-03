/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:41:28 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/03 01:07:50 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk *init_chunk(int size, enum pos position)
{
    t_chunk *chunk;

    chunk->size = size;
    chunk->position = position;
    chunk->indexes = malloc(size * sizeof(int));
    if (!chunk->indexes)
        return (NULL);
    return (chunk);
}



t_split split_stack(t_stack **stack)
{
    int chunk_size;
    int remainder;
    t_stack *head;
    t_split *split_stack;

    head = *stack;
    chunk_size = ft_stacksize(*stack) / 3;
    remainder = ft_stacksize(*stack) % 3;
    split_stack->min = init_chunk(chunk_size, BOTTOM_B);
    split_stack->mid = init_chunk(chunk_size, TOP_A);
    split_stack->max = init_chunk(chunk_size + remainder, BOTTOM_A);
}
