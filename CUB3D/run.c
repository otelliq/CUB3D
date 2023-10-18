/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:24:19 by otelliq           #+#    #+#             */
/*   Updated: 2023/10/18 20:08:00 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
char	**read_map(char **av, int size)
{
	char	**map;
	char	*tmp;
	char	__unused *new;
	int		fd;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	tmp = get_next_line(fd);
	map = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		map[i] = tmp;
		tmp = get_next_line(fd);
		// free (new);
		i++;
	}
	map[i] = 0;
	// free (tmp);
	return (map);
}
int	col_size(char **av)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free (str);
		str = get_next_line(fd);
		i++;
	}
	free (str);
	return (i);
}



int main(int ac, char **av)
{
	int height;
	if (cub_checker(av[1], ".cub") == 0)
	{
		printf("Error, invalid map name!");
		exit(0);
	}
	if (ac != 2)
	{
		printf("Error, more or less arguments!");
		exit(0);
	}
	t_map_data	*m_d;
	t_map_colors *m_c;
	m_c = malloc(sizeof(t_map_colors));
	m_d = malloc(sizeof (t_map_data));
	height = col_size(av);
	m_d->map = read_map(av, height);
	ft_texture(m_d);
	ft_colors(m_d, m_c);
	checker00(m_c, m_d->map);
	fill_map(m_d);
	// int i = 0;
	// while(m_d->map_cub[i])
	// printf("%s\n", m_d->map_cub[i++]);
	// int le = ft_len(m_d);
	// printf("%d\n", le);
	return 0;
}
