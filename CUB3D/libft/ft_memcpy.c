/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:19:25 by otelliq           #+#    #+#             */
/*   Updated: 2022/11/01 20:35:18 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*c_dst;
	char	*c_src;

	i = 0;
	c_dst = (char *)dst;
	c_src = (char *)src;
	if (!c_dst && !c_src)
		return (NULL);
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
/*#include<stdio.h>
int	main(void)
{
	char s[] = "bbbbbbbbbbb";
	char d[] = "ppppppppppp";
	printf("%s", ft_memcpy(d, s, 0));
}*/
