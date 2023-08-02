/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:31:57 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/01 16:53:51 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	invalid_map(int i)
{
	if (!(ft_strchr("P0EC1\n", i)))
	{
		ft_putstr_fd("Invalid map", 1);
		write(1, "\n", 1);
		return (-1);
	}
	return (0);
}

int	check_map_stuff(char *map)
{
	int	c;
	int	e;
	int	p;

	c = 0;
	e = 0;
	p = 0;
	while (*map)
	{
		if (*map == 'C')
			c++;
		else if (*map == 'E')
			e++;
		else if (*map == 'P')
			p++;
		else if (invalid_map(*map) == -1)
			return (-1);
		map++;
	}
	if (c < 1 || e != 1 || p != 1)
	{
		ft_putstr_fd("check coins players and collectables \n", 1);
		return (-1);
	}
	return (0);
}

int	horizontal_check(t_game *game)
{
	size_t	i;
	size_t	h;

	h = game->height - 1;
	i = 0;
	while (game->grid[0][i])
	{
		if (game->grid[0][i] != '1')
		{
			ft_putstr_fd("problem horz wall", 1);
			write(1, "\n", 1);
			return (-1);
		}
		if (game->grid[h][i] != '1')
		{
			ft_putstr_fd("problem horz wall", 1);
			write(1, "\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	vertical_check(t_game *game)
{
	size_t	i;
	size_t	w;

	w = game->width - 1;
	i = 0;
	while (game->grid[i])
	{
		if (game->grid[i][0] != '1')
		{
			ft_putstr_fd("problem vert wall", 1);
			write(1, "\n", 1);
			return (-1);
		}
		if (game->grid[i][w] != '1')
		{
			ft_putstr_fd("problem vert wall", 1);
			write(1, "\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

/* 	0 for an empty space
	1 for a wall
	C for a collectible > 1
	E for a map exit // eden exit
	P for the player’s starting position 1 postion to be valid
*/