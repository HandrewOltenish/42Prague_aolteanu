/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:17:35 by aolteanu          #+#    #+#             */
/*   Updated: 2024/11/11 15:36:27 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_H
# define MAKE_H
# define GAME_PLAYER 'P'
# define GAME_COLLECTIBLE 'C'
# define GAME_EXIT 'E'
# define GAME_TILE '0'
# define GAME_WALL '1'
# define MAP_PATH "map.ber"
# define Y map->map_coord_height
# define X map->map_coord_width
# define MAX_Y map->map_height
# define MAX_X map->map_width
# include "../Libft_upgradable/libft.h"
# include "../Libft_upgradable/get_next_line_bonus.h"
# include "../Libft_upgradable/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
#endif

// by making these structures I can move the player on the map

typedef struct s_game_textures
{
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*tile;
	mlx_texture_t	*wall;
} t_game_textures;

typedef struct s_game_images
{
	mlx_image_t *player;
	mlx_image_t *collectible;
	mlx_image_t *tile;
	mlx_image_t *wall;
} t_game_images;

typedef struct s_game_map
{
	mlx_t	*mlx;
	char	**map;
	char	**copy;
	int		map_coord_height;
	int		map_coord_width;
	int		map_height;
	int		map_width;
	int		collectible_count;
	int		exit_count;
	int		player_count;
	int		movement_counter;
} t_game_map;