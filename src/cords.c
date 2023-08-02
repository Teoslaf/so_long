/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cords.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:49:36 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/01 16:47:30 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	get_pos_by_char(t_game *game, char c, char search_char)
{
	size_t	y;
	size_t	x;

	y = 0;
	if (game == NULL || game->grid == NULL)
		return (0);
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == search_char)
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
