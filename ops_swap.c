/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:47:32 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:47:35 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->arr[0];
	s->arr[0] = s->arr[1];
	s->arr[1] = tmp;
}

void	op_sa(t_stack *a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}
