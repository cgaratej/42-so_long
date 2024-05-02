/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:16:22 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/02 15:43:36 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	key_check(int keycode, t_game *game)
{
	game->sprite.mem = 0;
	if (keycode == ESC)
		game_over("", game, event_ending);
	else if (keycode == UP || keycode == W)
		mov_player(game, game->player_pos.y - 1, game->player_pos.x);
	else if (keycode == DOWN || keycode == S)
		mov_player(game, game->player_pos.y + 1, game->player_pos.x);
	else if (keycode == LEFT || keycode == A)
		mov_player(game, game->player_pos.y, game->player_pos.x - 1);
	else if (keycode == RIGHT || keycode == D)
		mov_player(game, game->player_pos.y, game->player_pos.x + 1);
	return (0);
}

void	print_moves(t_game *game)
{
	game->i.movements += 1;
	ft_printf("\rMovements: %d", game->i.movements);
}
