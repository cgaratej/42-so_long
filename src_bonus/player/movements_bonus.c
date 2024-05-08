/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:16:22 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/08 18:10:42 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

int	key_check(int keycode, t_game *game)
{
	game->sprite.mem = 0;
	if (keycode == ESC)
		game_over("", game, event_ending);
	else if (keycode == UP || keycode == W)
	{
		game->sprite.mem = up;
		mov_player(game, game->player_pos.y - 1, game->player_pos.x);
	}
	else if (keycode == DOWN || keycode == S)
	{
		game->sprite.mem = down;
		mov_player(game, game->player_pos.y + 1, game->player_pos.x);
	}
	else if (keycode == LEFT || keycode == A)
	{
		game->sprite.mem = left;
		mov_player(game, game->player_pos.y, game->player_pos.x - 1);
	}
	else if (keycode == RIGHT || keycode == D)
	{
		game->sprite.mem = right;
		mov_player(game, game->player_pos.y, game->player_pos.x + 1);
	}
	return (0);
}

void	print_moves(t_game *game)
{
	char	*num;

	game->i.movements += 1;
	num = ft_itoa(game->i.movements);
	mlx_string_put(game->mlx_ptr, game->window_ptr, \
		10, 10, 0x50ffffff, "Movements:");
	mlx_string_put(game->mlx_ptr, game->window_ptr, \
		115, 10, 0x50ffffff, num);
	ft_printf("\rMovements: %d", game->i.movements);
	free(num);
}
