/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 00:33:25 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/18 21:03:20 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_useless(t_data *data)
{
	ft_end(NULL, data, 10);
	return (0);
}

static void ft_moves(int move)
{
	int nb;
	int i;

	i = 0;
	nb = ft_size(move - 1) + 1;
	printf("Size : %d", nb);
	if (move == 1)
		printf("Moves : ");
	if (move > 1)
		while (i < nb)
		{
			write(1, "\b", 1);
			i++;
		}
	printf("%d", move);
	printf("\n");
}

void	ft_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 33, 0, ft_useless, data);
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
				ft_moves(++data->move_count);
				printf("You won!\n");
				ft_end(NULL, data, 10);
			}
		}
		ft_moves(++data->move_count);
		return (1);
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_useless(data);
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
