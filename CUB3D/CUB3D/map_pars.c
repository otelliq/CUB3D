/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:48:09 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/01 10:58:14 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

void	ft_colors(t_map_data *m_d, t_map_colors *m_c)
{
	m_d->Floor_color1 = ft_split(m_d->Floor_color, ',');
	m_d->sky_color1 = ft_split(m_d->sky_color, ',');
	if(!m_d->Floor_color1[0] || !m_d->Floor_color1[1] ||
	!m_d->Floor_color1[2] || m_d->Floor_color1[3] ||
	!m_d->sky_color1[0] || !m_d->sky_color1[1] ||
	!m_d->sky_color1[2] || m_d->sky_color1[3])
		error_printf("Error, invalid RGB!");
	m_c->floor_R = ft_atoi(m_d->Floor_color1[0]);
	m_c->floor_G = ft_atoi(m_d->Floor_color1[1]);
	m_c->floor_B = ft_atoi(m_d->Floor_color1[2]);
	m_c->sky_R = ft_atoi(m_d->sky_color1[0]);
	m_c->sky_G = ft_atoi(m_d->sky_color1[1]);
	m_c->sky_B = ft_atoi(m_d->sky_color1[2]);
}
void	ft_texture(t_map_data *m_d)
{
	int i;

	i = 0;
	ft_texture_check(m_d);
	while(m_d->map[i])
	{
		if(tex_checker(m_d->map[i], "NO") == 1)
			m_d->NO = ft_split(m_d->map[i], ' ');
		if(tex_checker(m_d->map[i], "WE") == 1)
			m_d->WE = ft_split(m_d->map[i], ' ');
		if(tex_checker(m_d->map[i], "SO") == 1)
			m_d->SO = ft_split(m_d->map[i], ' ');
		if(tex_checker(m_d->map[i], "EA") == 1)
			m_d->EA = ft_split(m_d->map[i], ' ');
		if(tex_checker(m_d->map[i], "F") == 1) 
			m_d->Floor_color = check(m_d->map[i]);
		if(tex_checker(m_d->map[i], "C") == 1)
			m_d->sky_color = check(m_d->map[i]);
		i++;
	}
}
void	fill_map(t_map_data *m_d)
{
	int len = 0;
	int i = check_to_fill(m_d);
	int j = 0;
	while(m_d->map[len])
	len++;
	m_d->map_cub = (char **)malloc(sizeof(char*) * len - i);
	if((check_to_fill(m_d)))
	{
		while(m_d->map[i])
		{
			if( (m_d->map[i]))
			m_d->map_cub[j++] = ft_strdup(m_d->map[i]);
			i++;
		}
		m_d->map_cub[j] = NULL;
	}
	else if(!check_to_fill(m_d))
	error_printf("Invalid map!");
}
int	check_to_fill(t_map_data *m_d)
{
	int i = 6;
	int j;
	int componentCounts[2] = {0};
	while(m_d->map[i])
	{
		j = 0;
		while(m_d->map[i][j])
		{
			if(m_d->map[i][j] != ' ' && m_d->map[i][j] != '\n' && m_d->map[i][j] != '1'&& m_d->map[i][j] != '0'&& m_d->map[i][j] != 'N' && m_d->map[i][j] != '\t')
			return 0;
			else if(m_d->map[i][j] == '\n')
			componentCounts[0]++;
			else if(m_d->map[i][j] == '1')
			componentCounts[1]++;
			j++;
		}
		if(componentCounts[0] >= 0 && componentCounts[1] > 2)
		return i;
		i++;
	}
	return 0;
}
int	ft_len(t_map_data *m_d)
{
	int len;
    int longest = 0;
    int i = 0;

    while (m_d->map_cub[i])
	{
        if (m_d->map_cub[i])
		{
            len = ft_strlen(m_d->map_cub[i]);
            if (len > longest)
                longest = len;
        }
        i++;
    }
    return longest;
}
