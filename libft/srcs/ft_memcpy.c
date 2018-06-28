/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:15:30 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:15:31 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *s;
	char *d;

	s = (char *)src;
	d = (char *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}
