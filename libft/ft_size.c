/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:43:59 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/18 21:01:06 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int nbr)
{
	int	i;
    int nb;

	i = 0;
    nb = nbr;
	if (nb <= 0)
	{
		nb = -nb;
		i += 1;
	}
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}