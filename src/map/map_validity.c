/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:55:00 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/01 16:27:55 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
		if ((current_lline != game->map.collum) && i != 0)
			error_msg("One line is larger that the other", game);
		while (j++ < current_lline)
		{
			if (!ft_strchr("01CEP", game->map.map[i][j]))
				error_msg("Unexpected char in the map.", game);
		}
		game->map.collum = current_lline;
		i++;
	}
	if (game->map.row == game->map.collum)
		error_msg("The map is square, expected a rectangulare map", game);
}

// 0. Check if there is wall all over the rectangle
// 1. check if char in the map are valid
// 2. call a function to check map_validity
// 3. call a function to check valid path