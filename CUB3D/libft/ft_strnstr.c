/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:57:44 by otelliq           #+#    #+#             */
/*   Updated: 2022/10/17 10:52:52 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hs;

	i = 0;
	j = 0;
	if (!needle[0])
		return (&(hs = (char *)haystack)[i]);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (i + j >= len)
				return (0);
			if (needle[j] == haystack[i + j] && needle[j + 1] == '\0')
				return (&(hs = (char *)haystack)[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*int main()
{
	char *a = "qwertyuiopasdfghjklzxcvbnm";
	char *b = "q";
	printf("%s", ft_strnstr(a, b, 26));
}*/
