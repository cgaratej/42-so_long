/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:16:22 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/30 16:02:51 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	key_check(int keycode, t_game *game)
{
	game->sprite.men = 0;
	if (keycode == ESC)
		game_over("", game, event_ending);
	else if (keycode == UP || keycode == W)
		ft_printf("arrba\n");
	else if (keycode == DOWN || keycode == S)
		ft_printf("abajo\n");
	else if (keycode == LEFT || keycode == A)
		ft_printf("izquierda\n");
	else if (keycode == RIGHT || keycode == D)
		ft_printf("derecha\n");
	return (0);
}
