/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:07:25 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/16 14:58:05 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nInvalid file\n");
		exit(1);
	}
	return (fd);
}


static void	line_validation(char **map, t_game *game)
{
	int		i;
	t_point	point;

	(void)*game;
	i = 0;
	point.x = 0;
	while (map[i] != 0)
	{
		point.x = ft_strlen(map[i]);
		if (point.x != point.y)
			ft_printf("error de lieneas no iguales");
		i++;
	}
}

int	len_map_validation(char **map, t_game *game)
{
	line_validation(map, game);
	return (ft_strlen(map[0]));
}
