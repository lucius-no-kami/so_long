/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:03:48 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/26 11:08:31 by luluzuri         ###   ########.fr       */
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

void	fill_2dtab(int fd, char **tab, int numLines)
{
	tab = (char **)malloc((numLines + 1) * sizeof(char *));
	if (!tab)
	{
		ft_printf("Error\nCoudn't not malloc. (fill_2dtab: line 29)");
		exit(EXIT_FAILURE);
	}
}

char	**read_file(char *map_name, char **tab)
{
	char	*line;
	int		fd;
	int		count;

	line = "";
	fd = open(map_name, O_RDONLY);
	count = 0;
	if (fd == -1)
	{
		ft_printf("Error\nCouldn't open map file.");
		return (NULL);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		count++;
		free(line);
	}
	fill_2dtab(fd, tab, count);
	return (tab);
}

char	**parsing_map(char *map_name)
{
	// 0. call a function to get the map into a 2d char tab
	// 1. check if char in the map are valid
	// 2. call a function to check map_validity
	// 3. call a function to check valid path
}
