/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:12:00 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/24 17:07:17 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	map_set_img(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == door)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, \
			game->door.img, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else if (game->plot.map[y][x] == wall)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, \
			game->tree.img, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else if (game->plot.map[y][x] == coin)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, \
			game->coin.img, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, \
			game->floor.img, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
}

static void	map_check_one(t_game *game, int y, int x)
{
	if (!is_surrounded_by_walls(game, y, x))
		game_over("Not surrounded by walls!", game, map_char_error);
	else if (!is_rectangular(game))
		game_over("Map is not rectangular!", game, map_char_error);
	else if (!is_character_valid(game, y, x))
		game_over("Invalid character in map", game, map_char_error);
	map_set_img(game, y, x);
	return ;
}

void	render_map(t_game *game)
{
	t_point	coord;

	coord.y = 0;
	while (game->plot.map[coord.y])
	{
		coord.x = 0;
		while (game->plot.map[coord.y][coord.x])
		{
			map_check_one(game, coord.y, coord.x);
			coord.x++;
		}
		coord.y++;
	}
}