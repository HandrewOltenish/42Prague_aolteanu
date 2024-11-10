/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_experiment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:15:51 by aolteanu          #+#    #+#             */
/*   Updated: 2024/11/10 20:33:32 by aolteanu         ###   ########.fr       */
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

char *map_handle_experiment(int stringscount, t_game_map	*map)
{
	int size;

	size = 0;
	map->collectible_count = 0;
	map->player_count = 0;
	map->exit_count = 0;
	while (map->copy[map->map_height])
	{
		while (map->copy[0] || map->copy[stringscount])
		{
			if (map->copy[map->map_height][map->map_width] != GAME_WALL)
				return("Invalid map: Outer perimeter invalid.");
			map->map_width++;
		}
		while (map->copy[map->map_height][map->map_width])
		{
			if (!char_check(map->copy[map->map_height][map->map_width]))
				return("Invalid map: Illegal character inside map.");
			map->map_width++;
		}
		if (size == 0)
			size = map->map_width;
		else if (size != map->map_width)
			return("Invalid map: Different line size");
		map->map_height++;
	}
	return ("Valid Map! Enjoy the game!");
}

void path_handle_experiment(t_game_map	*map, int j, int i) 
{
	if (!map->collectible_count && !map->exit_count && !map->player_count)
		puts("Valid map!");
	if (map->map[j][i] == '1' || map->map[j][i] == 'X')
	{
		puts("Invalid map.");
		return ;
	// player = mlx_load_png("./char.png");
	}
	if (map->map[j][i] == 'C')
		map->collectible_count--;
	if (map->map[j][i] == 'E')
		map->exit_count--;
	if (map->map[j][i] == 'P')
	map->map[j][i] = 'X';
	if (map->map[j][i - 1])
		path_handle_experiment(map, j, i - 1);
	if (map->map[j][i + 1])
		path_handle_experiment(map, j, i + 1);
	if (map->map[j - 1][i])
		path_handle_experiment(map, j - 1, i);
	if (map->map[j + 1][i])
		path_handle_experiment(map, j + 1, i);
}

int	ft_countstrings(int fd)
{
	int count;
	char	*str;

	count = 0;
	str = "";
	while (fd)
	{
		str = get_next_line(fd);
		if (!str)
			return (count);
		count++;
	}
	return (count);
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
	int strings_count;

	fd = open(MAP_PATH, O_RDONLY);
	if (fd < 0)
		puts("Error: Could not open file. Check if file exists");
	map = (t_game_map *)malloc(sizeof(t_game_map));
	if (!map)
		puts("Error: Failed to allocate memory for struct");
	strings_count = ft_countstrings(fd);
	close(fd);
	fd = open(MAP_PATH, O_RDONLY);
	if (fd < 0)
		puts("Error: Could not open file. Check if file exists");
	map->copy = (char **)malloc((strings_count + 1) * sizeof(char *));
		if (!map->copy)
		puts("Error: Failed to allocate memory for copy");
	copy_map(fd, map->copy, strings_count);
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
	printf("%s", map_handle_experiment(strings_count, map));
	// path_handle_experiment(map, 0, 0);
	// mlx_delete_image(mlx, player_img);
	// mlx_terminate(mlx);
	// free(map);
	return (EXIT_SUCCESS);
}
