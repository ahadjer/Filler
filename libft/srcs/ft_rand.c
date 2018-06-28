/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:19:14 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:19:18 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** random function using memory address instead of the usual timestamp
*/

#include "libft.h"

int		ft_rand(int min, int max)
{
	int n;
	int	rng;

	n = (long)malloc(sizeof(long)) >> 1;
	n = (n < 0) ? -n : n;
	rng = 0;
	while (n >= 10)
	{
		rng += (n % 10);
		n /= 10;
	}
	rng = (rng % (max - min + 1)) + min;
	return (rng);
}
