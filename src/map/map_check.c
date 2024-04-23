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

#include "../../inc/so_long.h"

void	check_num_elemts_valids(t_game *game, t_counter *cn, char *tmp)
{
	if (!(cn->collectible > 0 && cn->exit == 1
			&& cn->start == 1 && cn->empty > 0))
	{
		free(tmp);
		game_over("Invalid, file!", game, error);
	}
}

int	is_double_line(char *string_map, int i)
{
	return ((string_map[i] == '\n') && (ft_strchr("\n\0", string_map[i + 1])));
}

/*int	is_surrounded_by_walls(t_game *game, int y, int x)
{

}*/
