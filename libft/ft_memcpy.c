/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:24:20 by ckannane          #+#    #+#             */
/*   Updated: 2022/10/13 22:22:31 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (0);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dst);
}
