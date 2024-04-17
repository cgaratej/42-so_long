/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:42:56 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/17 16:52:40 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	count_elements(t_counter *cn, char c)
{
	if (c == collect)
		cn->collectible++;
	else if (c == portal)
		cn->exit++;
	else if (c == player)
		cn->start++;
	else if (c == floor)
		cn->empty++;
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

void	init_map(t_game *game, char *path)
{
	int	fd;

	fd = open_file(path);
	read_map(game, fd);
	game->plot.length = len_map_validation(game->plot.map, game);
	close(fd);
	return ;
}
