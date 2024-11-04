/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_experiment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:15:51 by aolteanu          #+#    #+#             */
/*   Updated: 2024/11/04 19:34:30 by aolteanu         ###   ########.fr       */
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

// void swap_entities(mlx_image_t *current_pos, mlx_image_t *next_pos)
// {
// 	/*pseudocode
// 	if next position is wall, don't go to next position
// 	else if it's enemy, die
// 	else go to next position*/
// }

void detect_collision(mlx_key_data_t keydata, mlx_image_t *img)
{
	// current coordinates vs source coordinates. This applies not only to player img, but to everything
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		if (img->instances[0].y - img->height >= 0)
			img->instances[0].y -= img->height;
		else puts ("Ouch!");
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		if (img->instances[0].y + img->height <= HEIGHT - 200)
			img->instances[0].y += img->height;
		else puts ("Ouch!");
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		if (img->instances[0].x - img->width >= 0)
			img->instances[0].x -= img->width;
		else puts ("Ouch!");
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		if (img->instances[0].x + img->width <= WIDTH - 200)
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

int map_handle_experiment(int fd)
{
	char	*counter;
	char	*pe;
	char	*temp;
	int		count_strings;

	count_strings = 0;
	counter = (char	*)malloc(3 * sizeof(char));
	if (counter == 0)
		printf("Error: Failed to allocate memory to counter");
	// fd = open("map.ber", O_RDONLY);
	// 	if (fd < 0)
	// 		printf("Error. File cannot be opened.");
	pe = get_next_line(fd);
		if (pe == 0)
			printf("Error: File is empty");
	count_strings++;
	temp = pe;
	while (pe)
	{
		temp = pe;
		if ((ft_strrchr(counter, 'P') && ft_strrchr(pe, 'P'))
				|| (ft_strchr(counter, 'E') && (ft_strrchr(pe, 'P'))))
					printf("Erorr: Multiple P or E in map");
		if (ft_strrchr(pe, 'P'))
			ft_strlcat(counter, "P", 1);
		else if (ft_strrchr(pe, 'E'))
			ft_strlcat(counter, "E", 1);
		if (ft_strncmp(pe, temp, ft_strlen(pe)))
			printf("Error: Strings have different sizes");
		pe = get_next_line(fd);
		count_strings++;
	}
	printf("%s", "Valid Map");
	close(fd);
	return(count_strings);
}

// Logic is OK consider collectible counter and exit counter
void path_handle_experiment(char	**map, char position, int i, int j) 
{
	if (position != '1' || position != 'E')
	{
		position = 'X';
		path_handle_experiment(map, map[i][j - 1], i, j - 1);
		path_handle_experiment(map, map[i][j + 1], i, j + 1);
		path_handle_experiment(map, map[i - 1][j], i - 1, j);
		path_handle_experiment(map, map[i - 1][j - 1], i - 1, j - 1);
	}
	else if (position == 'E')
		ft_printf("Valid Path!");
	else ft_printf("Invalid Path!");
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
	int fd;
	int i;
	char	**map_copy;
	
	i = 0;
	fd = open("map.ber", O_WRONLY);
	if (fd < 0)
		printf("Error: No file present!\n");
	else
	{
		map_copy = (char **)malloc(sizeof(char *) * (map_handle_experiment(fd) + 1));
		while (fd)
		{
			map_copy[i] = get_next_line(fd);
			i++;
		}
		path_handle_experiment(map_copy, map_copy[0][0], 0, 0);
		close(fd);
	}
	if (!mlx)
		printf("Error");
	player = mlx_load_png("./char.png");
	if (!player)
		printf("Error");
	player_img = mlx_texture_to_image(mlx, player);
	if (!player_img)
		printf("Error");
	if (mlx_image_to_window(mlx, player_img, WIDTH -200, HEIGHT - 200) < 0)
		printf("Error");
	mlx_key_hook(mlx, (mlx_keyfunc)key_movement, player_img);
	mlx_loop(mlx);
	mlx_delete_image(mlx, player_img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
