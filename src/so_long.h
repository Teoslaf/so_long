/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:17:38 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/02 13:43:02 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# define WIDTH 512
# define HEIGHT 512

typedef struct s_img
{
	mlx_image_t	*bush;
	mlx_image_t	*grass;
	mlx_image_t	*rupee;
	mlx_image_t	*link;
	mlx_image_t	*exit_closed;
	mlx_image_t	*exit_open;
}				t_img;

typedef struct s_game
{
	char		**grid;
	size_t		width;
	size_t		height;
	size_t		rupees;
	size_t		steps;
	size_t		collected;
	size_t		link_x;
	size_t		link_y;
	size_t		exit_x;
	size_t		exit_y;
	t_img		*img;
	mlx_t		*mlx;
}				t_game;

int				invalid_map(int i);
int				check_map_stuff(char *map);
int				map_shape(char **grid);
size_t			count_rupees(t_game *game);
char			*read_maps(char *map);
t_game			*init_game_struct(char **grid);
t_game			*init_data(char *map);
void			walls(t_game *game);
int				empty_map(char *map);
void			free_data(t_game *data);
int				empty_lines(char *map);
void			check_file_extension(char *file);
int				path(t_game *temp, size_t y, size_t x);
size_t			get_pos_by_char(t_game *game, char c, char search_char);
int				flood_fill(t_game *game);
void			map_render(t_game *data);
void			fill_bg(t_game *data);
void			img_select(t_game *data, size_t y, size_t x);
t_img			*init_img(mlx_t *mlx);
t_img			*load_link(mlx_t *mlx, t_img *img);
t_img			*rupees(mlx_t *mlx, t_img *img);
t_img			*grass(mlx_t *mlx, t_img *img);
t_img			*bush(mlx_t *mlx, t_img *img);
t_img			*exit_open(mlx_t *mlx, t_img *img);
t_img			*exit_closed(mlx_t *mlx, t_img *img);
void			move_hook(mlx_key_data_t key, void *data);
void			move_player(t_game *game, char line, char direction);
void			delete_rupees(t_game *game, int y, int x);
t_game			*move_up(t_game *game);
t_game			*move_down(t_game *game);
t_game			*move_right(t_game *game);
t_game			*move_left(t_game *game);
void			print_moves(t_game *game);
void			check_game(t_game *game);
int				horizontal_check(t_game *game);
int				vertical_check(t_game *game);

#endif