/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:31:29 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/01 16:56:44 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_rupees(t_game *game)
{
	size_t	count;
	size_t	y;
	size_t	x;

	y = 0;
	count = 0;
	if (game == NULL || game->grid == NULL)
	{
		return (count);
	}
	while (y < game->height)
	{
		x = 0;
		while (x < ft_strlen(game->grid[y]) - 1)
		{
			if (game->grid[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
