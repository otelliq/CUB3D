/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:21:24 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/18 22:08:49 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	border_check(char **m_d)
{
	int	i;
	int	j;

	i = 0;
	while (m_d[i])
	{
		j = 0;
		while (m_d[i][j] && m_d[i][j] == ' ')
			j++;
		if (m_d[i][j] != '1' && m_d[i][j])
			return (0);
		j = ft_strlen(m_d[i]) - 1;
		while (j >= 0 && m_d[i][j] == ' ')
			j--;
		if (j >= 0 && m_d[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	borders_checker(t_bjt *m_d)
{
	int	i;
	int	j;

	i = 0;
	while (m_d->tmp[i])
	{
		j = 0;
		while (m_d->tmp[i][j])
		{
			if (j - 1 >= 0 && i - 1 >= 0 && j + 1 <= (int)ft_strlen(m_d->tmp[i])
				&& j - 1 <= (int)ft_strlen(m_d->tmp[i]))
			{
				if ((m_d->tmp[i][j] == '0' && m_d->tmp[i][j + 1] == ' ') ||
					(m_d->tmp[i][j] == '0' && m_d->tmp[i][j - 1] == ' ') ||
					(m_d->tmp[i][j] == '0' && m_d->tmp[i + 1][j] == ' ') ||
					(m_d->tmp[i][j] == '0' && m_d->tmp[i - 1][j] == ' '))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	error_texture(t_bjt *p)
{
	ft_free_struct(p);
	mlx_terminate(p->mlx);
	if (p->north)
		mlx_delete_texture(p->north);
	if (p->west)
		mlx_delete_texture(p->west);
	if (p->east)
		mlx_delete_texture(p->east);
	if (p->south)
		mlx_delete_texture(p->south);
	erroc_exit(p, "TEXTURE path not found");
}

int	check_double_path(t_bjt *m_d, char *name)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (m_d->file[i])
	{
		if (tex_checker(m_d->file[i], name) == 1)
			count++;
		i++;
	}
	return (count);
}

int	component_check(t_bjt *m_d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m_d->mini_map[i])
	{
		j = 0;
		while (m_d->mini_map[i][j])
		{
			if (m_d->mini_map[i][j] != '1' && m_d->mini_map[i][j] != '0' &&
				m_d->mini_map[i][j] != 'N' && m_d->mini_map[i][j] != 'W' &&
				m_d->mini_map[i][j] != 'S' && m_d->mini_map[i][j] != 'E' &&
				m_d->mini_map[i][j] != '\n' && m_d->mini_map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
