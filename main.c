/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:03:14 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/25 10:28:08 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Usage: %s <map_name.ber>", av[0]);
		return (1);
	}
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
	{
		ft_printf("Error: invalide .ber file.");
		return (1);
	}
	so_long(av[1]);
	return (0);
}
