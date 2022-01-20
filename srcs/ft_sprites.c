/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:42:19 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/20 04:06:56 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_floor_wall(t_data *data)
{
	int		width;
	int		height;

	data->floor = mlx_xpm_file_to_image(data->mlx, "./assets/grass_dirt15.xpm",
			&width, &height);
	if (!data->floor)
		ft_end("Failed to load floor sprite.", data, 3);
	data->walls = mlx_xpm_file_to_image(data->mlx, "./assets/fence_0.xpm",
			&width, &height);
	if (!data->walls)
		ft_end("Failed to load wall sprite.", data, 4);
}

static void	load_player(t_data *data)
{
	int		width;
	int		height;

	data->player.img = mlx_xpm_file_to_image(data->mlx, "./assets/cat001.xpm",
			&width, &height);
	if (!data->player.img)
		ft_end("Failed to load character sprite.", data, 5);
}

static void	load_collectable(t_data *data)
{
	int		width;
	int		height;

	data->collectable.img = mlx_xpm_file_to_image(data->mlx,
			"./assets/fish.xpm", &width, &height);
	if (!data->collectable.img)
		ft_end("Failed to load character sprite.", data, 6);
}

static void	load_exit(t_data *data)
{
	int		width;
	int		height;

	data->exit = mlx_xpm_file_to_image(data->mlx, "./assets/stairs.xpm", &width,
			&height);
	if (!data->exit)
		ft_end("Failed to load character sprite.", data, 7);
}

static void	load_enemy(t_data *data)
{
	int		width;
	int		height;

	data->enemy = mlx_xpm_file_to_image(data->mlx, "./assets/enemy.xpm", &width,
			&height);
	if (!data->enemy)
		ft_end("Failed to load enemy sprite.", data, 8);
}

int	ft_sprites(t_data *data)
{
	load_floor_wall(data);
	load_player(data);
	load_collectable(data);
	load_exit(data);
	if (data->enemy_count != 0)
		load_enemy(data);
	return (0);
}
