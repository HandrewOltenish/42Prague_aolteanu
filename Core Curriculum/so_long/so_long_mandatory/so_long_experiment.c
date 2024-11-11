/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_experiment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:15:51 by aolteanu          #+#    #+#             */
/*   Updated: 2024/11/11 16:08:21 by aolteanu         ###   ########.fr       */
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

int char_check(char c)
{
	if (c == GAME_PLAYER
		|| c == GAME_EXIT
		|| c == GAME_COLLECTIBLE
		|| c == GAME_WALL)
		return (1);
	return (0);
}

char *map_handle_experiment(int strings_count, t_game_map	*map)
{
	map->collectible_count = 0;
	map->player_count = 0;
	map->exit_count = 0;
	while (map->copy[Y])
	{
		while (map->copy[Y][X])
		{
			if (Y == 0 || Y == strings_count)
			{
				if (map->copy[Y][X] != GAME_WALL
					&& map->copy[Y][X] != '\n'
					&& map->copy[Y][X + 1] != '\0')
					return("Invalid map: Outer perimeter invalid.");
			}
			if (!char_check(map->copy[Y][X]))
				return("Invalid map: Illegal character inside map.");
			X++;
		}
		if (strings_count != X)
			return("Invalid map: Different line size");
		Y++;
	}
	return ("Valid Map! Enjoy the game!");
}

void path_handle_experiment(t_game_map	map, int j, int i) 
{
	if (!map.collectible_count && !map.exit_count && !map.player_count)
		puts("Valid map!");
	if (map.map[j][i] == GAME_WALL || map.map[j][i] == 'X')
	{
		return ;
	}
	if (map.map[j][i] == GAME_COLLECTIBLE)
		map.collectible_count--;
	if (map.map[j][i] == GAME_EXIT)
		map.exit_count--;
	if (map.map[j][i] == GAME_PLAYER)
	map.map[j][i] = 'X';
	if (map.map[j][i - 1])
		path_handle_experiment(map, j, i - 1);
	if (map.map[j][i + 1])
		path_handle_experiment(map, j, i + 1);
	if (map.map[j - 1][i])
		path_handle_experiment(map, j - 1, i);
	if (map.map[j + 1][i])
		path_handle_experiment(map, j + 1, i);
}

void	ft_count_size(t_game_map *map, int fd)
{
	Y = 0;
	X = 0;
	map->map[X] = get_next_line(fd);
	while (map->map)
	{
		while (map->map[X][Y])
			X++;
		get_next_line(fd);
		printf("%s\n", map->map[X]);
		Y++;
	}
	MAX_Y = Y;
	MAX_X = X;
	Y = 0;
	X = 0;
}

void copy_map(int fd,char** map, int strings_count)
{
	int j;

	j = 0;
	while (j <= strings_count)
	{
		map[j] = get_next_line(fd);
		printf("%s\n", map[j]);
		j++;
	}
	close(fd);
}

// Split the functions. One function is doing too many things to accurately track in the future!
int main(void)
{
	// mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "Project Escape Schengen", true);
	// mlx_texture_t *player;
	// mlx_image_t	*player_img;
	t_game_map *map;
	int fd;

	map = (t_game_map *)malloc(sizeof(t_game_map));
	if (!map)
		puts("Error: Failed to allocate memory for struct");
	fd = open(MAP_PATH, O_RDONLY);
	if (fd < 0)
		puts("Error: Could not open file. Check if file exists");
	ft_count_size(map, fd);
	close(fd);
	fd = open(MAP_PATH, O_RDONLY);
	if (fd < 0)
		puts("Error: Could not open file. Check if file exists");
	map->copy = (char **)malloc(( + 1) * sizeof(char *));
		if (!map->copy)
		puts("Error: Failed to allocate memory for copy");
	// copy_map(fd, map->copy, strings_count);
	// if (!mlx)
	// 	puts("Error: Could not initialize mlx");
	// player = mlx_load_png("./char.png");
	// if (!player)
	// 	puts("Error: Could not load player texture");
	// player_img = mlx_texture_to_image(mlx, player);
	// if (!player_img)
	// 	puts("Error: Could not create player image");
	// if (mlx_image_to_window(mlx, player_img, WIDTH -200, HEIGHT - 200) < 0)
	// 	puts("Error: Could not draw window");
	// mlx_key_hook(mlx, (mlx_keyfunc)key_movement, player_img);
	// mlx_loop(mlx);
	// printf("%s", map_handle_experiment(strings_count, map));
	// path_handle_experiment(map, 0, 0);
	// mlx_delete_image(mlx, player_img);
	// mlx_terminate(mlx);
	// free(map);
	return (EXIT_SUCCESS);
}
