/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:46:36 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/20 07:46:40 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_rank(int *arr, int *rank, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		rank[i] = 0;
		j = 0;
		while (j < size)
		{
			if (arr[j] < arr[i])
				rank[i]++;
			j++;
		}
		i++;
	}
}

int	compress_values(int *arr, int size)
{
	int		*rank;
	int		i;

	rank = (int *)malloc(sizeof(int) * size);
	if (!rank)
		return (0);
	fill_rank(arr, rank, size);
	i = 0;
	while (i < size)
	{
		arr[i] = rank[i];
		i++;
	}
	free(rank);
	return (1);
}
