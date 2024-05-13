/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:42:56 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/13 10:18:22 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void				flood_fill(t_draw *map, int x, int y);
static void			read_map(t_game *game, int fd);
static void			count_elements(t_counter *cn, char c);
static t_counter	start_counter(char *string_map, t_game *game);

void	init_map(t_game *game, char *path)
{
	int		fd;
	t_draw	tmp;

	fd = open_file(path);
	game->plot = new_map();
	read_map(game, fd);
	game->plot.length = len_map_validation(game->plot.map, game);
	render_map(game, 0);
	tmp = map_dup(game);
	flood_fill(&tmp, game->player_pos.x, game->player_pos.y);
	if (game->i.collectible != tmp.ncoins || \
		game->i.exit != tmp.nexit)
	{
		free_map(&game->plot);
		free_map(&tmp);
		game_over("Invalid, file!", game, error);
	}
	free_map(&tmp);
	close(fd);
	return ;
}

void	flood_fill(t_draw *map, int x, int y)
{
	if (x < 0 || x >= map->length || y < 0 || y >= map->height || \
		map->map[y][x] == wall || map->map[y][x] == 'F')
		return ;
	if (map->map[y][x] == 'C')
		map->ncoins++;
	if (map->map[y][x] == 'E')
		map->nexit++;
	map->map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static void	read_map(t_game *game, int fd)
{
	char	*tmp;

	tmp = ft_strdup("");
	game->plot.height = 0;
	while (fd)
	{
		game->plot.line = get_next_line(fd);
		if (game->plot.line == NULL)
			break ;
		tmp = ft_strjoin_gnl(tmp, game->plot.line);
		free(game->plot.line);
		game->plot.height++;
	}
	game->i = start_counter(tmp, game);
	game->plot.map = ft_split(tmp, '\n');
	free(tmp);
	return ;
}

static t_counter	start_counter(char *string_map, t_game *game)
{
	t_counter	cn;
	int			i;

	cn = new_counter();
	i = 0;
	while (string_map[i])
	{
		if (is_double_line(string_map, i))
		{
			free(string_map);
			game_over("Invalid, file!", game, file_error);
		}
		count_elements(&cn, string_map[i]);
		i++;
	}
	check_num_elemts_valids(game, &cn, string_map);
	return (cn);
}

static void	count_elements(t_counter *cn, char c)
{
	if (c == coin)
		cn->collectible++;
	else if (c == door)
		cn->exit++;
	else if (c == player)
		cn->start++;
	else if (c == floor)
		cn->empty++;
}
