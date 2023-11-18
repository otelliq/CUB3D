/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:09:14 by ckannane          #+#    #+#             */
/*   Updated: 2023/11/18 21:19:37 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init(t_bjt *m_d)
{
	m_d->c_norm = 0;
	m_d->f_norm = 0;
	m_d->no_norm = 0;
	m_d->ea_norm = 0;
	m_d->so_norm = 0;
	m_d->we_norm = 0;
}

void	ft_texture_check(t_bjt *m_d)
{
	int	i;

	i = 0;
	init(m_d);
	while (m_d->file[i])
	{
		if (tex_checker(m_d->file[i], "NO ") == 1)
			m_d->no_norm++;
		else if (tex_checker(m_d->file[i], "WE ") == 1)
			m_d->we_norm++;
		else if (tex_checker(m_d->file[i], "SO ") == 1)
			m_d->so_norm++;
		else if (tex_checker(m_d->file[i], "EA ") == 1)
			m_d->ea_norm++;
		else if (tex_checker(m_d->file[i], "F ") == 1)
			m_d->f_norm++;
		else if (tex_checker(m_d->file[i], "C ") == 1)
			m_d->c_norm++;
		i++;
	}
	dup_component_check(m_d);
}

void	dup_component_check(t_bjt *m_d)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (m_d->no_norm > 1 || m_d->so_norm > 1 || m_d->we_norm > 1 || 
			m_d->ea_norm > 1 || m_d->c_norm > 1 || m_d->f_norm > 1)
		{
			free_double_array(m_d->file);
			free_double_array(m_d->tmp);
			free_double_array(m_d->mini_map);
			erroc_exit(m_d, "Duplicate component found!");
		}
		else if (m_d->no_norm == 0 || m_d->so_norm == 0 || m_d->we_norm == 0 || 
			m_d->ea_norm == 0 || m_d->c_norm == 0 || m_d->f_norm == 0)
		{
			free_double_array(m_d->file);
			free_double_array(m_d->tmp);
			free_double_array(m_d->mini_map);
			erroc_exit(m_d, "Missing component!");
		}
		i++;
	}
}

int	tab_check(t_bjt *m_d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m_d->file[i])
	{
		j = 0;
		while (m_d->file[i][j])
		{
			if (m_d->file[i][j] == '\t')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	player_checker(char **av)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 'N')
				count++;
			else if (av[i][j] == 'E')
				count++;
			else if (av[i][j] == 'S')
				count++;
			else if (av[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
