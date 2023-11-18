/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:17:29 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/18 11:58:41 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_it(t_bjt *p, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= p->map_fac)
	{
		j = 0;
		while (j <= p->map_fac)
		{
			mlx_put_pixel(p->angle, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	print_player(t_bjt *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= 1)
	{
		j = 0;
		while (j <= 1)
		{
			mlx_put_pixel(p->angle, ((p->p_x / 50) * p->map_fac) + j,
				((p->p_y / 50) * p->map_fac) + i, ft_pixel(0, 255, 0, 255));
			j++;
		}
		i++;
	}
}

void	print_map(t_bjt *map)
{
	int		i;
	int		j;

	i = -1;
	if ((map->map_size_wide * SQ) / WIDE > (map->map_size_hight * SQ) / HEIGHT)
		map->map_fac = 10 / ((map->map_size_wide * SQ) / WIDE);
	else
		map->map_fac = 10 / ((map->map_size_hight * SQ) / HEIGHT);
	while (map->mini_map[++i])
	{
		j = -1;
		while (map->mini_map[i][++j])
		{
			if (map->mini_map[i][j] == '1')
				print_it(map, j * map->map_fac, i * map->map_fac,
					ft_pixel(255, 255, 255, 150));
			if (map->mini_map[i][j] == '2' || map->mini_map[i][j] == '3')
				print_it(map, j * map->map_fac, i * map->map_fac,
					ft_pixel(255, 0, 255, 150));
			if (map->mini_map[i][j] == '4')
				print_it(map, j * map->map_fac, i * map->map_fac,
					ft_pixel(0, 0, 255, 150));
		}
	}
	print_player(map);
}

void	dda_bns(t_bjt *p, int xx, int y, int yy)
{
	int		i;
	float	j;
	float	dist_top;

	i = -1;
	j = yy - y;
	p->fac = p->east->height / p->wall_height;
	while (++i <= j)
	{
		dist_top = y + (p->wall_height) - (HEIGHT / 2);
		if (p->dis_h > p->dis_v)
			put_vertical_walls(p, xx, y, dist_top);
		else
			put_horizontal_walls(p, xx, y, dist_top);
		y++;
	}
}

void	render_wall_v(t_bjt *p, int x, int y, float dist_top)
{
	int	color;
	int	offse_x;
	int	offse_y;

	offse_y = dist_top * p->fac / 2;
	offse_x = (int)p->ray_ax % p->east->width;
	color = get_color_from_pos(p->door_closed, offse_y, offse_x);
	mlx_put_pixel(p->angle, x, y, color);
}
