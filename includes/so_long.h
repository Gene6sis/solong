/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:53:53 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/20 04:17:10 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "get_next_line.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define WIN_X	640
# define WIN_Y	640
# define IMG_SIZE	32

typedef enum e_tiletype {
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'X',
}				t_tiletype;

# ifdef LINUX

typedef enum e_keycode {
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100,
	ESC = 65307,
}				t_keycode;

# else

typedef enum e_keycode {
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	ESC = 53,
}				t_keycode;
# endif

typedef struct s_player
{
	void	*img;
	int		row;
	int		col;
}				t_player;

typedef struct s_collectable {
	void	*img;
	int		count;
}				t_collectable;

typedef struct s_map {
	char	**array;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_data {
	void			*mlx;
	void			*win;
	int				move_count;
	int				exit_count;
	int				player_count;
	int				enemy_count;
	void			*exit;
	void			*floor;
	void			*walls;
	void			*enemy;
	void			*frame_buf;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_map			map;
	t_player		player;
	t_collectable	collectable;
}				t_data;

void			ft_hooks(t_data *data);
int				ft_end(char *message, t_data *data, int error);
int				ft_checkmap(t_data *data);
void			put_pixel_to_frame_buf(t_data *data, int x, int y, int color);
unsigned int	ft_get_pixel(int x, int y, void *img);
int				ft_readmap(char *path, t_map *map, t_data *data);
int				ft_screen(t_data *data);
int				ft_sprites(t_data *data);
void			ft_error(t_data *data, int error);
int				key_hook(int keycode, t_data *data);
void			ft_destroy_image(void *mlx, void *xpm);
void			ft_moves(t_data *data);
void			load_enemy(t_data *data);

#endif