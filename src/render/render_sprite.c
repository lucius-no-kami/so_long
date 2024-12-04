/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:07:30 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/04 16:05:26 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	render_sprite(t_game *game, t_img sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	sprite.xpm_ptr, y * sprite.y, x * sprite.x);
}

static void	identify_sprite(t_game *game, char c, int x, int y)
{
	if (c == FLOOR || c == COIN || c == EXIT || c == PLAYER)
		render_sprite(game, game->floor, x, y);
	if (c == WALLS)
		render_sprite(game, game->wall, x, y);
}

void	render_map(t_game *game)
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
}
