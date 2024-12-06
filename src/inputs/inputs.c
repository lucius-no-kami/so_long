/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:00:05 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/06 09:22:08 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	input_handling(int keycode, t_game *game)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_A)
		horizontal_movement(game, \
		game->map.player_pos.x, &game->map.player_pos.y, -1);
	if (keycode == KEY_D)
		horizontal_movement(game, \
		game->map.player_pos.x, &game->map.player_pos.y, 1);
	if (keycode == KEY_W)
		vertical_movement(game, \
		&game->map.player_pos.x, game->map.player_pos.y, -1);
	if (keycode == KEY_S)
		vertical_movement(game, \
		&game->map.player_pos.x, game->map.player_pos.y, 1);
	return (0);
}
