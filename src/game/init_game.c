/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:11:53 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/02 09:16:38 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_vars(t_game *game)
{
	game->cmove = 0;
	game->map.columns = ft_strlen(game->map.map[0]) - 1;
	game->map.player = 0;
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.player = 0;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_msg("Mlx ptr couldn't be created.", game);
	game->mlx_win = mlx_new_window(game->mlx, \
	(game->map.columns * IMG_SIZE), (game->map.row * IMG_SIZE), "so_long");
	if (!game->mlx_win)
		error_msg("Window couldn't be created.", game);
}
