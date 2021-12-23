/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 00:25:15 by adben-mc          #+#    #+#             */
/*   Updated: 2021/12/23 00:33:46 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_pixel_to_frame_buf(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_get_pixel(int x, int y, void *img)
{
	char	*src;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	src = addr + (y * line_length + x * (bits_per_pixel / 8));
	return (*(unsigned int *)src);
}
