/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:27:37 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/01 15:03:50 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		error_msg("There is an empty line at the beginning.", game);
	}
	if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		error_msg("There is an empty line at the end.", game);
	}
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error_msg("There is an empty line at the middle.", game);
		}
		i++;
	}
}

void	init_map(t_game *game, char *map_name)
{
	char	*map_temp;
	char	*line_tmp;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_msg("Couldn't open the file", game);
	map_temp = ft_strdup("");
	game->map.row = 0;
	while (1)
	{
		line_tmp = get_next_line(fd);
		if (line_tmp == NULL)
			break ;
		map_temp = gnl_strjoin(map_temp, line_tmp);
		free(line_tmp);
		game->map.row++;
	}
	check_empty_line(map_temp, game);
	game->map.map = ft_split(map_temp, '\n');
	game->map_alloc = 1;
	free(map_temp);
}