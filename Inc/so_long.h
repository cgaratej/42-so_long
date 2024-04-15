/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:42:44 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/15 17:14:41 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <errno.h>
# include "libft/ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "../minilibx/mlx.h"
# include "so_utils.h"
# include "path.h"

/*Window and Images*/
t_win	new_window(int w, int h, char *str);
t_img	new_sprite(void *mlx, char *path);
void	set_images(t_game *game);

/*Game over*/


#endif