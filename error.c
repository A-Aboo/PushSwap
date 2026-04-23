/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:46:21 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:46:28 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fatal_error(t_stack *a, t_stack *b, int *values)
{
	if (values)
		free(values);
	if (a)
		stack_clear(a);
	if (b)
		stack_clear(b);
	write(2, "Error\n", 6);
	exit(1);
}
