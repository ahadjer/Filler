/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:24:35 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:24:36 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	t;

	i = -1;
	j = ft_strlen(s);
	while (++i < --j)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
	return (s);
}
