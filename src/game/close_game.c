/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 08:52:20 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/01 15:03:15 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.row)
		free(game->map.map[i++]);
	free(game->map.map);
}

void	destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.xpm_ptr);
	mlx_destroy_image(game->mlx, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx, game->exit.xpm_ptr);
	mlx_destroy_image(game->mlx, game->coin.xpm_ptr);
}

void	error_msg(char *msg, t_game *game)
{
	ft_printf("%sError\n%s%s", RED, RESET, msg);
	if (game->map_alloc == 1)
		free_map(game);
	free(game);
	exit(EXIT_FAILURE);
}

void	free_memory(t_game *game)
{
	destroy_img(game);
	free_map(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}
