/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:13:12 by ckannane          #+#    #+#             */
/*   Updated: 2023/11/18 21:47:45 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	zero_check(t_bjt *m_d)
{
	int	i;
	int	j;
	int	next_line_len;
	int	prev_line_len;

	i = 1;
	while (m_d->tmp[i + 1])
	{
		next_line_len = ft_strlen(m_d->tmp[i + 1]);
		prev_line_len = ft_strlen(m_d->tmp[i - 1]);
		j = 0;
		while (m_d->tmp[i][j])
		{
			if ((m_d->tmp[i][j] == '0' || m_d->tmp[i][j] == '2')
				&& (j >= next_line_len || j >= prev_line_len))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	one_check(t_bjt *m_d)
{
	int	i;
	int	j;

	j = 0;
	while (m_d->mini_map[0][j])
	{
		if (m_d->mini_map[0][j] != '1' &&
			m_d->mini_map[0][j] != ' ' && m_d->mini_map[0][j] != '\n')
			return (0);
		j++;
	}
	i = check_to_check(m_d);
	j = 0;
	while (m_d->mini_map[i][j])
	{
		if (m_d->mini_map[i][j] != '1' &&
			m_d->mini_map[i][j] != ' ' && m_d->mini_map[i][j] != '\n')
			return (0);
		j++;
	}
	return (1);
}

int	check_to_check(t_bjt *m_d)
{
	int	i;
	int	j;

	i = 0;
	while (m_d->mini_map[i])
		i++;
	i--;
	while (m_d->mini_map[i])
	{
		j = 0;
		while (m_d->mini_map[i][j])
		{
			if (m_d->mini_map[i][j] == '1')
				return (i);
			j++;
		}
		i--;
	}
	return (0);
}
