/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:16:34 by otelliq           #+#    #+#             */
/*   Updated: 2023/10/11 15:24:11 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(char const	*s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static int	length(char const *s, char c, int *j)
{
	int		i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	while (s1[*j])
	{
		if (s1[*j] != c)
		{
			while (s1[*j] && s1[*j] != c)
			{
				*j = *j + 1;
				i++;
			}
			return (i);
		}
		*j = *j + 1;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	int		j;
	char	**p;

	j = 0;
	i = 0;
	p = malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!p || !s)
		return (NULL);
	while (i < counter(s, c))
	{
		count = length(s, c, &j);
		p[i] = ft_substr(s, j - count, count);
		i++;
	}
	p[i] = 0;
	return (p);
}
/*int main ()
{
	char **tab;
	int i;

	tab = ft_split("dcfedc  fecdc ecdc ecdc edc ", ' ');
	i = 0;
	while (i < 5)
	{
		printf("%s\n" , tab[i]);
		i++;
	}
	return 0;
}*/
