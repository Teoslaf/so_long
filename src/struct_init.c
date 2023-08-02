/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:40:21 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/02 13:40:18 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	row_count(char **grid)
{
	size_t	y;

	y = 0;
	while (grid[y])
		y++;
	return (y);
}

t_game	*init_game_struct(char **grid)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_putstr_fd("memory alloc failed", 1);
	game->width = ft_strlen(grid[0]);
	game->height = row_count(grid);
	game->grid = grid;
	game->steps = 0;
	game->link_x = get_pos_by_char(game, 'x', 'P');
	game->link_y = get_pos_by_char(game, 'y', 'P');
	game->exit_x = get_pos_by_char(game, 'x', 'E');
	game->exit_y = get_pos_by_char(game, 'y', 'E');
	game->rupees = count_rupees(game);
	return (game);
}

t_game	*init_data(char *map)
{
	char	*str_map;
	char	**array_map;
	t_game	*data;

	str_map = read_maps(map);
	if (check_map_stuff(str_map) == -1 || empty_map(str_map) == -1
		|| empty_lines(str_map) == -1)
	{
		free(str_map);
		return (NULL);
	}
	array_map = ft_split(str_map, '\n');
	data = init_game_struct(array_map);
	if (map_shape(array_map) == -1 || horizontal_check(data) == -1
		|| vertical_check(data) == -1 || flood_fill(data) == -1)
	{
		free(str_map);
		free_data(data);
		return (NULL);
	}
	free(str_map);
	return (data);
}

t_img	*init_img(mlx_t *mlx)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_link(mlx, assets);
	assets = rupees(mlx, assets);
	assets = grass(mlx, assets);
	assets = bush(mlx, assets);
	assets = exit_open(mlx, assets);
	assets = exit_closed(mlx, assets);
	return (assets);
}
