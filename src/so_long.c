/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:01:30 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/03 15:23:32 by luluzuri         ###   ########.fr       */
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

	ft_printf("\n");
	ft_printf(CYAN"\
.▄▄ ·       ▄▄▌         ▐ ▄  ▄▄ • \n\
▐█ ▀. ▪     ██•  ▪     •█▌▐█▐█ ▀ ▪\n\
▄▀▀▀█▄ ▄█▀▄ ██▪   ▄█▀▄ ▐█▐▐▌▄█ ▀█▄\n\
▐█▄▪▐█▐█▌.▐▌▐█▌▐▌▐█▌.▐▌██▐█▌▐█▄▪▐█\n\
 ▀▀▀▀  ▀█▄▀▪.▀▀▀  ▀█▄▀▪▀▀ █▪·▀▀▀▀ \n\
"RESET);
	game = (t_game *)malloc(sizeof(t_game));
	check_arguments(ac, av, game);
	init_map(game, av[1]);
	init_vars(game);
	check_char_in_map(game);
	init_game(game);
	init_imgs(game);
	ft_printf("sprite x: %d ;; sprite y: %d\n", \
	((1 / game->map.columns) * IMG_SIZE), ((1 % game->map.columns) * IMG_SIZE));
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, input_handling, game);
	mlx_hook(game->mlx_win, DestroyNotify, SubstructureNotifyMask, free_memory, game);
	mlx_loop(game->mlx);
	free_memory(game);
	return (0);
}
