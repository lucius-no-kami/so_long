/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:07:09 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/12 08:09:07 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "mlx.h"

/* IMG */
# define FLOOR_PTH		"assets/floor.xpm"
# define WALLS_PTH		"assets/wall.xpm"
# define COIN_PTH		"assets/coin.xpm"
# define EXIT_PTH		"assets/exit.xpm"
# define PLAYER_PTH		"assets/player.xpm"

# define IMG_SIZE		32

/* MAP */
# define FLOOR			'0'
# define WALLS			'1'
# define COIN			'C'
# define EXIT			'E'
# define PLAYER			'P'	

/* KEY */
# define KEY_Q			113
# define KEY_ESC		65307

# define KEY_A			97
# define KEY_W			119
# define KEY_S			115
# define KEY_D			100

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_RIGHT		65363
# define KEY_LEFT		65361

/* COLOR */
# define RED			"\033[0;31m"
# define WHITE			"\x1B[37m"
# define BLACK          "\033[0;30m"
# define GREEN          "\033[0;32m"
# define MAGENTA        "\033[0;35m"
# define CYAN           "\033[0;36m"
# define RESET          "\033[0m"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**map;
	int		row;
	int		columns;
	int		coin;
	int		exit;
	int		player;
	t_pos	player_pos;
}	t_map;

typedef struct s_img
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		cmove;
	int		map_alloc;
	t_map	map;
	t_img	floor;
	t_img	wall;
	t_img	coin;
	t_img	exit;
	t_img	player;
}	t_game;

void	init_map(t_game *game, char *map_name);
void	init_vars(t_game *game);
void	init_game(t_game *game);
void	init_imgs(t_game *game);
void	check_map_validity(t_game *game);
void	check_char_in_map(t_game *game);
void	count_map_value(t_game *game);
void	verify_map_value(t_game *game);
void	path_finder(t_game *game, t_map map);
int		render_map(t_game *game);
void	render_sprite(t_game *game, t_img sprite, int x, int y);
void	horizontal_movement(t_game *game, int x, int *y, int step);
void	vertical_movement(t_game *game, int *x, int y, int step);
int		input_handling(int keycode, t_game *game);
void	close_game(t_game *game);
void	destroy_img(t_game *game);
void	free_map(t_game *game);
int		free_memory(t_game *game);
void	error_msg(char *msg, t_game *game);

#endif /* SO_LONG_H */