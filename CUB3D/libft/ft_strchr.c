/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:31:02 by otelliq           #+#    #+#             */
/*   Updated: 2022/11/01 19:35:55 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//The strchr() function locates the first occurrence of c converted to a char)
// in the string pointed to by s
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i])
			return (0);
		s++;
	}
	return ((char *)s);
}
/*int main()
{
	char s[] = "qwertyuiopasdfghjk";
	printf("%s", ft_strchr(s, 'w'));
}*/
