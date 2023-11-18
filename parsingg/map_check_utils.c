/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:53:03 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/18 21:47:16 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*check(char *str)
{
	int		i;
	int		j; 
	char	*res;

	j = 0;
	i = 0;
	res = malloc(ft_strlen(str));
	while (str[i])
	{
		if (str[i] == 'F' || str[i] == 'C')
			i++;
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

int	cub_checker(char *haystack, char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	tex_checker(char *haystack, char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	comma(char *s)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (s[i])
	{
		if (s[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}
