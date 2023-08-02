/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:48:59 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/01 16:55:23 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	empty_map(char *map)
{
	int	i;

	i = 0;
	if (!map[i])
	{
		ft_putstr_fd("empty map bruv", 1);
		write(1, "\n", 1);
		return (-1);
	}
	return (0);
}

int	empty_lines(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n'))
		{
			ft_putstr_fd("empty lines in map", 1);
			write(1, "\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	check_file_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4))
	{
		printf("give a bratan .ber file.\n");
		exit(1);
	}
}

int	map_shape(char **grid)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(grid[i]);
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != len)
		{
			ft_putstr_fd("not a rectangle", 1);
			write(1, "\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}
