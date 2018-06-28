/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:26:56 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:26:57 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(wchar_t const *s1)
{
	wchar_t	*s2;
	size_t	len;

	len = ft_wstrlen((unsigned *)s1) * sizeof(wchar_t);
	if (!s1 || !(s2 = (wchar_t *)ft_memalloc((sizeof(wchar_t) + len))))
		return (NULL);
	ft_memcpy(s2, s1, len);
	return (s2);
}
