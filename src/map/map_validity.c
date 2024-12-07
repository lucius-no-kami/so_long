/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:55:00 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/07 11:28:31 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	check_walls(t_game *game)
{
	int	i;
	int	ligne_len;

	i = -1;
	ligne_len = ft_strlen(game->map.map[0]) - 1;
	while (game->map.map[0][++i])
		if (game->map.map[0][i] != WALLS)
			error_msg("Map is not surrounded by walls.", game);
	i = -1;
	while (game->map.map[game->map.row - 1][++i])
		if (game->map.map[game->map.row - 1][i] != WALLS)
			error_msg("Map is not surrounded by walls.", game);
	i = 0;
	while (game->map.map[++i])
	{
		if (game->map.map[i][0] != WALLS \
			|| game->map.map[i][ligne_len] != WALLS)
			error_msg("Map is not surrounded by walls.", game);
	}
	path_finder(game, game->map);
}

void	verify_map_value(t_game *game)
{
	if (game->map.player != 1)
		error_msg("The game can handle only one player", game);
	if (game->map.exit == 0)
		error_msg("The game should have atleast one exit", game);
	if (game->map.coin == 0)
		error_msg("The game should have atleast one coin", game);
	check_walls(game);
}

void	count_map_value(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.row)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.map[i][j] == FLOOR)
				game->map.floor++;
			else if (game->map.map[i][j] == WALLS)
				game->map.wall++;
			else if (game->map.map[i][j] == COIN)
				game->map.coin++;
			else if (game->map.map[i][j] == EXIT)
				game->map.exit++;
			else if (game->map.map[i][j] == PLAYER)
			{
				game->map.player++;
				game->map.player_pos.x = i;
				game->map.player_pos.y = j;
			}
		}
	}
}

void	check_char_in_map(t_game *game)
{
	int	i;
	int	j;
	int	current_lline;

	i = 0;
	while (game->map.map[i])
	{
		j = -1;
		current_lline = ft_strlen(game->map.map[i]);
		if ((current_lline != game->map.columns) && i != 0)
			error_msg("One line is larger that the other", game);
		while (j++ < current_lline)
		{
			if (!ft_strchr("01CEP", game->map.map[i][j]))
				error_msg("Unexpected char in the map.", game);
		}
		game->map.columns = current_lline;
		i++;
	}
	if (game->map.row == game->map.columns)
		error_msg("The map is square, expected a rectangulare map", game);
}
