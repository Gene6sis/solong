/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 00:33:25 by adben-mc          #+#    #+#             */
/*   Updated: 2021/12/23 01:15:18 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, (1L << 17), ft_end, NULL);
	mlx_hook(data->win, 12, (1L << 15), ft_screen, data);
}

static int	check_action(t_data *data, int row, int col)
{
	if (data->map.array[row][col] != WALL)
	{
		if (data->map.array[row][col] == COLLECTABLE)
		{
			data->collectable.count--;
			data->map.array[row][col] = EMPTY;
		}
		if (data->map.array[row][col] == EXIT)
		{
			if (data->collectable.count == 0)
			{
				printf("Moves: %d\nYou won!\n", ++data->move_count);
				ft_end(NULL);
			}
		}
		printf("Moves: %d\n", ++data->move_count);
		return (1);
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == UP)
		if (check_action(data, data->player.row - 1, data->player.col))
			data->player.row -= 1;
	if (keycode == LEFT)
		if (check_action(data, data->player.row, data->player.col - 1))
			data->player.col -= 1;
	if (keycode == DOWN)
		if (check_action(data, data->player.row + 1, data->player.col))
			data->player.row += 1;
	if (keycode == RIGHT)
		if (check_action(data, data->player.row, data->player.col + 1))
			data->player.col += 1;
	mlx_clear_window(data->mlx, data->win);
	ft_screen(data);
	return (0);
}