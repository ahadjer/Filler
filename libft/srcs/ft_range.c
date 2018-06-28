/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:19:23 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:19:24 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** replace #include libft.h with #include <stdlib.h>
** replace ft_intnew(n - 1) with protected malloc(sizeof(int) * (n));
*/

int		*ft_range(int min, int max)
{
	int		n;
	int		*s;

	n = max >= min ? max - min : min - max;
	if (!(s = ft_intnew(n - 1)))
		return (NULL);
	while (max != min)
		*s++ = max > min ? min++ : min--;
	*s = min;
	return (s - n);
}
