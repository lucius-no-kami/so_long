/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:01:30 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/01 16:14:52 by luluzuri         ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	}
	if (!ft_strnstr(av[1], ".ber", -1))
	{
		ft_printf("%sError\n%sIncorrect map extention.(.ber exepected)", \
		RED, WHITE);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		i;

	i = 0;
	ft_printf(CYAN"\
.▄▄ ·       ▄▄▌         ▐ ▄  ▄▄ • \n\
▐█ ▀. ▪     ██•  ▪     •█▌▐█▐█ ▀ ▪\n\
▄▀▀▀█▄ ▄█▀▄ ██▪   ▄█▀▄ ▐█▐▐▌▄█ ▀█▄\n\
▐█▄▪▐█▐█▌.▐▌▐█▌▐▌▐█▌.▐▌██▐█▌▐█▄▪▐█\n\
 ▀▀▀▀  ▀█▄▀▪.▀▀▀  ▀█▄▀▪▀▀ █▪·▀▀▀▀ \n\
"RESET);
	ft_printf("\n");
	game = (t_game *)malloc(sizeof(t_game));
	check_arguments(ac, av, game);
	init_map(game, av[1]);
	check_char_in_map(game);
	while (i < game->map.row)
	{
		ft_printf("%s\n", game->map.map[i]);
		i++;
	}
	ft_printf("\n");
	free_map(game);
	free(game);
	return (0);
}
