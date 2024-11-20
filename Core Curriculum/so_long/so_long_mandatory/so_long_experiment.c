/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_experiment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:15:51 by aolteanu          #+#    #+#             */
/*   Updated: 2024/11/20 21:48:15 by aolteanu         ###   ########.fr       */
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

int char_check(t_game_map *map, char c)
{
	if (c == GAME_PLAYER
		|| c == GAME_EXIT
		|| c == GAME_COLLECTIBLE
		|| c == GAME_WALL)
	{
		if (c == GAME_PLAYER)
			map->player_count++;
		if (c == GAME_EXIT)
			map->exit_count++;
		if (c == GAME_COLLECTIBLE)
			map->collectible_count++;
		return (1);
	}
	return (0);
}

int map_handle_experiment(int strings_count, t_game_map	*map)
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
					{
						puts("Invalid map: Outer perimeter invalid.");
						return (0);
					}
			}
			if (!char_check(map, map->copy[Y][X]))
			{
				puts("Invalid map: Illegal character inside map.");
				return (0);
			}
			X++;
		}
		if (strings_count != X)
		{
			puts("Invalid map: Different line size");
			return(0);
		}
		Y++;
	}
	puts("Valid Map! Enjoy the game!");
	return (1);
}

// COMPLETE OK proceed with map_handle_experiment
// int path_handle_experiment(t_game_map *map, int y, int x)
// {
// 	printf("Y: %i X: %i char: %c\n", y, x, map->copy[y][x]);
// 	if (y >= MAX_Y || x >= MAX_X || y < 0 || x < 0 || map->copy[y][x] == 'X')
// 	{
// 		return (0);
// 	}
// 	if (map->copy[y][x] == GAME_COLLECTIBLE)
// 		map->collectible_count--;
// 	if (map->copy[y][x] == GAME_EXIT)
// 		map->exit_count--;
// 	if (map->copy[y][x] == GAME_PLAYER)
// 		map->player_count--;
// 	if (map->copy[y][x] == GAME_TILE)
// 		map->copy[y][x]= 'X';
// 	if (map->copy[y][x - 1] != GAME_WALL)
// 		path_handle_experiment(map, y, x - 1);
// 	if (map->copy[y][x + 1] != GAME_WALL)
// 		path_handle_experiment(map, y, x + 1);
// 	if (map->copy[y - 1][x] != GAME_WALL)
// 		path_handle_experiment(map, y - 1, x);
// 	if (map->copy[y + 1][x] != GAME_WALL)
// 		path_handle_experiment(map, y + 1, x);
// 	if (!map->collectible_count && !map->exit_count && !map->player_count)
// 	{
// 		puts("Valid map!");
// 		return(1);
// 	}
// 	return (0);
// }

void ft_count_size(int fd, t_game_map *map)
{
	char	*str;
	int	i;

	i = 0;
	fd = open(MAP_PATH, O_RDONLY);
	MAX_Y = 0;
	MAX_X = 0;
	str = get_next_line(fd);
	MAX_Y++;
	if (!str)
		return ;
	while (str[i])
		i++;
	MAX_X = i;
	while (get_next_line(fd))
		MAX_Y++;
	close(fd);
}

int ft_allocate_map_memory(t_game_map *map)
{
	Y = 0;
	map->map = (char **)malloc(sizeof(char *) * MAX_Y);
	map->copy = (char **)malloc(sizeof(char *) * MAX_Y);
	if (!map->map && !map->copy)
		return 0;
	while (Y <= MAX_X)
	{
		map->map[Y] = (char *)malloc(sizeof(char ) * MAX_X);
		map->copy[Y] = (char *)malloc(sizeof(char ) * MAX_X);
		if (!map->map[Y] && map->copy[Y])
			return 0;
		Y++;
	}
	Y = 0;
	return (1);
}

void copy_map(int fd, char ** map, int strings_count)
{
	int j;
	j = 0;
	fd = open(MAP_PATH, O_RDONLY);
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

	fd = 0;
	map = (t_game_map *)malloc(sizeof(t_game_map));
	if (!map)
		puts("Error: Failed to allocate memory for struct");
	ft_count_size(fd, map);
	if (!ft_allocate_map_memory(map))
	{
		puts("Error: Failed to allocate memory for map");
		return (1);
	}
	copy_map(fd,map->map, MAX_Y);
	map->copy = map->map;
	path_handle_experiment(map, 1, 1);
	free(map);
	map_handle_experiment(MAX_Y, map);
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
	// mlx_delete_image(mlx, player_img);
	// mlx_terminate(mlx);
	// free(map);
	return (EXIT_SUCCESS);
}
