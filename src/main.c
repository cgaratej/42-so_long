/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:37:28 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/15 12:34:42 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		width;
	int		height;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	img = mlx_xpm_file_to_image(mlx_ptr, "/Users/cgaratej/Documents/ComonCore/so_long/assets/tree.xpm", &width, &height);
	if (!img)
	{
		ft_printf("test");
		return (1);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 100, 100);
	mlx_loop(mlx_ptr);
}
