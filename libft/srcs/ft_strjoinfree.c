/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:21:44 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:21:45 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, char control)
{
	char	*mem;

	mem = ft_strjoin(s1, s2);
	if (control == 'L' || control == 'B')
		free(s1);
	if (control == 'R' || control == 'B')
		free(s2);
	return (mem);
}
