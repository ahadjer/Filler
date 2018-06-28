/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:15:04 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:15:05 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*s;
	char			*d;
	unsigned int	i;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	while (n--)
	{
		d[i] = s[i];
		if (s[i++] == (char)c)
			return ((char *)dest + i);
	}
	return (NULL);
}
