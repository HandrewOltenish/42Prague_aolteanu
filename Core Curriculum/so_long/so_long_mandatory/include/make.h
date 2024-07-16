/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:17:35 by aolteanu          #+#    #+#             */
/*   Updated: 2024/06/19 17:40:32 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_H
# define MAKE_H
# define GAME_PLAYER 'P'
# define GAME_COLLECTIBLE 'C'
# define GAME_TILE '0'
# define GAME_WALL '1'
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
	int		map_height;
	int		map_width;
	int		collectible_count;
	int		number_of_collectibles;
	int		movement_counter;
	char	**next_map;
} t_game_map;