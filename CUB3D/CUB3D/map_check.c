/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:21:24 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/14 23:24:55 by otelliq          ###   ########.fr       */
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
int border_check(t_map_data *m_d)
{
    int i = 0;

    while (m_d->map_cub[i]) {
        int j = 0;

        while (m_d->map_cub[i][j] && m_d->map_cub[i][j] == ' ')
            j++;

        if (m_d->map_cub[i][j] != '1')
            return 0;
        j = ft_strlen(m_d->map_cub[i]) - 1;
        while (j >= 0 && m_d->map_cub[i][j] == ' ')
            j--;
        if (j >= 0 && m_d->map_cub[i][j] != '1')
            return 0;

        i++;
    }
    return 1;
}
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
			if ((m_d->map_cub[i][j] == '0' && m_d->map_cub[i][j + 1] == ' ') || (m_d->map_cub[i][j] == '0' && m_d->map_cub[i][j - 1] == ' ') || (m_d->map_cub[i][j] == '0' && m_d->map_cub[i + 1][j] == ' ') || (m_d->map_cub[i][j] == '0' && m_d->map_cub[i - 1][j] == ' '))
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
void zero_check(t_map_data *m_d)
{
    int i;
	int	j;
    int next_line_len;
    int prev_line_len;
	
	i  = 1;
    while (m_d->map_cub[i + 1])
	{
		next_line_len = ft_strlen(m_d->map_cub[i + 1]);
		prev_line_len = ft_strlen(m_d->map_cub[i - 1]);
        j = 0;
        while (m_d->map_cub[i][j])
		{
            if (m_d->map_cub[i][j] == '0' && (j >= next_line_len || j >= prev_line_len))
                error_printf("Invalid position for '0' in the row.");
            j++;
        }

        i++;
    }
}
int	one_check(t_map_data *m_d)
{
	int i;
	int j;

	j = 0;
		while(m_d->map_cub[0][j])
		{
			if(m_d->map_cub[0][j] == '0')
			return 0;
		j++;
		}
		i = check_to_check(m_d);
		j = 0;
		while(m_d->map_cub[i][j])
		{
			if(m_d->map_cub[i][j] == '0')
			return 0;
		j++;
		}
	return 1;
}

int	check_to_check(t_map_data *m_d)
{
	int i = 0;
	int j;
	while(m_d->map_cub[i])
	i++;
	i--;
	while(m_d->map_cub[i])
	{
		j = 0;
		while(m_d->map_cub[i][j])
		{
			if(m_d->map_cub[i][j] == '1')
			return i;
			j++;
		}
		i--;
	}
	return 0;
}
int	bonus_component_check(t_map_data *m_d)
{
	int i = 0;
	int j = 0;
	while(m_d->map_cub[i])
	{
		j = 0;
		while(m_d->map_cub[i][j])
		{
			if(m_d->map_cub[i][j] != '1' && m_d->map_cub[i][j] != '2' && m_d->map_cub[i][j] != '3' && m_d->map_cub[i][j] != '0' && m_d->map_cub[i][j] != 'N' && m_d->map_cub[i][j] != 'W' && m_d->map_cub[i][j] != 'S' && m_d->map_cub[i][j] != 'E' && m_d->map_cub[i][j] != '\n' && m_d->map_cub[i][j] != ' ')
			return(0);
			j++;
		}
		i++;
	}
	return(1);
}
int	component_check(t_map_data *m_d)
{
	int i = 0;
	int j = 0;
	while(m_d->map_cub[i])
	{
		j = 0;
		while(m_d->map_cub[i][j])
		{
			if(m_d->map_cub[i][j] != '1' && m_d->map_cub[i][j] != '0' && m_d->map_cub[i][j] != 'N' && m_d->map_cub[i][j] != 'W' && m_d->map_cub[i][j] != 'S' && m_d->map_cub[i][j] != 'E' && m_d->map_cub[i][j] != '\n' && m_d->map_cub[i][j] != ' ')
			return(0);
			j++;
		}
		i++;
	}
	return(1);
}
int	tab_check(t_map_data *m_d)
{
	int i = 0;
	int j = 0;
	while(m_d->map[i])
	{
		j = 0;
		while(m_d->map[i][j])
		{
			if(m_d->map[i][j] == '\t')
			j++;
		}
		i++;
	}
	return(1);
}