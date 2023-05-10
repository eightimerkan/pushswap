/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 05:15:57 by edolgun           #+#    #+#             */
/*   Updated: 2022/12/04 05:21:21 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_before_indexing(t_data *data)
{
	int	index;
	int	two_index;
	int	*tmp;
	int	tmp_alone;

	index = -1;
	tmp = malloc(sizeof(int) * data->size);
	while (++index < data->size)
		tmp[index] = data->array[index];
	index = -1;
	while (++index < data->size)
	{
		two_index = index - 1;
		while (++two_index < data->size)
		{
			if (tmp[index] > tmp[two_index])
			{
				tmp_alone = tmp[index];
				tmp[index] = tmp[two_index];
				tmp[two_index] = tmp_alone;
			}
		}
	}
	return (tmp);
}

void	indexing(t_data *data)
{
	int	*sorted;
	int	index;
	int	two_index;

	index = 0;
	sorted = sort_before_indexing(data);
	while (index < data->size)
	{
		two_index = 0;
		while (two_index < data->size)
		{
			if (data->array[index] == sorted[two_index])
			{
				data->array[index] = two_index;
				break ;
			}
			two_index++;
		}
		index++;
	}
	free (sorted);
}
