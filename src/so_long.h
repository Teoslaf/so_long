/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:17:38 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/24 13:50:48 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <MLX42/MLX42.h>
#include "../libft/libft.h"
#define WIDTH 512
#define HEIGHT 512

typedef struct s_game
{
	char **grid;
	size_t width;
	size_t height;
	size_t rupees;
	size_t steps;
	size_t collected;
	size_t link_x;
	size_t link_y;
	size_t exit_x;
	size_t exit_y;
	//	mlx_texture_t	*link_up;
	//	mlx_texture_t	*link_down;
	//	mlx_texture_t	*link_left;
	//	mlx_texture_t	*link_right;
	//	t_img			*img;
	//	mlx_t			*mlx;
} t_game;

typedef struct s_img
{
	/* 	mlx_image_t			*bush;
		mlx_image_t			*grass;
		mlx_image_t			*rupee; */
	mlx_image_t *link;
	/* 	mlx_image_t			*exit_closed;
		mlx_image_t			*exit_open;
		mlx_image_t			*enemy;
		mlx_image_t			*moves_print;
		mlx_image_t			*moves_nbr;
		mlx_image_t			*rupee_nbr;
		mlx_image_t			*rupee_2; */
} t_img;
void invalid_map(int i);
size_t count_rupees(t_game *game);
void check_map_stuff(char *map);
void map_shape(char **grid);
char *read_maps(char *map);
t_game *init_game_struct(char **grid);
t_game *init_data(char *map);
void walls(t_game *game);
int empty_map(char *map);
void free_data(t_game *data);
void empty_lines(char *map);
void check_file_extension(char *file);
#endif