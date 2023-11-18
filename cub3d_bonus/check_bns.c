/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:55:49 by ckannane          #+#    #+#             */
/*   Updated: 2023/11/18 22:05:31 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	bonus_component_check(t_bjt *m_d)
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
			if (m_d->mini_map[i][j] != '1' && m_d->mini_map[i][j] != '2' && 
				m_d->mini_map[i][j] != '0' && m_d->mini_map[i][j] != 'N' && 
				m_d->mini_map[i][j] != 'W' && m_d->mini_map[i][j] != 'S' && 
				m_d->mini_map[i][j] != 'E' && m_d->mini_map[i][j] != '\n' && 
				m_d->mini_map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_all_b(t_bjt *map)
{
	if (!tab_check(map) || !border_check(map->tmp) || 
		!borders_checker(map) || !one_check(map) || 
		!bonus_component_check(map) || player_checker(map->mini_map) != 1)
	{
		ft_free_struct(map);
		erroc_exit(map, "Numbers incorrects, Invalid map!");
	}
}

void	reset_textures(t_bjt *p)
{
	mlx_delete_texture(p->north);
	mlx_delete_texture(p->south);
	mlx_delete_texture(p->east);
	mlx_delete_texture(p->west);
}

void	checkfile_name_b(char **av)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		error_file(line);
	free(line);
	while (av[1][i])
	{
		if (av[1][i] == '.' && av[1][i + 1] != '.')
		{
			i++;
			if (av[1][i] == 'c' && av[1][i + 1] == 'u' && \
			av[1][i + 2] == 'b' && av[1][i + 3] == '\0')
				break ;
			else
				exit(1);
		}
		i++;
	}
}
