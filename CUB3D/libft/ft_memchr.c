/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:42:12 by otelliq           #+#    #+#             */
/*   Updated: 2022/10/13 15:49:28 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*c_s;

	i = 0;
	c_s = (char *)s;
	while (i < n)
	{
		if (c_s[i] == (char)c)
			return (&c_s[i]);
		i++;
	}
	return (0);
}
