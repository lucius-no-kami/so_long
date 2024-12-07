/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:38:51 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/07 16:45:44 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_map_copy(char **map, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	free(map);
}

char	**copy_map(t_game *game, t_map map)
{
	int		i;
	char	**copy;

	i = 0;
	copy = (char **)malloc((map.row + 1) * sizeof(char *));
	if (!copy)
		error_msg("Couldn't allocate memory in copy_map", game);
	while (i < map.row)
	{
		copy[i] = ft_strdup(map.map[i]);
		if (!copy[i])
		{
			free_map_copy(copy, i);
			error_msg("Couldn't allocate memory in copy_map", game);
		}
		i++;
	}
	return (copy);
}

void	floodfill(char **map, char paint, int x, int y)
{
	if (map[x][y] == 'T' || map[x][y] == WALLS)
		return ;
	map[x][y] = paint;
	floodfill(map, paint, x - 1, y);
	floodfill(map, paint, x + 1, y);
	floodfill(map, paint, x, y - 1);
	floodfill(map, paint, x, y + 1);
}

void	path_finder(t_game *game, t_map map)
{
	char	**tmp;
	int		i;
	int		j;

	tmp = copy_map(game, map);
	i = 0;
	floodfill(tmp, 'T', map.player_pos.x, map.player_pos.y);
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (((map.map[i][j] == EXIT || map.map[i][j] == COIN) \
			&& tmp[i][j] != 'T'))
			{
				free_map_copy(tmp, map.row);
				error_msg("There is no valid path to objectives", game);
			}
			j++;
		}
		i++;
	}
	free_map_copy(tmp, i);
}
