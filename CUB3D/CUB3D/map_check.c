/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:21:24 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/09 21:58:47 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	player_checker(char **av)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if(av[i][j] == 'N' )
			count++;
			else if(av[i][j] == 'E')
			count++;
			 else if(av[i][j] == 'S')
			count++;
			 else if(av[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
// int border_check(t_map_data *m_d)
// {
// 	int	i;
// 	int j;

// 	i = 0;
// 	zero_check(m_d);
// 	while (m_d->map_cub[i])
// 	{
// 		j = 0;
// 		while(m_d->map_cub[i][j])
// 		{
// 			while(m_d->map_cub[i][j] && m_d->map_cub[i][j] == ' ')
// 			j++;
// 			if(m_d->map_cub[i][j])
// 		}
// 		i++;
// 	}
// 	return (1);
// }
int	borders_checker(t_map_data *m_d)
{
	int	i;
	int j;

	i = 0;
	while (m_d->map_cub[i])
	{
		j = 0;
		while(m_d->map_cub[i][j])
		{
			if(m_d->map_cub[i][j] == '0' && (m_d->map_cub[i][j + 1] && m_d->map_cub[i][j + 1] != '0' && m_d->map_cub[i][j + 1] != '1' && m_d->map_cub[i][j + 1] != 'N' && m_d->map_cub[i][j + 1] != 'S' && m_d->map_cub[i][j + 1] != 'E' && m_d->map_cub[i][j + 1] != 'W'))
			return (0);
			if(m_d->map_cub[i][j] == '0' && (m_d->map_cub[i][j - 1] && m_d->map_cub[i][j - 1] != '0' && m_d->map_cub[i][j - 1] != '1' && m_d->map_cub[i][j - 1] != 'N' && m_d->map_cub[i][j - 1] != 'S' && m_d->map_cub[i][j - 1] != 'E' && m_d->map_cub[i][j - 1] != 'W'))
			return (0);
			if(m_d->map_cub[i][j] == '0' && (m_d->map_cub[i + 1][j] && m_d->map_cub[i + 1][j] != '0' && m_d->map_cub[i + 1][j] != '1' && m_d->map_cub[i + 1][j] != 'N' && m_d->map_cub[i + 1][j] != 'S' && m_d->map_cub[i + 1][j] != 'E' && m_d->map_cub[i + 1][j] != 'W'))
			return (0);
			if(m_d->map_cub[i][j] == '0' && (m_d->map_cub[i - 1][j] && m_d->map_cub[i - 1][j]  != '0' && m_d->map_cub[i - 1][j] != '1' && m_d->map_cub[i - 1][j] != 'N' && m_d->map_cub[i - 1][j] != 'S' && m_d->map_cub[i - 1][j] != 'E' && m_d->map_cub[i - 1][j] != 'W'))
			return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void ft_texture_check(t_map_data *m_d)
{
    int i;
    int componentCounts[6] = {0};

	i = 0;
    while (m_d->map[i])
	{
        if (tex_checker(m_d->map[i], "NO") == 1)
            componentCounts[0]++;
        else if (tex_checker(m_d->map[i], "WE") == 1)
            componentCounts[1]++;
        else if (tex_checker(m_d->map[i], "SO") == 1)
            componentCounts[2]++;
        else if (tex_checker(m_d->map[i], "EA") == 1)
            componentCounts[3]++;
        else if (tex_checker(m_d->map[i], "F") == 1)
            componentCounts[4]++;
        else if (tex_checker(m_d->map[i], "C") == 1)
            componentCounts[5]++;
        i++;
    }
    i = 0;
    while (i < 6)
	{
        if (componentCounts[i] > 1)
            error_printf("Error: Duplicate component found!");
		else if (componentCounts[i] == 0)
            error_printf("Error: Missing component!");
        i++;
    }
}
void	zero_check(t_map_data *m_d)
{
	int i = 0;
	int j;
	int len;
	while(m_d->map_cub[i])
	{
	len = ft_strlen(m_d->map_cub[i]);
		j = 0;
		while(m_d->map_cub[i][j])
		{
			if(m_d->map_cub[i][j] == '0' && j > len)
			{
				// if(j < len)
				error_printf("adfdsfsdfdsf");
			}
			j++;
		}
		i++;
	}
}