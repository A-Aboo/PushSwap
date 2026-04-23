/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:48:06 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:48:08 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *a)
{
	if (a->arr[0] > a->arr[1])
		op_sa(a);
}

static void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->arr[0];
	y = a->arr[1];
	z = a->arr[2];
	if (x > y && y < z && x < z)
		op_sa(a);
	else if (x > y && y > z)
	{
		op_sa(a);
		op_rra(a);
	}
	else if (x > y && y < z && x > z)
		op_ra(a);
	else if (x < y && y > z && x < z)
	{
		op_sa(a);
		op_ra(a);
	}
	else if (x < y && y > z && x > z)
		op_rra(a);
}

static void	bring_pos_to_top(t_stack *a, int pos)
{
	int	moves;

	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			op_ra(a);
			pos--;
		}
	}
	else
	{
		moves = a->size - pos;
		while (moves > 0)
		{
			op_rra(a);
			moves--;
		}
	}
}

static void	sort_five(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 3)
	{
		pos = find_pos_of_min(a);
		bring_pos_to_top(a, pos);
		op_pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		op_pa(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size >= 4)
		sort_five(a, b);
}
