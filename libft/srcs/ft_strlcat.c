/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:22:00 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:22:01 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	i;
	size_t	n;
	size_t	m;

	n = ft_strlen(dest);
	m = ft_strlen(src);
	if (!size)
		return (n);
	i = 0;
	while (*src && (i + n < size - 1))
		dest[i++ + n] = *src++;
	dest[i + n] = '\0';
	return (m += n < size ? n : size);
}
