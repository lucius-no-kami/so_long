/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:03:48 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/29 11:47:24 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] != NULL)
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	free(tab);
	exit(EXIT_FAILURE);
}

static int	count_line(char *map_file)
{
	int	fd;
	int	count;

	count = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nIn count_line , couldn't open the file.");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd))
		count++;
	close(fd);
	return (count);
}

static char	**get_map(int fd, char **tab, int numLines)
{
	int	i;

	i = 0;
	tab = (char **)malloc((numLines + 1) * sizeof(char *));
	if (!tab)
	{
		ft_printf("Error\nCoudn't not malloc. (fill_2dtab: line 29)");
		exit(EXIT_FAILURE);
	}
	while (i < numLines)
	{
		tab[i] = get_next_line(fd);
		if (tab[i] == NULL)
		{
			ft_printf("Error\nCouldn't fill the 2d tab.");
			free_tab(tab);
		}
		i++;
	}
	tab[numLines] = 0;
	return (tab);
}

static char	**read_file(char *map_name, char **tab)
{
	char	*line;
	int		fd;
	int		count;

	line = "";
	count = count_line(map_name);
	if (count <= 0)
	{
		ft_printf("Error\nMap file is empty.");
		exit(EXIT_FAILURE);
	}
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCouldn't open map file.");
		exit(EXIT_FAILURE);
	}
	ft_printf("count value: %d\n", count);
	tab = get_map(fd, tab, count);
	close(fd);
	return (tab);
}

char	**parsing_map(char *map_name	)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	tab = read_file(map_name, tab);
	while (tab[i])
	{
		ft_printf("line %d: %s\n", i, tab[i]);
		i++;
	}
	return (tab);
}
