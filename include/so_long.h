/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:07:09 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/29 12:20:49 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define EMPTY_SPACE '0'
# define WALLS '1'
# define COLLECTIBLE 'C'
# define ESCAPE 'E'
# define SPAWN 'P'

# include <libft.h>
# include <mlx.h>

void	so_long(char *map_name);
char	**parsing_map(char *map_name);
void	check_map_rules(char **map);
void	free_tab(char **tab);

#endif /* SO_LONG_H */