/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:19:44 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/24 13:48:24 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t *image;
// -----------------------------------------------------------------------------

// Function to combine color components into a single pixel value
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// Function to randomize the image pixels
void ft_randomize(void *param __attribute__((unused)))
{
	// Iterate over the image width and height
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			// Set the color of each pixel to red
			uint32_t color = ft_pixel(255, 0, 0, 255); // Red color values
			mlx_put_pixel(image, i, y, color);
		}
	}
}

// Function to handle user input events
void ft_hook(void *param)
{
	mlx_t *mlx = param;

	// Check for key presses using MLX functions
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}
void ft_hook_count(void *param)
{
	mlx_t *mlx = param;
	static int keyPressCount = 0;
	static int isNewMove = 0;
	static int previousKeyPress = -1;

	// Check for key presses using MLX functions
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

	int currentKeyPress = -1;

	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		currentKeyPress = MLX_KEY_UP;
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		currentKeyPress = MLX_KEY_DOWN;
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		currentKeyPress = MLX_KEY_LEFT;
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		currentKeyPress = MLX_KEY_RIGHT;

	if (currentKeyPress != -1 && currentKeyPress != previousKeyPress)
	{
		keyPressCount++;
		isNewMove = 1;
	}

	previousKeyPress = currentKeyPress;

	if (isNewMove)
	{
		printf("Key Press Count: %d\n", keyPressCount);
		isNewMove = 0;
	}
}

char *read_maps(char *map)
{
	int fd;
	char *line;
	char *add_line;

	fd = open(map, O_RDONLY);
	add_line = ft_calloc(1, 1);
	if (add_line == NULL)
		return NULL;
	while ((line = get_next_line(fd)))
	{
		char *temp = ft_strjoin(add_line, line);
		free(add_line);
		add_line = temp;
		free(line);
	}
	close(fd);
	return add_line;
}

/* int32_t main(int32_t argc, const char *argv[])
{
	mlx_t *mlx = NULL;

	(void)argv;
	(void)argc;
	// Initialize the MLX context
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}

	// Create a new image
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}

	// Display the image in the window
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop_hook(mlx, ft_hook_count, mlx);
	mlx_loop(mlx);
	
	// Terminate the MLX context
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
} */



int main(int argc, char **argv)
{
	if (argc == 2)
	{
		check_file_extension(argv[1]);
		t_game *data = init_data(argv[1]);
		if (data == NULL)
			return (0);
		free_data(data);
	}
	else 
		ft_putstr_fd("err", 1);
	return 0;
}