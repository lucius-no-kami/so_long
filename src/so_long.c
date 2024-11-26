/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:01:30 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/26 11:10:10 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_long(char *map_name)
{
	if (ft_strchr(map_name, 't'))
	{
		ft_printf("Error\n't' wasn't in the file name");
		exit(EXIT_FAILURE);
	}
	// 1. Parser the map and check if it's valid
	// 2. Create mlx window etc
	// 3. print the map on the window
	// 4. make it all playable
}
