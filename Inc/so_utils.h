/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:09:20 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/02 16:11:18 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_UTILS_H
# define SO_UTILS_H

# define W	13
# define S	1
# define A	0
# define D	2
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define ESC	53
# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"
# define SPRITE_SIZE	32

enum e_map
{
	floor = '0',
	wall = '1',
	coin = 'C',
	door = 'E',
	player = 'P',
};

enum e_state
{
	event_ending = -1,
	end_game = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		mem;
}		t_img;

typedef struct s_counter
{
	int		empty;
	int		collectible;
	int		exit;
	int		start;
	int		movements;
}		t_counter;

typedef struct s_draw
{
	char	**map;
	int		height;
	int		length;
	char	*line;
	int		ncoins;
	int		nexit;
}	t_draw;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*window_ptr;
	t_draw		plot;
	t_counter	i;
	t_point		player_pos;
	t_img		sprite;
	t_img		sprite_l;
	t_img		sprite_r;
	t_img		sprite_f;
	t_img		floor;
	t_img		tree;
	t_img		coin;
	t_img		door;
	t_img		door_open;
}		t_game;


#endif