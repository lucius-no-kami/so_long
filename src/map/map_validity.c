/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:55:00 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/29 16:41:59 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	exit_function(char **map, char *msg)
{
	ft_printf("Error\n%s", msg);
	free_tab(map, EXIT_FAILURE);
	exit(EXIT_FAILURE);
}

static void	check_rectangular_map(char **map)
{
	size_t	reference_len;
	size_t	i;

	i = 0;
	reference_len = ft_strlen(map[0]) - 1;
	while (map[i + 1] != NULL)
	{
		if (map[i][0] != WALLS && map[i][reference_len] != WALLS)
		{
			ft_printf("Exit so_long\n");
			exit_function(map, "Map isn't surrounded by WALLS.");
		}
		if (ft_strlen(map[i]) - 1 != reference_len)
			exit_function(map, "Map isn't rectangular. One line is larger");
		i++;
	}
	if (i + 1 == reference_len)
		exit_function(map, "Map isn't rectagular. width == height");
	// 2. check if the map is surround by WALLS
}

void	check_map_rules(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] != EMPTY_SPACE || map[i][j] != WALLS \
			|| map[i][j] != COLLECTIBLE || map[i][j] != ESCAPE \
			|| map[i][j] != SPAWN))
				exit_function(map, "Found unvalid character in map.");
			j++;
		}
		i++;
	}
	check_rectangular_map(map);
}

// 0. Check if there is wall all over the rectangle
// 1. check if char in the map are valid
// 2. call a function to check map_validity
// 3. call a function to check valid path