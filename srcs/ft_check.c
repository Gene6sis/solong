/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:46:41 by adben-mc          #+#    #+#             */
/*   Updated: 2021/12/23 01:01:17 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void ft_value_check(t_data *data, int row, int col)
{
	if (data->map.array[row][col] == PLAYER)
	{
		data->player.row = row;
		data->player.col = col;
		(data->player_count)++;
	}
	if (data->map.array[row][col] == COLLECTABLE)
		data->collectable.count++;
	if (data->map.array[row][col] == EXIT)
		(data->exit_count)++;
	if (!ft_strchr("01CPE", data->map.array[row][col]))
		ft_end("Invalid character in map.");
	if (row == 0 || row == data->map.rows - 1 || col == 0 || col == data->map.cols - 1)
		if (data->map.array[row][col] != WALL)
			ft_end("Map not surrounded by walls.");
}

int ft_checkmap(t_data *data)
{
	int row;
	int col;

	row = 0;
	data->exit_count = 0;
	data->player_count = 0;
	data->collectable.count = 0;
	while (row < data->map.rows)
	{
		col = 0;
		while (col < data->map.cols)
		{
			ft_value_check(data, row, col);
			col++;
		}
		row++;
	}
	if (data->exit_count < 1 || data->player_count != 1 || data->collectable.count < 1)
		ft_end("Invalid chars in map");
	return (0);
}