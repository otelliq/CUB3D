/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:41:45 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/18 21:54:52 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_file(char *line)
{
	printf("Error no FILE.CUB detected\n");
	free (line);
	exit(1);
}

void	checker00(t_bjt *m_c)
{
	if (m_c->floor_r > 225 || m_c->floor_r < 0 || 
		m_c->floor_g > 225 || m_c->floor_g < 0 || 
		m_c->floor_b > 225 || m_c->floor_b < 0 || 
		m_c->sky_r > 225 || m_c->sky_r < 0 || 
		m_c->sky_g > 225 || m_c->sky_g < 0 || 
		m_c->sky_b > 225 || m_c->sky_b < 0)
	{
		ft_free_struct(m_c);
		erroc_exit(m_c, "invalid RGB!");
	}
}

int	detect_the_map_array(t_bjt *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->file[i])
	{
		j = 0;
		while (p->file[i][j])
		{
			if (p->file[i][j] != '1' && p->file[i][j] != ' '
				&& p->file[i][j] != '\n')
				return (i);
			j++;
		}
	}
	return (0);
}

int	check_to_fill(t_bjt *m_d, int count_b, int count_a)
{
	int	i;
	int	j;

	i = 6;
	while (m_d->file[i])
	{
		j = 0;
		while (m_d->file[i][j])
		{
			if (m_d->file[i][j] != ' ' && m_d->file[i][j] != '\n' && 
				m_d->file[i][j] != '1' && m_d->file[i][j] != '0')
				return (0);
			else if (m_d->file[i][j] == '\n')
				count_a++;
			else if (m_d->file[i][j] == '1' || m_d->file[i][j] == '0')
				count_b++;
			j++;
		}
		if (count_a >= 0 && count_b > 0)
			return (i);
		i++;
	}
	return (0);
}

int	ft_len(char **mini_map)
{
	int	len;
	int	longest;
	int	i;

	longest = 0;
	i = 0;
	while (mini_map[i])
	{
		if (mini_map[i])
		{
			len = ft_strlen(mini_map[i]);
			if (len > longest)
				longest = len;
		}
		i++;
	}
	return (longest);
}
