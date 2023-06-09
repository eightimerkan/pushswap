/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 05:15:43 by edolgun           #+#    #+#             */
/*   Updated: 2022/12/11 16:39:12 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_data *data_a, t_data *data_b)
{
	int	index;
	int	two_index;

	index = 0;
	while (index < data_a->size)
	{
		two_index = index;
		while (two_index < data_a->size - 1)
		{
			if (data_a->array[index] == data_a->array[two_index++ + 1])
				error_mes(data_b, data_a);
		}
		index++;
	}
}

void	check_listed(t_data *data_a, t_data *data_b)
{
	int	index;
	int	counter;

	index = 0;
	counter = 1;
	while (index < data_a->size - 1)
	{
		if (data_a->array[index] < data_a->array[index + 1])
			counter = 0;
		index++;
	}
	if (counter == 1)
	{
		free(data_a->array);
		free(data_b->array);
		exit(1);
	}
}

void	check_listed_for_checker(t_data *data_a, t_data *data_b, int *control)
{
	int	index;

	index = 0;
	(void)data_b;
	while (index < data_a->size - 1)
	{
		if (data_a->array[index] < data_a->array[index + 1])
			*control = 0;
		index++;
	}
	if (*control != 0)
		*control = 1;
}
