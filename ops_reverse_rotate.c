/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:47:14 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:47:17 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_stack *s)
{
	int	last;
	int	i;

	if (s->size < 2)
		return ;
	last = s->arr[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	s->arr[0] = last;
}

void	op_rra(t_stack *a)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack *b)
{
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
}
