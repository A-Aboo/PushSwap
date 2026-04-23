/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:47:40 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:47:42 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_numbers_in_arg(char *s, int *count)
{
	int	i;
	int	local_count;

	i = 0;
	local_count = 0;
	while (s[i])
	{
		while (ft_is_space(s[i]))
			i++;
		if (!s[i])
			break ;
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (!ft_is_digit(s[i]))
			return (0);
		while (ft_is_digit(s[i]))
			i++;
		if (s[i] && !ft_is_space(s[i]))
			return (0);
		local_count++;
	}
	if (local_count == 0)
		return (0);
	*count += local_count;
	return (1);
}

static int	total_numbers(int argc, char **argv, int *count)
{
	int	i;

	*count = 0;
	i = 1;
	while (i < argc)
	{
		if (!count_numbers_in_arg(argv[i], count))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_int(char *s, int *i, int *value)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (!ft_is_digit(s[*i]))
		return (0);
	while (ft_is_digit(s[*i]))
	{
		nbr = (nbr * 10) + (s[*i] - '0');
		if ((sign == 1 && nbr > INT_MAX) || (sign == -1 && (-nbr) < INT_MIN))
			return (0);
		(*i)++;
	}
	*value = (int)(nbr * sign);
	return (1);
}

static int	fill_numbers(int argc, char **argv, int *values)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (ft_is_space(argv[i][j]))
				j++;
			if (!argv[i][j])
				break ;
			if (!parse_int(argv[i], &j, &values[k]))
				return (0);
			k++;
			if (argv[i][j] && !ft_is_space(argv[i][j]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_numbers *nums)
{
	int	count;

	if (!total_numbers(argc, argv, &count))
		return (0);
	nums->values = (int *)malloc(sizeof(int) * count);
	if (!nums->values)
		return (0);
	if (!fill_numbers(argc, argv, nums->values))
	{
		free(nums->values);
		return (0);
	}
	if (has_duplicate(nums->values, count))
	{
		free(nums->values);
		return (0);
	}
	nums->size = count;
	return (1);
}
