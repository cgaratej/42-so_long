/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:11:20 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/29 17:22:09 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->tree.img);
	mlx_destroy_image(game->mlx_ptr, game->floor.img);
	mlx_destroy_image(game->mlx_ptr, game->door.img);
	mlx_destroy_image(game->mlx_ptr, game->coin.img);
	mlx_destroy_image(game->mlx_ptr, game->sprite.img);
	mlx_destroy_image(game->mlx_ptr, game->sprite_l.img);
	mlx_destroy_image(game->mlx_ptr, game->sprite_r.img);
	mlx_destroy_image(game->mlx_ptr, game->sprite_f.img);
	mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	free_map(&game->plot);
	free(game->mlx_ptr);
	return ;
}

void	free_map(t_draw *map)
{
	while (map->height > 0)
	{
		free(map->map[map->height - 1]);
		map->height--;
	}
	free(map->map);
	return ;
}

void	game_over(char *message, t_game *game, enum e_state i)
{
	if (i == event_ending || i == end_game)
	{
		ft_printf("%s\n", message);
		destroy_image(game);
		exit(0);
	}
	else if (i == error)
	{
		ft_printf(RED"Error\n%s\n"ENDC, message);
		exit(1);
	}
	else if (i == file_error)
	{
		ft_printf(RED"Error\n%s\n"ENDC, message);
		exit(1);
	}
	ft_printf(RED"Error\n%s\n"ENDC, message);
	destroy_image(game);
	exit(1);
	return ;
}
