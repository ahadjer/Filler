/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:22:57 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:22:58 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dst);
	while (*src && n--)
		dst[i++ + len] = *src++;
	dst[i + len] = '\0';
	return (dst);
}
