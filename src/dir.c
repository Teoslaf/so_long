/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:44:50 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/01 17:27:29 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_rupees(t_game *game, int y, int x)
{
	size_t	i;

	i = 0;
	x = x * 64 + 16;
	y = y * 64 + 16;
	while (i < game->img->rupee->count)
	{
		if (game->img->rupee->instances[i].x == x
			&& game->img->rupee->instances[i].y == y)
			game->img->rupee->instances[i].enabled = false;
		i++;
	}
}

t_game	*move_up(t_game *game)
{
	if (game->grid[game->link_y - 1][game->link_x] != '1'
		&& game->grid[game->link_y - 1][game->link_x] != 'E')
	{
		if (game->grid[game->link_y - 1][game->link_x] == 'C')
		{
			delete_rupees(game, game->link_y - 1, game->link_x);
			game->grid[game->link_y - 1][game->link_x] = '0';
			game->collected += 1;
		}
		game->link_y -= 1;
		game->img->link->instances[0].y -= 1 * 64;
		game->steps += 1;
	}
	check_game(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->grid[game->link_y + 1][game->link_x] != '1'
		&& game->grid[game->link_y + 1][game->link_x] != 'E')
	{
		if (game->grid[game->link_y + 1][game->link_x] == 'C')
		{
			delete_rupees(game, game->link_y + 1, game->link_x);
			game->grid[game->link_y + 1][game->link_x] = '0';
			game->collected += 1;
		}
		game->link_y += 1;
		game->img->link->instances[0].y += 1 * 64;
		game->steps += 1;
	}
	check_game(game);
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->grid[game->link_y][game->link_x + 1] != '1'
		&& game->grid[game->link_y][game->link_x + 1] != 'E')
	{
		if (game->grid[game->link_y][game->link_x + 1] == 'C')
		{
			delete_rupees(game, game->link_y, game->link_x + 1);
			game->grid[game->link_y][game->link_x + 1] = '0';
			game->collected += 1;
		}
		game->link_x += 1;
		game->img->link->instances[0].x += 1 * 64;
		game->steps += 1;
	}
	check_game(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->grid[game->link_y][game->link_x - 1] != '1'
		&& game->grid[game->link_y][game->link_x - 1] != 'E')
	{
		if (game->grid[game->link_y][game->link_x - 1] == 'C')
		{
			delete_rupees(game, game->link_y, game->link_x - 1);
			game->grid[game->link_y][game->link_x - 1] = '0';
			game->collected += 1;
		}
		game->link_x -= 1;
		game->img->link->instances[0].x -= 1 * 64;
		game->steps += 1;
	}
	check_game(game);
	return (game);
}
