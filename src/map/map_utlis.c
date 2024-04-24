/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:07:25 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/24 16:22:34 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(RED"Error\nInvalid file\n"ENDC);
		exit(1);
	}
	return (fd);
}

static void	line_validation(char **map, t_game *game)
{
	int		i;
	t_point	point;

	i = 0;
	point.x = 0;
	point.y = ft_strlen(map[0]);
	while (map[i] != 0)
	{
		point.x = ft_strlen(map[i]);
		if (point.x != point.y)
		{
			free_map(game);
			game_over("Invalid file: lines are not the same size!", \
				game, error);
		}
		i++;
	}
}

t_counter	new_counter(void)
{
	t_counter	counter;

	counter.empty = 0;
	counter.collectible = 0;
	counter.exit = 0;
	counter.start = 0;
	counter.movements = 0;
	return (counter);
}

int	len_map_validation(char **map, t_game *game)
{
	line_validation(map, game);
	return (ft_strlen(map[0]));
}