/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:04:03 by ckannane          #+#    #+#             */
/*   Updated: 2023/01/22 15:57:33 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result;

	result = NULL;
	while (lst)
	{
		new = ft_lstnew((f)(lst->content));
		if (!new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back (&result, new);
		lst = lst->next;
	}
	return (result);
}
