/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:48:12 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:48:14 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(t_stack *s, int cap)
{
	s->arr = NULL;
	s->size = 0;
	s->cap = 0;
	s->arr = (int *)malloc(sizeof(int) * cap);
	if (!s->arr)
		return (0);
	s->cap = cap;
	return (1);
}

void	stack_clear(t_stack *s)
{
	free(s->arr);
	s->arr = NULL;
	s->size = 0;
	s->cap = 0;
}

int	stack_is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_pos_of_min(t_stack *a)
{
	int		min;
	int		min_pos;
	int		i;

	min = INT_MAX;
	min_pos = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] < min)
		{
			min = a->arr[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}
