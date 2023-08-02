/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bgr_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:42:51 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/02 13:38:11 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*grass(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./textures/Grass.png");
	if (!grass)
		ft_putstr_fd("small problem with loading png", 1);
	img->grass = mlx_texture_to_image(mlx, grass);
	if (!img->grass)
		ft_putstr_fd("small problem with texture to image", 1);
	mlx_delete_texture(grass);
	return (img);
}

t_img	*bush(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*bush;

	bush = mlx_load_png("./textures/Bush.png");
	if (!bush)
		ft_putstr_fd("small problem with loading png", 1);
	img->bush = mlx_texture_to_image(mlx, bush);
	if (!img->bush)
		ft_putstr_fd("small problem with texture to image", 1);
	mlx_delete_texture(bush);
	return (img);
}

t_img	*exit_open(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./textures/Exit_Open.png");
	if (!exit)
		ft_putstr_fd("small problem with loading png", 1);
	img->exit_open = mlx_texture_to_image(mlx, exit);
	if (!img->exit_open)
		ft_putstr_fd("small problem with texture to image", 1);
	mlx_delete_texture(exit);
	return (img);
}

t_img	*exit_closed(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./textures/Exit_Closed.png");
	if (!exit)
		ft_putstr_fd("small problem with loading png", 1);
	img->exit_closed = mlx_texture_to_image(mlx, exit);
	if (!img->exit_closed)
		ft_putstr_fd("small problem with texture to image", 1);
	mlx_delete_texture(exit);
	return (img);
}
