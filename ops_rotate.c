/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:47:24 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:47:27 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *s)
{
	int	first;
	int	i;

	if (s->size < 2)
		return ;
	first = s->arr[0];
	i = 0;
	while (i + 1 < s->size)
	{
		s->arr[i] = s->arr[i + 1];
		i++;
	}
	s->arr[s->size - 1] = first;
}

void	op_ra(t_stack *a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}
