/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:12:00 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/02 16:12:07 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	map_set_img(t_game *game, int y, int x);
static void	map_check_one(t_game *game, int y, int x);

void	render_map(t_game *game, int bol)
{
	t_point	coord;

	coord.y = 0;
	while (game->plot.map[coord.y])
	{
		coord.x = 0;
		while (game->plot.map[coord.y][coord.x])
		{
			if (!bol)
				map_check_one(game, coord.y, coord.x);
			else
				map_set_img(game, coord.y, coord.x);
			if (game->plot.map[coord.y][coord.x] == player && !bol)
			{
				game->player_pos.x = coord.x;
				game->player_pos.y = coord.y;
			}
			coord.x++;
		}
		coord.y++;
	}
}

static void	map_set_img(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == door)
	{
		if (game->i.collectible == 0)
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, \
				game->door_open.img, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
		else
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, \
				game->door.img, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	}
	else if (game->plot.map[y][x] == wall)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, \
			game->tree.img, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else if (game->plot.map[y][x] == coin)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, \
			game->coin.img, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else if (game->plot.map[y][x] == player)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, \
			game->sprite_f.img, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, \
			game->floor.img, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
}

static void	map_check_one(t_game *game, int y, int x)
{
	if (!is_surrounded_by_walls(game, y, x))
		game_over("Not surrounded by walls!", game, error);
	else if (!is_rectangular(game))
		game_over("Map is not rectangular!", game, error);
	else if (!is_character_valid(game, y, x))
		game_over("Invalid character in map", game, error);
	return ;
}

t_draw	map_dup(t_game *game)
{
	t_draw	tmp;
	int		i;

	i = 0;
	ft_memcpy(&tmp, &game->plot, sizeof(t_draw));
	tmp.map = malloc(game->plot.length * sizeof(char *));
	if (!tmp.map)
		exit(-1);
	while (i < game->plot.height)
	{
		tmp.map[i] = ft_strdup(game->plot.map[i]);
		i++;
	}
	return (tmp);
}
