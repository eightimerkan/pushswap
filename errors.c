/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 05:15:52 by edolgun           #+#    #+#             */
/*   Updated: 2022/12/24 12:01:55 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_mes(t_data *data_a, t_data *data_b)
{
	ft_printf("Error\n");
	free(data_a->array);
	free(data_b->array);
	exit(1);
}
