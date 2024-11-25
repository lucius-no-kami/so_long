/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:02:35 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/25 15:25:47 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	char	*map_file;

	if (ac != 2)
	{
		ft_printf("Usage: %s <map_name.ber>\n", av[0]);
		return (1);
	}
	map_file = av[1];
	if (!ft_strnstr(map_file, ".ber", ft_strlen(map_file)))
	{
		ft_printf("Error: map file should finish by .ber, yours: %s.\n", \
		map_file);
		return (1);
	}
	return (0);
}
