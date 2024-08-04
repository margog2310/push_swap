/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:05:22 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/03 22:42:38 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_TA(t_data *data, enum pos dest)
{
	if (dest == BOTTOM_A)
		ra(data);
	else if (dest == TOP_B)
		pb(data);
	else if (dest == BOTTOM_B)
	{
		pb(data);
		if (ft_stacksize(*data->b) > 1)
            rb(data);
	}
}

void    move_BA(t_data *data, enum pos dest)
{
    if (dest == TOP_A)
        rra(data);
    else if (dest == TOP_B)
    {
        rra(data);
        pb(data);
    }
    else if (dest == BOTTOM_B)
    {
        rra(data);
        pb(data);
        if (ft_stacksize(*data->b) > 1)
            rb(data);
    }
}

void    move_TB(t_data *data, enum pos dest)
{
    if (dest == TOP_A)
        pa(data);
    else if (dest == BOTTOM_A)
    {
        pa(data);
        if (ft_stacksize(*data->a) > 1)
            ra(data);
    }
    else if (dest == BOTTOM_B)
        rb(data);
}

void    move_BB(t_data *data, enum pos dest)
{
    if (dest == TOP_A)
    {
        rrb(data);
        pa(data);
    }
    else if (dest == BOTTOM_A)
    {
        rrb(data);
        pa(data);
        if (ft_stacksize(*data->a) > 1)
            ra(data);
    }
    else if (dest == TOP_B)
        rb(data);
}

void    move_to(t_data *data, enum pos pos, enum pos dest)
{
    if (pos == TOP_A)
        move_TA(data, dest);
    else if (pos == BOTTOM_A)
        move_BA(data, dest);
    else if (pos == TOP_B)
        move_TB(data, dest);
    else if (pos == BOTTOM_B)
        move_BB(data, dest);
}
