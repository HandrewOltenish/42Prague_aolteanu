/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_experiment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:15:51 by aolteanu          #+#    #+#             */
/*   Updated: 2024/07/16 20:40:11 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/make.h"
#define WIDTH 800
#define HEIGHT 600
#define BPP sizeof (int32_t)

// use structures example

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

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


void map_handle_experiment(char	*file)
{
	int		fd;
	char	*counter;
	char	*pe;
	counter = (char	*)malloc(3 * sizeof(char));
	fd = open(file, O_RDONLY);
		if (fd < 0)
			error();
	pe = get_next_line(fd);
		if (pe == 0)
			error();
	while (pe)
	{
		if ((ft_strrchr(counter, 'P') && ft_strrchr(pe, 'P'))
				|| (ft_strchr(counter, 'E') && (ft_strrchr(pe, 'P'))))
					error() ;
		if (ft_strrchr(pe, 'P'))
			ft_strlcat(counter, "P", 1);
		else if (ft_strrchr(pe, 'E'))
			ft_strlcat(counter, "E", 1);
		if (ft_strlen(get_next_line(fd)) != ft_strlen(pe))
			error();
		pe = get_next_line(fd);
	}
	printf("%s", "Valid Map\n");
	fd = close(file);
}

void path_handle_experiment(char	*file) // use recursive function
{
	int fd;
	int i;
	int j;
	char	**map_line;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	map_line = get_next_line(fd);
	while (fd)
	{
		while (ft_strchr(map_line[i][j], 'P'));
		{
			int new x;
			int new y;
			if(map_line[i][j--] == 0)
				map_line[i][j] = X;
			if (map_line[i][j + 2] == 0)
				map_line[i][j] = X;
			if (map_line[i - 1][j -1] == 0)
				map_line[i][j] = X;
			if (map_line[i + 2][ j + 1])
				map_line[i][j] = X;
			j++;
		}
		i++;
	}
}

int main(void)
{
	mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "Project Escape Schengen", true);
	mlx_texture_t *player;
	mlx_image_t	*player_img;

	map_handle_experiment("map.ber");
	if (!mlx)
		error();
	player = mlx_load_png("./char.png");
	if (!player)
		error();
	player_img = mlx_texture_to_image(mlx, player);
	if (!player_img)
		error();
	if (mlx_image_to_window(mlx, player_img, WIDTH -200, HEIGHT - 200) < 0)
		error();
	mlx_key_hook(mlx, (mlx_keyfunc)key_movement, player_img);
	mlx_loop(mlx);
	mlx_delete_image(mlx, player_img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
