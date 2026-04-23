/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:46:59 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:47:02 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack *dst, t_stack *src)
{
	int	value;
	int	i;

	if (src->size == 0 || dst->size >= dst->cap)
		return ;
	value = src->arr[0];
	i = 0;
	while (i + 1 < src->size)
	{
		src->arr[i] = src->arr[i + 1];
		i++;
	}
	src->size--;
	i = dst->size;
	while (i > 0)
	{
		dst->arr[i] = dst->arr[i - 1];
		i--;
	}
	dst->arr[0] = value;
	dst->size++;
}

void	op_pa(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	write(1, "pa\n", 3);
}

void	op_pb(t_stack *a, t_stack *b)
{
	push_stack(b, a);
	write(1, "pb\n", 3);
}
