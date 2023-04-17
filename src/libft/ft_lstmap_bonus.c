/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:29:38 by tpaufert          #+#    #+#             */
/*   Updated: 2023/03/09 17:28:57 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*i;
	t_list	*next;

	if (!lst)
		return (0);
	i = ft_lstnew(f(lst->content));
	while (lst->next)
	{
		lst = lst->next;
		next = ft_lstnew(f(lst->content));
		if (!next)
		{
			ft_lstclear(&i);
			return (0);
		}
		ft_lstadd_back(&i, next);
	}
	return (i);
}
