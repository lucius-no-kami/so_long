/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 08:52:20 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/12 08:11:57 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_game *game)
{
	if (game->floor.xpm_ptr != NULL)
		mlx_destroy_image(game->mlx, game->floor.xpm_ptr);
	if (game->wall.xpm_ptr != NULL)
		mlx_destroy_image(game->mlx, game->wall.xpm_ptr);
	if (game->coin.xpm_ptr != NULL)
		mlx_destroy_image(game->mlx, game->coin.xpm_ptr);
	if (game->exit.xpm_ptr != NULL)
		mlx_destroy_image(game->mlx, game->exit.xpm_ptr);
	if (game->player.xpm_ptr != NULL)
		mlx_destroy_image(game->mlx, game->player.xpm_ptr);
}

int	free_memory(t_game *game)
{
	destroy_img(game);
	free_map(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	ft_printf(RED"GAME CLOSED\n"RESET);
	exit(EXIT_FAILURE);
}

void	close_game(t_game *game)
{
	ft_printf(CYAN"\n\
██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗\n\
╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║\n\
 ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║\n\
  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║\n\
   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║\n\
   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝\n\
"RESET);
	ft_printf(GREEN"Movements: %d\n"RESET, game->cmove);
	free_memory(game);
}
