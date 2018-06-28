/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:25:40 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:25:41 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;
	char			*mem;

	i = 0;
	while (ft_isspace(s[i]))
		++i;
	len = ft_strlen(s) - 1;
	while (len > i && ft_isspace(s[len]))
		len--;
	if (len < i)
		return (mem = ft_strdup(""));
	return (mem = ft_strsub(s, i, len - (size_t)i + 1));
}
