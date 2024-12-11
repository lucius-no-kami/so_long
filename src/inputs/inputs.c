/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:00:05 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/11 08:16:57 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	input_handling(int keycode, t_game *game)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
		free_memory(game);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		horizontal_movement(game, \
		game->map.player_pos.x, &game->map.player_pos.y, -1);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		horizontal_movement(game, \
		game->map.player_pos.x, &game->map.player_pos.y, 1);
	if (keycode == KEY_W || keycode == KEY_UP)
		vertical_movement(game, \
		&game->map.player_pos.x, game->map.player_pos.y, -1);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		vertical_movement(game, \
		&game->map.player_pos.x, game->map.player_pos.y, 1);
	return (0);
}
