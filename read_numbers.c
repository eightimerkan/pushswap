/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 05:16:26 by edolgun           #+#    #+#             */
/*   Updated: 2022/12/11 16:39:45 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_counter(char *str, t_data *data_a, t_data *data_b)
{
	int	index;
	int	counter;

	index = 0;
	counter = 0;
	while (str[index])
	{
		while (str[index] == ' ' || str[index] == '\t')
			index++;
		if ((str[index] >= '0' && str[index] <= '9') || \
		(str[index] == '-' || str[index] == '+'))
			counter++;
		else
			error_mes(data_a, data_b);
		while ((str[index] >= '0' && str[index] <= '9') || \
		(str[index] == '-' || str[index] == '+'))
			index++;
	}
	return (counter);
}

int	ft_atoi(char *str, t_data *data_a, t_data *data_b)
{
	int		index;
	long	res;
	int		neg;

	index = 0;
	neg = 1;
	res = 0;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			neg *= -1;
		index++;
	}
	while (str[index])
	{
		if (!((str[index] >= '0' && str[index] <= '9') || str[index] == ' '))
			error_mes(data_a, data_b);
		if (str[index] == ' ' || str[index] == '\t')
			return (res * neg);
		res = (res * 10) + str[index++] - '0';
		if (res > INT_MAX)
			error_mes(data_a, data_b);
	}
	return (res * neg);
}

void	for_two_args(char *str, t_data *data_a, t_data *data_b)
{
	int	index;
	int	total_number;
	int	number_index;

	number_index = 0;
	index = 0;
	total_number = number_counter(str, data_a, data_b);
	data_a->size = total_number;
	data_b->size = 0;
	data_b->array = malloc(sizeof(int) * total_number);
	data_a->array = malloc(sizeof(int) * total_number);
	while (str[index])
	{
		while (str[index] == ' ' || str[index] == '\t')
			index++;
		if ((str[index] >= '0' && str[index] <= '9') || \
		(str[index] == '-' || str[index] == '+'))
			data_a->array[total_number - 1 - number_index++] = \
				ft_atoi(str + index, data_a, data_b);
		while ((str[index] >= '0' && str[index] <= '9') || \
		(str[index] == '-' || str[index] == '+'))
			index++;
	}
}

void	for_more_args(int ac, char **av, t_data *data_a, t_data *data_b)
{
	int	index;

	index = 0;
	data_a->array = malloc(sizeof(int) * (ac - 1));
	data_b->array = malloc(sizeof(int) * (ac - 1));
	data_a->size = ac - 1;
	data_b->size = 0;
	while (++index < ac)
		data_a->array[ac - 1 - index] = ft_atoi(av[index], data_a, data_b);
}
