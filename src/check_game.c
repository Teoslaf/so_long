/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:59:08 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/01 18:00:01 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_game(t_game *game)
{
	print_moves(game);
	if (game->collected == game->rupees)
	{
		if (mlx_image_to_window(game->mlx, game->img->exit_open, game->exit_x
				* 64, game->exit_y * 64) < 0)
			ft_putstr_fd("pic prob", 1);
		game->grid[game->exit_y][game->exit_x] = '0';
	}
	if (game->link_y == game->exit_y && game->link_x == game->exit_x)
	{
		mlx_close_window(game->mlx);
		ft_putstr_fd("gg\n", 1);
	}
}
