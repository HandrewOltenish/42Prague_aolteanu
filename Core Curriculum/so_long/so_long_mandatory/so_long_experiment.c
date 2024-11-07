/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_experiment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:15:51 by aolteanu          #+#    #+#             */
/*   Updated: 2024/11/07 19:51:27 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/make.h"
#define WIDTH 800
#define HEIGHT 600
#define BPP sizeof (int32_t)

// static void error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

uint8_t get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void detect_collision(mlx_key_data_t keydata, mlx_image_t *img)
{
	// current coordinates vs source coordinates. This applies not only to player img, but to everything
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		if (img->instances[0].y - img->height / 2 >= 0)
			img->instances[0].y -= img->height;
		else puts ("Ouch!");
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		if (img->instances[0].y <= HEIGHT)
			img->instances[0].y += img->height;
		else puts ("Ouch!");
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		if (img->instances[0].x - img->width / 2 >= 0)
			img->instances[0].x -= img->width;
		else puts ("Ouch!");
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		if (img->instances[0].x <= WIDTH - img->instances[0].x / 2)
			img->instances[0].x += img->width;
		else puts ("Ouch!");
	}
}

void	key_movement(mlx_key_data_t keydata, void	*param)
{
	mlx_image_t	*img;
	img = param;
	printf("Key pressed: %u\nX: %i\n\nY: %i\n----------\n", keydata.key, img->instances[0].x, img->instances[0].y);
	detect_collision(keydata, img);
}

void path_handle_experiment(t_game_map	*map, int j, int i) 
{
	if (!map->collectible_count && !map->exit_count && !map->player_count)
		puts("Valid map!");
	if (map->map[j][i] == '1' || map->map[j][i] == 'X')
	{
		puts("Invalid map.");
		return ;
	}
	if (map->map[j][i] == 'C')
		map->collectible_count--;
	if (map->map[j][i] == 'E')
		map->exit_count--;
	if (map->map[j][i] == 'P')
	map->map[j][i] == 'X';
	path_handle_experiment(map, j, i - 1);
	path_handle_experiment(map, j, i + 1);
	path_handle_experiment(map, j - 1, i);
	path_handle_experiment(map, j + 1, i);
	
}

int	ft_countstrings(int fd)
{
	int count;

	count = 0;
	while (fd)
	{
		get_next_line(fd);
		count++;
	}
	return (count);
}

// Split the functions. One function is doing too many things to accurately track in the future!
int main(void)
{
	mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "Project Escape Schengen", true);
	mlx_texture_t *player;
	mlx_image_t	*player_img;

	if (!mlx)
		printf("Error: Could not initialize mlx");
	player = mlx_load_png("./char.png");
	if (!player)
		printf("Error: Could not load player texture");
	player_img = mlx_texture_to_image(mlx, player);
	if (!player_img)
		printf("Error: Could not create player image");
	if (mlx_image_to_window(mlx, player_img, WIDTH -200, HEIGHT - 200) < 0)
		printf("Error: Could not draw window");
	mlx_key_hook(mlx, (mlx_keyfunc)key_movement, player_img);
	mlx_loop(mlx);
	mlx_delete_image(mlx, player_img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
