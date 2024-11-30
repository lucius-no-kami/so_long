/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:07:09 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/30 13:58:25 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <libft.h>
# include <mlx.h>

# define EMPTY_SPACE	'0'
# define WALLS			'1'
# define COLLECTIBLE	'C'
# define ESCAPE			'E'
# define SPAWN			'P'

# define RED			"\033[0;31m"
# define WHITE			"\x1B[37m"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**map;
	int		row;
	int		collum;
	t_pos	player_pos;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		cmove;
	t_map	*map;
}	t_game;

#endif /* SO_LONG_H */