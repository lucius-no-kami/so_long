/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:01:30 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/08 12:51:49 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_arguments(int ac, char **av, t_game *game)
{
	if (!game)
	{
		ft_printf(RED"Error\nMemory couldn't be allocate for t_game.");
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		ft_printf("%sError\n%sUsage: %s <file_name.ber>", RED, WHITE, av[0]);
		free(game);
		exit(EXIT_FAILURE);
	}
	if (!ft_strnstr(av[1], ".ber", -1))
	{
		ft_printf("%sError\n%sIncorrect map extention.(.ber exepected)", \
		RED, WHITE);
		free(game);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_game	*game;

	ft_printf(CYAN"\n\
███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗ \n\
██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝ \n\
███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗\n\
╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║\n\
███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝\n\
╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ \n"RESET);
	game = (t_game *)malloc(sizeof(t_game));
	check_arguments(ac, av, game);
	init_map(game, av[1]);
	init_vars(game);
	check_map_validity(game);
	init_game(game);
	init_imgs(game);
	render_map(game);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, input_handling, game);
	mlx_hook(game->mlx_win, DestroyNotify, ButtonPressMask, free_memory, game);
	mlx_loop_hook(game->mlx, render_map, game);
	mlx_loop(game->mlx);
	free_memory(game);
	return (0);
}
