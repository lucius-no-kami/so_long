/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 08:10:23 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/06 10:08:03 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	horizontal_movement(t_game *game, int x, int *y, int step)
{
	if (game->map.map[x][*y + step] != WALLS)
	{
		if (game->map.map[x][*y + step] == COIN)
			game->map.coin--;
		if (game->map.map[x][*y + step] == EXIT \
		&& game->map.coin == 0)
			close_game(game);
		else if (game->map.map[x][*y + step] == EXIT \
		&& game->map.coin != 0)
			return ;
		game->map.map[x][*y] = FLOOR;
		*y += step;
		game->map.map[x][*y] = PLAYER;
		game->cmove++;
		ft_printf(GREEN"Movements: %d\n"RESET, game->cmove);
	}
}

void	vertical_movement(t_game *game, int *x, int y, int step)
{
	if (game->map.map[*x + step][y] != WALLS)
	{
		if (game->map.map[*x + step][y] == COIN)
		game->map.coin--;
		if (game->map.map[*x + step][y] == EXIT \
		&& game->map.coin == 0)
			close_game(game);
		else if (game->map.map[*x + step][y] == EXIT \
		&& game->map.coin != 0)
			return ;
		game->map.map[*x][y] = FLOOR;
		*x += step;
		game->map.map[*x][y] = PLAYER;
		game->cmove++;
		ft_printf(GREEN"Movements: %d\n"RESET, game->cmove);
	}
}
