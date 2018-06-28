/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:14:35 by ahadjer           #+#    #+#             */
/*   Updated: 2017/03/20 09:14:36 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (f && lst)
	{
		list = f(lst);
		list->next = ft_lstmap(lst->next, f);
		return (list);
	}
	return (NULL);
}
