/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:18:15 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/11 19:53:38 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_close(t_data *data, int error)
{
	if (error >= 4)
		ft_destroy_image(data->mlx, data->floor);
	//if (error >= 5)
	//	ft_destroy_image(data->mlx, data->walls);
	if (error >= 6)
		ft_destroy_image(data->mlx, data->player.img);
	if (error >= 7)
		ft_destroy_image(data->mlx, data->collectable.img);
	if (error >= 8)
		ft_destroy_image(data->mlx, data->exit);
	if (data->win != NULL && error >= 9)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL && error >= 1)
		mlx_destroy_display(data->mlx);
}

void	ft_error(t_data *data, int error)
{
	int i;

	i = 0;
	ft_close(data, error);
	if (error >= 1)
		free(data->mlx);
	if (error >= 2 && error < 5)
		free(data->walls);
	if (error >= 3)
	{
		while (data->map.array[i])
			free(data->map.array[i++]);
		free(data->map.array);
	}
}
