/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:03:48 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/26 10:15:14 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_valid_path(char **map)
{
	// 1. checker if there is a path to the escape
}

int	check_map_validity(char **map)
{
	// 1. if there is only EMPTY_SPACE WALLS COLLECTIBLES ESCAPE SPAWN
	// 2. check if the map is rectangular
	// 3. Check if there is wall all over the rectangle
}

char	**read_file(char *map_name)
{
	int	fd;
	char	buffer[10];
}

char	**parsing_map(char *map_name)
{
	// 0. call a function to get the map into a 2d char tab
	// 1. check if char in the map are valid
	// 2. call a function to check map_validity
	// 3. call a function to check valid path
}