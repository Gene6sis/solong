/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 23:41:25 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/06 12:37:55 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_image_to_frame(t_data *data, void *img, int row, int col)
{
	int	x;
	int	y;
	int	pixel;

	x = 0;
	y = 0;
	while (y < IMG_SIZE)
	{
		x = 0;
		while (x < IMG_SIZE)
		{
			pixel = ft_get_pixel(x, y, img);
			if (!(pixel & (0xFF << 24)))
				put_pixel_to_frame_buf(data, (col * IMG_SIZE) + x, (row * IMG_SIZE) + y, pixel);
			x++;
		}
		y++;
	}
}

static void	*ft_on_img(t_data *data, int row, int col)
{
	if (data->map.array[row][col] == WALL)
		return (data->walls);
	else if (data->map.array[row][col] == COLLECTABLE)
		return (data->collectable.img);
	else if (data->map.array[row][col] == EXIT)
		return (data->exit);
	return (NULL);
}

static void	ft_putimg(t_data *data, int row, int col)
{
	void	*on_img;

	ft_image_to_frame(data, data->floor, row, col);
	on_img = ft_on_img(data, row, col);
	if (on_img)
		ft_image_to_frame(data, on_img, row, col);
}

int	ft_screen(t_data *data)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (row < data->map.rows)
	{
		col = 0;
		while (col < data->map.cols)
		{
			ft_putimg(data, row, col);
			col++;
		}
		row++;
	}
	ft_image_to_frame(data, data->player.img, data->player.row, data->player.col);
	mlx_put_image_to_window(data->mlx, data->win, data->frame_buf, 0, 0);
	return (0);
}
