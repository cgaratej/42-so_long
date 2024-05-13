/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animatios_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:14:32 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/13 10:19:10 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	anim_left(t_game *game, int y, int x)
{
	if (game->i.movements % 3 == 0)
		put_img(game, y, x, game->sprite_l2.img);
	else if (game->i.movements % 2 == 0)
		put_img(game, y, x, game->sprite_l1.img);
	else
		put_img(game, y, x, game->sprite_l.img);
}

void	anim_rigth(t_game *game, int y, int x)
{
	if (game->i.movements % 3 == 0)
		put_img(game, y, x, game->sprite_r2.img);
	else if (game->i.movements % 2 == 0)
		put_img(game, y, x, game->sprite_r1.img);
	else
		put_img(game, y, x, game->sprite_r.img);
}

void	anim_back(t_game *game, int y, int x)
{
	if (game->i.movements % 3 == 0)
		put_img(game, y, x, game->sprite_f2.img);
	else if (game->i.movements % 2 == 0)
		put_img(game, y, x, game->sprite_f1.img);
	else
		put_img(game, y, x, game->sprite_f.img);
}

void	anim_front(t_game *game, int y, int x)
{
	if (game->i.movements % 3 == 0)
		put_img(game, y, x, game->sprite_2.img);
	else if (game->i.movements % 2 == 0)
		put_img(game, y, x, game->sprite_1.img);
	else
		put_img(game, y, x, game->sprite.img);
}
