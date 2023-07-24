/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:33:04 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/14 19:10:59 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_data(t_game *data)
{
	size_t i = 0;
	while (i < data->height)
	{
		free(data->grid[i]);
		i++;
	}

	free(data->grid);

	free(data);
}
