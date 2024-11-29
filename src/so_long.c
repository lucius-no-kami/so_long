/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:01:30 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/29 12:23:10 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_long(char *map_name)
{
	char	**map;

	map = parsing_map(map_name);
	check_map_rules(map);
	// 1. Parser the map and check if it's valid
	// 2. Create mlx window etc
	// 3. print the map on the window
	// 4. make it all playable
	free_tab(map);
}
