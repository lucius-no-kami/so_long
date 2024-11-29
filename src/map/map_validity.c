/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:55:00 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/29 12:24:50 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	exit_function(char **map, char *msg)
{
	ft_printf("Error\n%s", msg);
	free_tab(map);
	exit(EXIT_FAILURE);
}

/*int	check_valid_path(char **map)
{
	// 1. checker if there is a path to the escape
}*/

static void	check_rectangular_map(char **map)
{
	size_t	reference_len;
	size_t	i;

	reference_len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != reference_len)
			exit_function(map, "Map isn't rectangular.");
		i++;
	}
	if (i == reference_len)
		exit_function(map, "Map isn't rectagular.");
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