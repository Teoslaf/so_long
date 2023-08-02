/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:19:44 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/02 12:53:41 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_maps(char *map)
{
	int		fd;
	char	*line;
	char	*add_line;
	char	*temp;

	fd = open(map, O_RDONLY);
	add_line = ft_calloc(1, 1);
	if (add_line == NULL)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin(add_line, line);
		free(add_line);
		add_line = temp;
		free(line);
	}
	close(fd);
	return (add_line);
}

int	main(int argc, char **argv)
{
	t_game	*data;
	t_img	*img;

	if (argc != 2)
		ft_putstr_fd("err \n", 1);
	check_file_extension(argv[1]);
	data = init_data(argv[1]);
	if (data == NULL)
		return (0);
	data->mlx = mlx_init(data->width * 64, data->height * 64, "G", false);
	if (!data->mlx)
		return (EXIT_FAILURE);
	img = init_img(data->mlx);
	data->img = img;
	fill_bg(data);
	map_render(data);
	mlx_key_hook(data->mlx, move_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free_data(data);
	return (EXIT_SUCCESS);
}
