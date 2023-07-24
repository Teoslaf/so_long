/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:40:21 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/24 13:57:00 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t row_count(char **grid)
{
	size_t y;

	y = 0;
	while (grid[y])
		y++;
	return (y);
}

t_game *init_game_struct(char **grid)
{
	t_game *game;
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_putstr_fd("memory alloc failed", 1);
	game->width = ft_strlen(grid[0]);
	game->height = row_count(grid);
	game->grid = grid;
	game->rupees = count_rupees(game);
	return (game);
}

t_game *init_data(char *map)
{
	char *str_map;
	char **array_map;
	t_game *data;

	str_map = read_maps(map);
	check_map_stuff(str_map);
	if (empty_map(str_map) == -1)
	{
		free(str_map);
		return (NULL);
	}
	empty_lines(str_map);
	array_map = ft_split(str_map, '\n');
	data = init_game_struct(array_map);
	map_shape(array_map);
	walls(data);
	free(str_map);
	return (data);
}
/* t_img *init_img(mlx_t *mlx)
{
	t_img *assets;
	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_link_texture(mlx, assets);
	return (assets);
} */