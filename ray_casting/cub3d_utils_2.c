/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:15:51 by ckannane          #+#    #+#             */
/*   Updated: 2023/11/18 22:09:00 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_hight_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	exit_now(t_bjt *p)
{
	mlx_terminate(p->mlx);
	mlx_delete_texture(p->north);
	mlx_delete_texture(p->west);
	mlx_delete_texture(p->east);
	mlx_delete_texture(p->south);
	ft_free_struct(p);
	free(p);
	exit(0);
}

void	get_value(t_bjt *p)
{
	if (p->dis_h < p->dis_v)
	{
		p->ray_ax = p->h_x;
		p->ray_ay = p->h_y;
		p->dist = p->dis_h;
	}
	else
	{
		p->ray_ax = p->v_x;
		p->ray_ay = p->v_y;
		p->dist = p->dis_v;
	}
}

int	colon_size(char **av)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	return (i);
}

char	**read_map(char **av, int size)
{
	char	**map;
	char	*tmp;
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
		map[i] = ft_strdup(tmp);
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
	map[i] = 0;
	return (map);
}
