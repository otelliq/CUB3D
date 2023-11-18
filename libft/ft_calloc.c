/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:17:56 by ckannane          #+#    #+#             */
/*   Updated: 2022/10/08 15:18:00 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	s;
	char	*ptr;

	s = count * size;
	ptr = malloc(s);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, s);
	return (ptr);
}
