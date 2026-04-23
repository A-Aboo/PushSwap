/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:47:50 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:48:45 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	cap;
}		t_stack;

typedef struct s_numbers
{
	int	*values;
	int	size;
}		t_numbers;

int		parse_arguments(int argc, char **argv, t_numbers *nums);
int		compress_values(int *arr, int size);

int		stack_init(t_stack *s, int cap);
void	stack_clear(t_stack *s);
int		stack_is_sorted(t_stack *a);
int		find_pos_of_min(t_stack *a);

void	op_sa(t_stack *a);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);

void	sort_small(t_stack *a, t_stack *b);
void	sort_chunk(t_stack *a, t_stack *b);

void	fatal_error(t_stack *a, t_stack *b, int *values);

int		ft_is_space(char c);
int		ft_is_digit(char c);
int		has_duplicate(int *arr, int size);

#endif
