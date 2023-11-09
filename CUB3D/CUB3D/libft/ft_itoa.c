/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:46:29 by otelliq           #+#    #+#             */
/*   Updated: 2022/10/21 15:31:52 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	counter(long int c)
{
	int	i;

	i = 0;
	if (c <= 0)
	{
		c *= -1;
		i++;
	}
	while (c > 0)
	{
		i++;
		c /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			len;
	long int	nb;

	nb = n;
	len = counter(nb);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s[len] = '\0';
	if (nb < 0)
	{
		s[0] = '-';
		nb *= -1;
	}
	else if (nb == 0)
		s[0] = '0';
	while (nb > 0)
	{
		s[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (s);
}
/*int main()
{
	printf("%s\n", ft_itoa(-164156168));
}*/
