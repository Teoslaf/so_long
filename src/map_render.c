/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:23:51 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/01 16:55:53 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_select(t_game *data, size_t y, size_t x)
{
	size_t	img_size;

	img_size = 32;
	if (data->grid[y][x] == '1')
		if (mlx_image_to_window(data->mlx, data->img->bush, x * 64, y * 64) < 0)
			ft_putstr_fd("problem with img", 1);
	if (data->grid[y][x] == 'C')
		if (mlx_image_to_window(data->mlx, data->img->rupee, x * 64 + img_size
				/ 2, y * 64 + img_size / 2) < 0)
			ft_putstr_fd("problem with img", 1);
	if (data->grid[y][x] == 'P')
		if (mlx_image_to_window(data->mlx, data->img->link, x * 64, y * 64) < 0)
			ft_putstr_fd("problem with img", 1);
	if (data->grid[y][x] == 'E')
		if (mlx_image_to_window(data->mlx, data->img->exit_closed, x * 64, y
				* 64) < 0)
			ft_putstr_fd("problem with img", 1);
}

void	fill_bg(t_game *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (mlx_image_to_window(data->mlx, data->img->grass, x * 64, y
					* 64) < 0)
				ft_putstr_fd("problem with img", 1);
			x++;
		}
		y++;
	}
}

void	map_render(t_game *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			img_select(data, y, x);
			x++;
		}
		y++;
	}
}
