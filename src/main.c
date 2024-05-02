/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:37:28 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/02 15:29:04 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_game(t_game *game, char *path);
static int	is_ber_file(const char *argv);
static void	init_hook(t_game *game, int event, int mask, int (*f)());

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc > 2)
		game_over("Can't open multiple files!", &game, error);
	else if (argc < 2)
		game_over("Please specify file name!", &game, error);
	else if (argc == 2)
	{
		if (is_ber_file(argv[1]))
			init_game(&game, argv[1]);
		else
			game_over("The file is invalid!", &game, error);
	}
	return (0);
}

static void	init_game(t_game *game, char *path)
{
	init_map(game, path);
	init_window(game);
	init_images(game);
	render_map(game, 1);
	init_hook(game, 2, 0, key_check);
	init_hook(game, 17, 0, red_cross);
	mlx_loop(game->mlx_ptr);
}

static int	is_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '.');
	if (string)
		return (ft_strncmp(string, ".ber", ft_strlen(string)) == 0);
	return (0);
}

static void	init_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(
		game->window_ptr, \
		event, \
		mask, \
		f, \
		game);
}

int	red_cross(t_game *game)
{
	game_over("", game, event_ending);
	return (0);
}
