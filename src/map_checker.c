/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:31:57 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/24 13:11:05 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void invalid_map(int i)
{
	if (!(ft_strchr("P0EC1\n", i)))
	{
		ft_putstr_fd("Invalid map", 1);
		write(1, "\n", 1);
		// exit(1);
	}
}

void check_map_stuff(char *map)
{
	int i = 0;
	int c = 0;
	int e = 0;
	int p = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			c++;
		else if (map[i] == 'E')
			e++;
		else if (map[i] == 'P')
			p++;
		else
			invalid_map(map[i]);
		i++;
	}
	if (c < 1 || e != 1 || p != 1)
	{
		ft_putstr_fd("check coins players and collectables", 1);
		write(1, "\n", 1);
	}
}

void map_shape(char **grid)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(grid[i]);
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != len)
		{
			ft_putstr_fd("not a rectangle", 1);
			write(1, "\n", 1);
			// exit(1);
		}
		i++;
	}
}

void horizontal_check(t_game *game)
{
	size_t i;
	size_t h;

	h = game->height - 1;
	i = 0;
	while (game->grid[0][i])
	{
		if (game->grid[0][i] != '1')
		{
			ft_putstr_fd("problem horz wall", 1);
			write(1, "\n", 1);
			// exit(1);
		}
		if (game->grid[h][i] != '1')
		{
			ft_putstr_fd("problem horz wall", 1);
			write(1, "\n", 1);
			// exit(1);
		}
		i++;
	}
}

void vertical_check(t_game *game)
{
	size_t i;
	size_t w;

	w = game->width - 1;
	i = 0;
	while (game->grid[i])
	{
		if (game->grid[i][0] != '1')
		{
			ft_putstr_fd("problem vert wall", 1);
			write(1, "\n", 1);
			// exit(1);
		}
		if (game->grid[i][w] != '1')
		{
			ft_putstr_fd("problem vert wall", 1);
			write(1, "\n", 1);
			// exit(1);
		}
		i++;
	}
}
void walls(t_game *game)
{
	horizontal_check(game);
	vertical_check(game);
}

int empty_map(char *map)
{
	int i;

	i = 0;
	if (!map[i])
	{
		ft_putstr_fd("empty map bruv", 1);
		write(1, "\n", 1);
		return (-1);
	}
	return (0);
}
void empty_lines(char *map)
{
	size_t i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n'))
		{
			ft_putstr_fd("empty lines in map", 1);
			write(1, "\n", 1);
			break;
		}
		i++;
	}
}

void check_file_extension( char *file)
{
	size_t len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4))
	{
		printf("give a bratan .ber file.\n");
		exit(1);
	}
}

/* 	0 for an empty space
	1 for a wall
	C for a collectible > 1
	E for a map exit // eden exit
	P for the player’s starting position 1 postion to be valid
*/