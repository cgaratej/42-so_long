/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:11:20 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/16 14:34:45 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->tree.img);
	mlx_destroy_image(game->mlx_ptr, game->floor.img);
	mlx_destroy_image(game->mlx_ptr, game->portal.img);
	mlx_destroy_image(game->mlx_ptr, game->collect.img);
	mlx_destroy_image(game->mlx_ptr, game->sprite.img);
	mlx_destroy_image(game->mlx_ptr, game->sprite_l.img);
	mlx_destroy_image(game->mlx_ptr, game->sprite_r.img);
	mlx_destroy_image(game->mlx_ptr, game->sprite_f.img);
	mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	//mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	return ;
}
