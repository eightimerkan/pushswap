/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 05:16:02 by edolgun           #+#    #+#             */
/*   Updated: 2022/12/24 14:05:41 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data_a;
	t_data	data_b;

	data_a.type = 'a';
	data_b.type = 'b';
	if (ac == 2)
		for_two_args(av[1], &data_a, &data_b);
	else if (ac > 2 && ac <= 502)
		for_more_args(ac, av, &data_a, &data_b);
	else
		return (0);
	check_double(&data_a, &data_b);
	indexing(&data_a);
	check_listed(&data_a, &data_b);
	if (data_a.size > 5)
		sort_the_list(&data_a, &data_b);
	else
		sort_smaller_list(&data_a, &data_b);
	free(data_a.array);
	free(data_b.array);
	return (0);
}
