/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:03:18 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/23 13:32:20 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_larger_than_window(t_game *game);

void	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (is_larger_than_window(game))
	{
		free_map(game);
		free(game->mlx_ptr);
		game_over("Map size larger than display resolution", game, error);
	}
	else
	{
		game->window_ptr = mlx_new_window(game->mlx_ptr, \
			(game->plot.length * SPRITE_SIZE), \
			(game->plot.height * SPRITE_SIZE), "./so_long");
	}
}

void	init_images(t_game *game)
{
	game->sprite = new_sprite(game->mlx_ptr, PATH_SPRITE);
	game->sprite_l = new_sprite(game->mlx_ptr, PATH_SPRITE_L);
	game->sprite_r = new_sprite(game->mlx_ptr, PATH_SPRITE_R);
	game->sprite_f = new_sprite(game->mlx_ptr, PATH_SPRITE_F);
	game->floor = new_sprite(game->mlx_ptr, PATH_FLOOR);
	game->tree = new_sprite(game->mlx_ptr, PATH_TREE);
}

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.h, &img.w);
	return (img);
}

static t_point	get_screen_size(t_game *game)
{
	t_point	point;

	mlx_get_screen_size(game->mlx_ptr, &point.x, &point.y);
	return (point);
}

static int	is_larger_than_window(t_game *game)
{
	t_point	screen_size;

	screen_size = get_screen_size(game);
	return (\
	((game->plot.length * SPRITE_SIZE) > screen_size.x) \
	|| \
	((game->plot.height * SPRITE_SIZE) > screen_size.y) \
	);
}
