/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:43:19 by otelliq           #+#    #+#             */
/*   Updated: 2023/10/12 10:51:35 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    while (str[i] == ' ')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        res = (res * 10) + (str[i] - '0');
        i++;
    }
    while (str[i])
	{
        if (str[i] < '0' || str[i] > '9')
            return -1;
        i++;
    }
    return res * sign;
}
