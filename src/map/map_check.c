/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:13:02 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/17 14:34:55 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_num_elemts_valids(t_game *game, t_counter *cn, char *tmp)
{
	if (!(cn->collectible > 0 && cn->exit == 1
			&& cn->start == 1 && cn->empty > 0))
	{
		free(tmp);
		game_over("Invalid, file!", game, file_error);
	}
}

int	is_rectangular(t_game *game)
{
	if (game->plot.height == game->plot.length)
		return (0);
	return (1);
}

int	is_character_valid(t_game *game, int y, int x)
{
	if (!ft_strchr("10CEP", game->plot.map[y][x]))
		return (0);
	return (1);
}

int	is_double_line(char *string_map, int i)
{
	return ((string_map[i] == '\n') && (ft_strchr("\n\0", string_map[i + 1])));
}

int	is_surrounded_by_walls(t_game *game, int y, int x)
{
	if ((game->plot.map[game->plot.height - 1][x] != wall) ||
		(game->plot.map[0][x] != wall) || (game->plot.map[y] \
		[game->plot.length - 1] != wall) || game->plot.map[y][0] != wall)
		return (0);
	return (1);
}
