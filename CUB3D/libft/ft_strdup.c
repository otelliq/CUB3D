/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:27:27 by otelliq           #+#    #+#             */
/*   Updated: 2022/11/01 20:22:21 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*The strdup() function allocates sufficient memory for a copy of the string s1,
does the copy, and returns a pointer to it.*/

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!s1 || !str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
