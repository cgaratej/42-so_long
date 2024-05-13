/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:47:16 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/13 10:19:05 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_valid_mov(t_game *game, int y, int x);

void	mov_player(t_game *game, int new_y, int new_x)
{
	if (check_valid_mov(game, new_y, new_x))
	{
		game->plot.map[game->player_pos.y][game->player_pos.x] = floor;
		game->player_pos.y = new_y;
		game->player_pos.x = new_x;
		game->plot.map[new_y][new_x] = player;
		render_map(game, 1);
		print_moves(game);
	}
}

int	check_valid_mov(t_game *game, int y, int x)
{
	if (x < 0 || y < 0 || x >= game->plot.length || y >= game->plot.height)
		return (0);
	if (game->i.collectible == 0 && game->plot.map[y][x] == door)
	{
		game_over(GREEN"\n\nYou Win! 🏅"ENDC, game, end_game);
	}
	if (game->plot.map[y][x] == enemy)
	{
		game_over(RED"\n\nYou Died"ENDC, game, deat);
	}
	if (game->plot.map[y][x] == coin)
		game->i.collectible--;
	return (game->plot.map[y][x] == floor || game->plot.map[y][x] == coin \
		|| game->plot.map[y][x] == player);
}
