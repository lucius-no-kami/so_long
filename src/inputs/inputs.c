/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:00:05 by luluzuri          #+#    #+#             */
/*   Updated: 2024/12/02 17:41:31 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	input_handling(int keycode, t_game *game)
{
	//ft_printf(MAGENTA"key -> %c ;; keycode -> %d\n"RESET, keycode, keycode);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		close_game(game);
	return (0);
}
