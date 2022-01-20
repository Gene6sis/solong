/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:26:40 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/20 01:57:29 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	int			min;
	long int	nb;

	nb = n;
	i = ft_size(nb);
	min = 0;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
		min = 1;
	}
	res[i] = '\0';
	while (--i >= min)
	{
		res[i] = (nb % 10) + 48;
		nb /= 10;
	}
	return (res);
}

/*
#include <stdlib.h>

int main(int ac, char **argv)
{
	(void)ac;
	ft_itoa(atoi(argv[1]));
	return (0);
}
*/