/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:48:09 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/18 22:08:02 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_colors(t_bjt *p)
{
	p->floor_color1 = ft_split(p->floor_color, ',');
	p->sky_color1 = ft_split(p->sky_color, ',');
	if (!p->floor_color1[0] || !p->floor_color1[1] || 
		!p->floor_color1[2] || p->floor_color1[3] || 
		!p->sky_color1[0] || !p->sky_color1[1] || 
		!p->sky_color1[2] || p->sky_color1[3] || 
		(comma(p->floor_color) != 2) || (comma(p->sky_color) != 2))
	{
		ft_free_struct(p);
		erroc_exit(p, "invalid RGB!");
	}
	p->floor_r = ft_atoi(p->floor_color1[0]);
	p->floor_g = ft_atoi(p->floor_color1[1]);
	p->floor_b = ft_atoi(p->floor_color1[2]);
	p->sky_r = ft_atoi(p->sky_color1[0]);
	p->sky_g = ft_atoi(p->sky_color1[1]);
	p->sky_b = ft_atoi(p->sky_color1[2]);
}

void	ft_texture(t_bjt *m_d)
{
	int	i;

	i = 0;
	ft_texture_check(m_d);
	while (m_d->file[i])
	{
		if (tex_checker(m_d->file[i], "NO") == 1)
			m_d->no = ft_split(m_d->file[i], ' ');
		if (tex_checker(m_d->file[i], "WE") == 1)
			m_d->we = ft_split(m_d->file[i], ' ');
		if (tex_checker(m_d->file[i], "SO") == 1)
			m_d->so = ft_split(m_d->file[i], ' ');
		if (tex_checker(m_d->file[i], "EA") == 1)
			m_d->ea = ft_split(m_d->file[i], ' ');
		if (tex_checker(m_d->file[i], "F") == 1) 
			m_d->floor_color = check(m_d->file[i]);
		if (tex_checker(m_d->file[i], "C") == 1)
			m_d->sky_color = check(m_d->file[i]);
		i++;
	}
}

void	fill_with_ones(t_bjt *p, int big_len, char **tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i] != NULL)
	{
		p->mini_map[i] = malloc(sizeof(char) * big_len + 1);
		j = 0;
		while (tmp[i][j] != '\0')
		{
			if (tmp[i][j] == ' ')
				p->mini_map[i][j] = '1';
			else
				p->mini_map[i][j] = tmp[i][j];
			j++;
		}
		while (j < big_len - 1)
			p->mini_map[i][j++] = '1';
		p->mini_map[i][j] = '\0';
		i++;
	}
	p->mini_map[i++] = ft_calloc(big_len, 1);
	p->mini_map[i] = NULL;
}

void	re_fill_size_map(t_bjt *p, int len, int i)
{
	int	j;
	int	big_len;
	int	len_malloc;

	j = 0;
	p->tmp = (char **)malloc(sizeof(char *) * len - i);
	while (p->file[i])
	{
		if (p->file[i])
			p->tmp[j++] = ft_strdup(p->file[i]);
		i++;
	}
	p->tmp[j] = NULL;
	len_malloc = 0;
	while (p->tmp[len_malloc])
		len_malloc++;
	len_malloc++;
	p->mini_map = (char **)malloc(sizeof(char *) * (len_malloc + 1));
	big_len = ft_len(p->tmp) + 1;
	fill_with_ones(p, big_len, p->tmp);
}

void	fill_map(t_bjt *m_d)
{
	int	len;
	int	i;

	len = 0;
	i = check_to_fill(m_d, 0, 0);
	while (m_d->file[len])
		len++;
	if ((check_to_fill(m_d, 0, 0)))
		re_fill_size_map(m_d, len, i);
	else if (!check_to_fill(m_d, 0, 0))
	{
		free_double_array(m_d->file);
		erroc_exit(m_d, "Invalid map!");
	}
}
