/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 05:16:12 by edolgun           #+#    #+#             */
/*   Updated: 2022/12/11 16:39:28 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_data *data, int control)
{
	int	tmp;

	if (data->size < 2)
		ft_printf("No number to swap");
	tmp = data->array[data->size - 1];
	data->array[data->size - 1] = data->array[data->size - 2];
	data->array[data->size - 2] = tmp;
	if (control == 0)
	{
		if (data->type == 'a')
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
}

void	swap_together(t_data *data_a, t_data *data_b, int control)
{
	if (control == 0)
	{
		swap(data_a, 1);
		swap(data_b, 1);
		ft_printf("ss\n");
	}
}

void	rotate(t_data *data, int control)
{
	int	index;
	int	tmp;

	index = 0;
	tmp = data->array[data->size - 1];
	while (index < data->size)
	{
		data->array[data->size - 1 - index]
			= data->array[data->size - 2 - index];
		index++;
	}
	data->array[0] = tmp;
	if (control == 0)
	{
		if (data->type == 'a')
			ft_printf("ra\n");
		else if (data->type == 'b')
			ft_printf("rb\n");
	}
}

void	rotate_together(t_data *data_a, t_data *data_b, int control)
{
	if (control == 0)
	{
		rotate(data_a, 1);
		rotate(data_b, 1);
		ft_printf("rr\n");
	}
}

void	push(t_data *data1, t_data *data2, int control)
{
	if (data1->size < 1)
		ft_printf("No number to push");
	data2->array[data2->size] = data1->array[data1->size - 1];
	data2->size += 1;
	data1->size -= 1;
	if (control == 0)
	{
		if (data1->type == 'a')
			ft_printf("pb\n");
		else if (data1->type == 'b')
			ft_printf("pa\n");
	}
}
