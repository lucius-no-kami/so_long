/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:11:53 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/03 22:53:45 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_img	new_img(void *mlx, char *img_path, t_game *game)
{
	t_img	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, img_path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		error_msg("Image couldn't be created", game);
	return (sprite);
}

void	init_vars(t_game *game)
{
	game->cmove = 0;
	game->map.columns = ft_strlen(game->map.map[0]) - 1;
	game->map.player = 0;
	game->map.coin = 0;
	game->map.exit = 0;
	game->map.player = 0;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free(game->mlx);
		error_msg("Mlx ptr couldn't be created.", game);
	}
	game->mlx_win = mlx_new_window(game->mlx, \
	(game->map.columns * IMG_SIZE), (game->map.row * IMG_SIZE), "so_long");
	if (game->mlx_win == NULL)
	{
		free(game->mlx);
		error_msg("Window couldn't be created.", game);
	}
}

void	init_imgs(t_game *game)
{
	void	*mlx;

	mlx = game->mlx;
	game->floor = new_img(mlx, FLOOR_PTH, game);
	game->wall = new_img(mlx, WALLS_PTH, game);
	game->coin = new_img(mlx, COIN_PTH, game);
	game->exit = new_img(mlx, EXIT_PTH, game);
	game->player = new_img(mlx, PLAYER_PTH, game);
}
