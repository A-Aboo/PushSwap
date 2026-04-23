/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:46:46 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:46:50 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack(t_stack *a, t_numbers *nums)
{
	int	i;

	i = 0;
	while (i < nums->size)
	{
		a->arr[i] = nums->values[i];
		i++;
	}
	a->size = nums->size;
}

static void	sort_if_needed(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a))
		return ;
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_chunk(a, b);
}

static void	init_empty_stacks(t_stack *a, t_stack *b)
{
	a->arr = NULL;
	a->size = 0;
	a->cap = 0;
	b->arr = NULL;
	b->size = 0;
	b->cap = 0;
}

int	main(int argc, char **argv)
{
	t_numbers	nums;
	t_stack		a;
	t_stack		b;

	if (argc == 1)
		return (0);
	if (!parse_arguments(argc, argv, &nums))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_empty_stacks(&a, &b);
	if (!stack_init(&a, nums.size) || !stack_init(&b, nums.size))
		fatal_error(&a, &b, nums.values);
	if (!compress_values(nums.values, nums.size))
		fatal_error(&a, &b, nums.values);
	fill_stack(&a, &nums);
	sort_if_needed(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	free(nums.values);
	return (0);
}
