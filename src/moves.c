/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:59:22 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/02 13:09:09 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, char line, char direction)
{
	if (line == 'y')
	{
		if (direction == 'u')
			move_up(game);
		else
			move_down(game);
	}
	if (line == 'x')
	{
		if (direction == 'r')
			move_right(game);
		else
			move_left(game);
	}
}

void	game_loop(t_game *game)
{
	while (1)
	{
		mlx_loop(game->mlx);
		mlx_image_to_window(game->mlx, game->img->link, 0, 0);
		print_moves(game);
	}
}

void	move_hook(mlx_key_data_t key, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
		move_player(game, 'y', 'u');
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		move_player(game, 'y', 'u');
	if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
		move_player(game, 'x', 'r');
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		move_player(game, 'x', 'r');
	if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
		move_player(game, 'y', 'd');
	if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		move_player(game, 'y', 'd');
	if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
		move_player(game, 'x', 'l');
	if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		move_player(game, 'x', 'l');
}

void	print_moves(t_game *game)
{
	static size_t	printed;

	if (printed == 0)
	{
		game->steps = 1;
		ft_putstr_fd("Number of moves: ", 1);
		ft_putnbr_fd(game->steps, 1);
		ft_putstr_fd("\n", 1);
		printed = game->steps;
	}
	else if (game->steps != printed)
	{
		ft_putstr_fd("Number of moves: ", 1);
		ft_putnbr_fd(game->steps, 1);
		ft_putstr_fd("\n", 1);
		printed = game->steps;
	}
}
