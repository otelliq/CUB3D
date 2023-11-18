/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:16:50 by ckannane          #+#    #+#             */
/*   Updated: 2022/10/13 22:22:36 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*str;
	size_t			i;

	i = 0;
	cc = (unsigned char)c;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (str[i] == cc)
			return (&str[i]);
		i++;
	}
	return (0);
}
