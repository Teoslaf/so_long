/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:44:07 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/01 17:27:27 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path(t_game *temp, size_t y, size_t x)
{
	if (temp->grid[y][x] == 'C')
		temp->rupees--;
	if (temp->grid[y][x] == '1')
		return (0);
	if (temp->grid[y][x] == 'E')
	{
		temp->exit_x = 1;
		return (0);
	}
	temp->grid[y][x] = '1';
	if (path(temp, y, x + 1))
		return (1);
	if (path(temp, y, x - 1))
		return (1);
	if (path(temp, y + 1, x))
		return (1);
	if (path(temp, y - 1, x))
		return (1);
	return (0);
}

void	grid_free(char **grid, size_t height)
{
	size_t	i;

	if (grid == NULL)
		return ;
	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	copy_game(t_game *source, t_game *destination)
{
	size_t	i;

	destination->height = source->height;
	destination->width = source->width;
	destination->rupees = source->rupees;
	destination->link_y = source->link_y;
	destination->link_x = source->link_x;
	destination->exit_x = 0;
	destination->grid = (char **)malloc(sizeof(char *) * destination->height);
	if (destination->grid == NULL)
	{
		ft_putstr_fd("rip alloc", 1);
		exit(1);
	}
	i = 0;
	while (i < destination->height)
	{
		destination->grid[i] = ft_strdup(source->grid[i]);
		i++;
	}
}

int	is_valid_path(t_game *game)
{
	t_game	temp;

	copy_game(game, &temp);
	path(&temp, temp.link_y, temp.link_x);
	if (!(temp.exit_x == 1 && temp.rupees == 0))
	{
		ft_putstr_fd("u dont know the way", 1);
		grid_free(temp.grid, temp.height);
		return (-1);
	}
	grid_free(temp.grid, temp.height);
	return (0);
}

int	flood_fill(t_game *game)
{
	return (is_valid_path(game));
}
