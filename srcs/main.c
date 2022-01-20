/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:46:58 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/20 00:20:31 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_end(char *message, t_data *data, int error)
{
	ft_error(data, error);
	if (message)
	{
		printf("Error : %s\n", message);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}

static void	ft_initmlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_end("MLX init failed", data, 0);
	data->move_count = 0;
	data->map.array = malloc(sizeof(char *));
	if (!data->map.array)
		ft_end("Map allocation failed", data, 2);
	data->map.array[0] = NULL;
	data->map.rows = 0;
}

static void	ft_initwindow(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->map.cols * IMG_SIZE,
			data->map.rows * IMG_SIZE, "so_long");
	if (!data->win)
		ft_end("Window creation failed", data, 8);
	data->frame_buf = mlx_new_image(data->mlx, data->map.cols * IMG_SIZE,
			data->map.rows * IMG_SIZE);
	if (!data->frame_buf)
		ft_end("Frame creation failed", data, 9);
	data->addr = mlx_get_data_addr(data->frame_buf, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_end("Please give me only 2 arguments !", &data, 0);
	ft_initmlx(&data);
	ft_readmap(argv[1], &(data.map), &data);
	ft_checkmap(&data);
	ft_sprites(&data);
	ft_initwindow(&data);
	ft_screen(&data);
	ft_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
