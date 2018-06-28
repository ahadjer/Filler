/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:24:01 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:24:02 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoinfree(const char *s1, const char *s2, size_t len, char c)
{
	char	*s;

	s = ft_strnjoin(s1, s2, len);
	if (c == 'L' || c == 'B')
		free((char *)s1);
	if (c == 'R' || c == 'B')
		free((char *)s2);
	return (s);
}
