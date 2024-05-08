/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:42:44 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/08 13:49:33 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <errno.h>
# include "../utils/libft/ft_printf/ft_printf.h"
# include "../utils/libft/get_next_line/get_next_line.h"
# include "../utils/libft/libft.h"
# include "../utils/minilibx/mlx.h"
# include "so_utils_bonus.h"
# include "path_bonus.h"

/*Window and Images*/
t_img		new_sprite(void *mlx, char *path);
void		init_images(t_game *game);

/*Game over*/
void		destroy_image(t_game *game);
void		game_over(char *message, t_game *game, enum e_state i);
void		free_map(t_draw *game);

/* Map */
t_counter	new_counter(void);
void		init_map(t_game *game, char *path);
int			open_file(char *path);
int			len_map_validation(char **map, t_game *game);
void		check_num_elemts_valids(t_game *game, \
				t_counter *cn, char *string_map);
int			is_double_line(char *string_map, int i);
void		render_map(t_game *game, int bol);
int			is_surrounded_by_walls(t_game *game, int y, int x);
int			is_character_valid(t_game *game, int y, int x);
int			is_rectangular(t_game *game);
t_draw		new_map(void);
t_draw		map_dup(t_game *game);

/* Movements */
int			key_check(int keycode, t_game *game);
void		print_moves(t_game *game);
void		mov_player(t_game *game, int new_y, int new_x);

/* Window */
int			red_cross(t_game *game);
void		init_window(t_game *game);

#endif