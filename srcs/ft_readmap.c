/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:44:31 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/20 04:58:22 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}

static int	ft_checkextension(char *path, t_data *data)
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
	ft_end("Extension file name failed", data, 3);
	return (0);
}

static int	ft_addtomap(t_map *map, char *str, t_data *data)
{
	char	**newmap;
	size_t	i;

	i = 0;
	map->rows += 1;
	newmap = malloc(sizeof(char *) * (map->rows + 1));
	if (!newmap)
		ft_end("Allocation newline to map failed", data, 3);
	while (map->array[i])
	{
		newmap[i] = map->array[i];
		i++;
	}
	newmap[i++] = str;
	newmap[i] = NULL;
	i = 0;
	free(map->array);
	map->array = newmap;
	return (0);
}

static int	ft_checklenline(char **array, int lenght)
{
	int	len;
	int	i;

	i = 0;
	while (array[i])
	{
		len = ft_strlen(array[i]);
		if (ft_strchr(array[i], '\n'))
			len -= 1;
		i++;
		if (len != lenght)
			return (0);
	}
	return (1);
}

int	ft_readmap(char *path, t_map *map, t_data *data)
{
	int		fd;
	char	*new_line;

	ft_checkextension(path, data);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_end("Open file failed", data, 3);
	new_line = get_next_line(fd);
	if (!new_line)
		ft_end("Read file failed", data, 3);
	map->cols = ft_strlen(new_line) - 1;
	while (new_line)
	{
		ft_addtomap(map, new_line, data);
		new_line = get_next_line(fd);
	}
	close(fd);
	if (!ft_checklenline(data->map.array, map->cols))
	{
		free(new_line);
		ft_end("Map isn't rectangular", data, 3);
	}
	return (0);
}
