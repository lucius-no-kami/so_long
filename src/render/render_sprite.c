/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:07:30 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/12 08:11:31 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_sprite(t_game *game, t_img sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	sprite.xpm_ptr, y * sprite.y, x * sprite.x);
}

static void	identify_sprite(t_game *game, char c, int x, int y)
{
	if (c == FLOOR)
		render_sprite(game, game->floor, x, y);
	if (c == WALLS)
		render_sprite(game, game->wall, x, y);
	if (c == COIN)
		render_sprite(game, game->coin, x, y);
	if (c == EXIT)
		render_sprite(game, game->exit, x, y);
	if (c == PLAYER)
		render_sprite(game, game->player, x, y);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			identify_sprite(game, game->map.map[y][x], y, x);
			x++;
		}
		y++;
	}
	return (0);
}
