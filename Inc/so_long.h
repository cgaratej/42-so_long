/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:42:44 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/10 14:38:05 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1

# include <fcntl.h>
# include <errno.h>
# include "libft/ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

#endif