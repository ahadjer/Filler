/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:19:45 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:19:46 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_str2lower(char *s)
{
	unsigned i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
	return (s);
}
