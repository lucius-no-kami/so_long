/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:38:51 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/07 11:28:36 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	floodfill(t_map map, char paint, int x, int y)
{
	if (map.map[x][y] == 'T' || map.map[x][y] == WALLS \
	|| x < 0 || x >= map.row || y < 0 || y >= map.columns)
		return ;
	map.map[x][y] = paint;
	floodfill(map, paint, x - 1, y);
	floodfill(map, paint, x + 1, y);
	floodfill(map, paint, x, y - 1);
	floodfill(map, paint, x, y + 1);
}

void	path_finder(t_game *game, t_map map)
{
	t_map	tmp;
	int		i;
	int		j;

	tmp = map;
	i = 0;
	floodfill(tmp, 'T', map.player_pos.x, map.player_pos.y);
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if ((map.map[i][j] == EXIT || map.map[i][j] == COIN) \
			&& tmp.map[i][j] != 'T')
				error_msg("There is no valid path to objectives", game);
			j++;
		}
		i++;
	}
}
