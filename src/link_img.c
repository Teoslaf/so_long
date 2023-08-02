/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:19:20 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/02 13:38:16 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_link(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*link;

	link = mlx_load_png("./textures/Link.png");
	if (!link)
		ft_putstr_fd("small problem with loading png", 1);
	img->link = mlx_texture_to_image(mlx, link);
	if (!img->link)
		ft_putstr_fd("small problem with texture to image", 1);
	mlx_delete_texture(link);
	return (img);
}

t_img	*rupees(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*rupees;

	rupees = mlx_load_png("./textures/Rupee.png");
	if (!rupees)
		ft_putstr_fd("small problem with loading png", 1);
	img->rupee = mlx_texture_to_image(mlx, rupees);
	if (!img->rupee)
		ft_putstr_fd("small problem with texture to image", 1);
	mlx_delete_texture(rupees);
	return (img);
}
