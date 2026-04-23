/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:47:58 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:48:02 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	if (size <= 500)
		return (35);
	return (45);
}

static int	find_pos_of_max(t_stack *b)
{
	int	i;
	int	max;
	int	pos;

	i = 1;
	max = b->arr[0];
	pos = 0;
	while (i < b->size)
	{
		if (b->arr[i] > max)
		{
			max = b->arr[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	next_index;

	next_index = 0;
	while (a->size > 0)
	{
		if (a->arr[0] <= next_index)
		{
			op_pb(a, b);
			op_rb(b);
			next_index++;
		}
		else if (a->arr[0] <= next_index + chunk_size)
		{
			op_pb(a, b);
			next_index++;
		}
		else
			op_ra(a);
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	pos;
	int	moves;

	while (b->size > 0)
	{
		pos = find_pos_of_max(b);
		if (pos <= b->size / 2)
		{
			while (pos > 0)
			{
				op_rb(b);
				pos--;
			}
		}
		else
		{
			moves = b->size - pos;
			while (moves > 0)
			{
				op_rrb(b);
				moves--;
			}
		}
		op_pa(a, b);
	}
}

void	sort_chunk(t_stack *a, t_stack *b)
{
	push_chunks_to_b(a, b, get_chunk_size(a->size));
	push_back_to_a(a, b);
}





















