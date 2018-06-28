/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:22:10 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:22:11 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned	i;

	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
