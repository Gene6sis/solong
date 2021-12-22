/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:53:53 by adben-mc          #+#    #+#             */
/*   Updated: 2021/12/22 23:29:47 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
//# include "get_next_line.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define WIN_X	640
# define WIN_Y	640

typedef enum e_tiletype {
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}				t_tiletype;

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

typedef struct	s_data {
	void			*mlx;
	void			*win;
	void			**walls;
	int				move_count;
	int				exit_count;
	int				player_count;
	int				exit_count;
	void			*exit;
	void			*floor;
	void			*walls;
	t_map			map;
	t_player		player;
	t_collectable	collectable;
}				t_data;


#endif