/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:44:31 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/08 21:39:53 by adben-mc         ###   ########.fr       */
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
	ft_end("Extension file name failed"); // 3
	return (0);
}

static int	ft_addtomap(t_map *map, char *str)
{
	char	**newmap;
	size_t	i;

	i = 0;
	map->rows += 1;
	newmap = malloc(sizeof(char *) * (map->rows + 1));
	if (!newmap)
		ft_end("Allocation newline to map failed"); //3
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
	free(newmap);
	return (0);
}

static int	ft_checklenline(char *str, int lenght)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strchr(str, '\n'))
		len -= 1;
	return (lenght == len);
}

int	ft_readmap(char *path, t_map *map)
{
	int		fd;
	char	*new_line;

	ft_checkextension(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_end("Open file failed"); //3
	new_line = get_next_line(fd);
	if (!new_line)
	{
		close(fd);
		ft_end("Read file failed"); //3
	}
	map->cols = ft_strlen(new_line) - 1;
	while (new_line)
	{
		if (!ft_checklenline(new_line, map->cols))
		{
			free(new_line);
			close(fd);
			ft_end("Map isn't rectangular"); //3
		}
		ft_addtomap(map, new_line);
		new_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

//A revoir, le close peut creer des leaks si erreurs avant cat exit avant de close