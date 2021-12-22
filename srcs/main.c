/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:46:58 by adben-mc          #+#    #+#             */
/*   Updated: 2021/12/22 19:58:43 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_maps {
	char *str;
	char **map;
}
/*
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 119)
		printf("TOP\n");
	else if (keycode == 97)
		printf("LEFT\n");
	else if (keycode == 100)
		printf("RIGHT\n");
	else if (keycode == 115)
		printf("DOWN\n");
	else if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
		printf("%d\n",keycode);
	return (0);
}
*/

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_maps	map;
	char *path = argv[1];

	if (argc != 2)
		return (printf("Incorrect number of arguments !\n") == 0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
    mlx_pixel_put(vars.mlx, vars.win, 250, 250, 0xFFFFFF);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (-1);
}