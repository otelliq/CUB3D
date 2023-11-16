/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:58:19 by otelliq           #+#    #+#             */
/*   Updated: 2022/11/02 02:09:42 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c_s;
	size_t	i;
	size_t	u;

	if (!s)
		return (NULL);
	i = 0;
	u = len;
	if (len > ft_strlen(s))
		u = ft_strlen(s);
	c_s = ft_calloc((u + 1), sizeof(char));
	if (!c_s)
		return (0);
	if (start <= ft_strlen(s))
	{
		while (i < len && start <= ft_strlen(s))
			c_s[i++] = s[start++];
	}
	return (c_s);
}
/*int	main(void)
{
	char	*s;
	s = "qwertyuiopasdfghjklzxcvbnm";
	printf("%s", ft_substr(s, 5, 8));
}*/
