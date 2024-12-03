/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:35:18 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/03 18:02:44 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "X11/keysym.h"
#include "mlx_linux/mlx.h"

/* IMAGE SIZE */
#define	IMG_SIZE	64

/* IMAGES */
#define FLOOR_PTH	"./floor.xpm"
#define WALL_PTH	"./wall.xpm"
#define PLAYER_PTH	"./player.xpm"
#define COIN_PTH	"./coin.xpm"

/* COLOR */
#define CYAN	"\033[0;36m"
#define RESET	"\033[0m"

/* KEYS */
#define KEY_A	97
#define KEY_W	119
#define KEY_S	115
#define KEY_D	100

#define KEY_Q		113
#define KEY_ESC		65307

typedef struct	s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct	s_vars
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	floor;
	t_img	player;
}	t_vars;

void	error_msg(char *msg, t_vars *vars)
{
	printf("%s\n", msg);
	mlx_destroy_image(vars->mlx_ptr, vars->floor.img);
	mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	printf("\nExiting So_long");
	exit(EXIT_SUCCESS);
}

int	close_game(t_vars *vars)
{
	error_msg("Closing game carrefully", vars);
}

int	escape(int keycode, t_vars *vars)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
		error_msg("Game got safely closed.", vars);
	return (0);
}

int	main(void)
{
	t_vars	*vars;
	int		x;

	x = 0;
	printf(CYAN"\n\
	.▄▄ ·       ▄▄▌         ▐ ▄  ▄▄ • \n\
	▐█ ▀. ▪     ██•  ▪     •█▌▐█▐█ ▀ ▪\n\
	▄▀▀▀█▄ ▄█▀▄ ██▪   ▄█▀▄ ▐█▐▐▌▄█ ▀█▄\n\
	▐█▄▪▐█▐█▌.▐▌▐█▌▐▌▐█▌.▐▌██▐█▌▐█▄▪▐█\n\
	▀▀▀▀  ▀█▄▀▪.▀▀▀  ▀█▄▀▪▀▀ █▪·▀▀▀▀ \n"RESET);
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		error_msg("mlx_ptr couldn't be created", vars);
	vars->mlx_win = mlx_new_window(vars->mlx_ptr, (IMG_SIZE * 15), (IMG_SIZE * 10), "So_long");
	if (!vars->mlx_win)
		error_msg("mlx_win couldn't be create", vars);
	vars->floor.img = mlx_xpm_file_to_image(vars->mlx_ptr, FLOOR_PTH, \
	&vars->floor.width, &vars->floor.height);
	vars->player.img = mlx_xpm_file_to_image(vars->mlx_ptr, PLAYER_PTH, \
	&vars->player.width, &vars->player.height);
	printf("vars->img_width: %d\nvars->img_height: %d\n", \
	vars->floor.width, vars->floor.height);
	printf("vars->img_width: %d\nvars->img_height: %d\n", \
	vars->player.width, vars->player.height);
	mlx_put_image_to_window(vars->mlx_ptr, \
	vars->mlx_win, vars->floor.img, ((x % vars->floor.width) * IMG_SIZE), ((x / vars->floor.height) * IMG_SIZE));
	x = 5;
	mlx_put_image_to_window(vars->mlx_ptr, \
	vars->mlx_win, vars->floor.img, ((x % vars->floor.width) * IMG_SIZE), ((x / vars->floor.height) * IMG_SIZE));
	x = 0;
	mlx_put_image_to_window(vars->mlx_ptr, \
	vars->mlx_win, vars->player.img, ((x % vars->player.width) * IMG_SIZE), ((x / vars->player.height) * IMG_SIZE));
	mlx_hook(vars->mlx_win, 2, (1L << 0), escape, vars);
	mlx_hook(vars->mlx_win, 17, (1L << 2), close_game, vars);
	mlx_loop(vars->mlx_ptr);
}
