/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:42:19 by adben-mc          #+#    #+#             */
/*   Updated: 2021/12/22 23:03:12 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_floor_wall(t_data *data)
{
	int		width;
	int		height;
	int		i;

	data->floor = mlx_xpm_file_to_image(data->mlx, "./assets/grass_dirt15.xpm", &width, &height);
	if (!data->floor)
		end_game("Failed to load floor sprite.");
	data->walls = mlx_xpm_file_to_image(data->mlx, file_path, &width, &height);
	if (!data->walls)
		end_game("Failed to load wall sprite.");
}

static void	load_player(t_data *data)
{
	int		width;
	int		height;

	data->player.img = mlx_xpm_file_to_image(data->mlx, "./assets/cat001.xpm", &width, &height);
	if (!data->player.img)
		ft_end("Failed to load character sprite.");
}

static void	load_collectable(t_data *data)
{
	int		width;
	int		height;

	data->collectable.img = mlx_xpm_file_to_image(data->mlx, "./assets/fish.xpm", &width, &height);
	if (!data->collectable.img)
		ft_end("Failed to load character sprite.");
}

static void	load_exit(t_data *data)
{
	int		width;
	int		height;

	data->exit = mlx_xpm_file_to_image(data->mlx, "./assets/stairs.xpm", &width, &height);
	if (!data->exit)
		ft_end("Failed to load character sprite.");
}

int	load_sprites(t_data *data)
{
	load_floor_wall(data);
	load_player(data);
	load_collectable(data);
	load_exit(data);
	return (0);
}