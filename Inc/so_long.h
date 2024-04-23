/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:42:44 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/23 13:38:06 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <errno.h>
# include "../utils/libft/ft_printf/ft_printf.h"
# include "../utils/libft/get_next_line/get_next_line.h"
# include "../utils/libft/libft.h"
# include "../utils/minilibx/mlx.h"
# include "so_utils.h"
# include "path.h"

/*Window and Images*/
t_img		new_sprite(void *mlx, char *path);
void		init_images(t_game *game);
void		init_window(t_game *game);

/*Game over*/
void		destroy_image(t_game *game);
void		game_over(char *message, t_game *game, enum e_state i);
void		free_map(t_game *game);

/* Map */
t_counter	new_counter(void);
void		init_map(t_game *game, char *path);
int			open_file(char *path);
int			len_map_validation(char **map, t_game *game);
void		check_num_elemts_valids(t_game *game, \
		t_counter *cn, char *string_map);
int			is_double_line(char *string_map, int i);
void		render_map(t_game *game);
int			is_surrounded_by_walls(t_game *game, int y, int x);

#endif