/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:44:31 by adben-mc          #+#    #+#             */
/*   Updated: 2021/12/22 22:16:17 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_checkextension(char *path)
{
	size_t	lenght;
	char	*ber;

	lenght = ft_strlen(path);
	ber = ft_strnstr(path, ".ber", lenght);
	if (ber)
	{
		if (ber == (path + lenght - 4))
			return (1);
	}
	ft_end("Extension file name failed");
	return (0);
}

static int	ft_addtomap(t_map *map char *str)
{
	char	**newmap;
	size_t	i;

	i = 0;
	map->rows += 1;
	newmap = malloc (sizeof(char *) * (map->rows + 1))
	if (!new_map)
		ft_end("Allocation newline to map failed");
	while (map->array[i])
	{
		newmap[i] = map->array[i];
		i++;
	}
	newmap[i++]= str;
	newmap[i] == NULL;
	i = 0;
	while (map->array[i]) //peut poser probleme ou 
		free(map->array[i++]) // non a voir pas la suite
	free(map->array);
	map->array = new_map;
	return (0);
}

static int ft_checklenline(char *str, int lenght)
{
	int len;
	
	len = ft_strlen(str);
	len -= ft_strchr(str, '\n');
	return (lenght == len)
}

int ft_readmap(char *path, t_map *map)
{
	int fd;
	char	*new_line;
	
	ft_checkextension(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_end("Open file failed");
	new_line = get_next_line(fd);
	if (!new_line)
		ft_end("Read file failed");
	map->cols = ft_strlen(new_line) - 1;
	while (new_line)
	{
		if (!ft_checklenline(new_line, map->cols))
			ft_end("Map isn't rectangular");
		ft_addtomap(map, new_line);
		new_line = get_next_line(fd);
	}
	close(fd);
}

//A revoir, le close peut creer des leaks si erreurs avant cat exit avant de close