/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:46:58 by adben-mc          #+#    #+#             */
/*   Updated: 2021/12/22 22:20:14 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_end(char *message)
{
	if (message)
	{
		printf("Error\n%s\n", message);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}
static void	ft_initmlx(t_data	*data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_end("MLX init failed");
	data->move_count = 0;
	data->walls = malloc(sizeof(void *) * 17);
	if (!data->walls)
		ft_end("Wall image allocation failed");
	data->walls[16] = NULL;
	data->map.array = malloc(sizeof(char *));
	if (!data->map.array)
		ft_end("Map allocation failed");
	data->map.array[0] = NULL;
	data->map.rows = 0;
}

static void	ft_initwindow(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->maps.cols * IMG_SIZE, data->map.rows * IMG_SIZE, "so_long");
	if (!data->win)
		ft_end("Window creation failed");
}
//Comprend pas suite pour le moment 

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_end("Please give me only 2 arguments !");
	ft_initmlx(data.mlx);
	ft_readmap(argv[1], &(data.map));
    ft_checkmap(&data);
	ft_sprites(&data);
	ft_initwindow(&data);
	//ft_screen(&data);
	ft_hooks(&data);
	mlx_loop(data.mlx);
	return (-1);
}