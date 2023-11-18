/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:07:57 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/17 18:43:26 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	break_the_wall(t_bjt *p)
{
	int	i;
	int	j;

	i = -1;
	while (p->mini_map[++i])
	{
		j = -1;
		while (p->mini_map[i][++j])
		{
			if (p->mini_map[i][j] == '3' && p->breaking == 7)
				p->door_open = mlx_load_png("textures/animation/2.png");
			if (p->mini_map[i][j] == '3' && p->breaking == 14)
				p->door_open = mlx_load_png("textures/animation/3.png");
			if (p->mini_map[i][j] == '3' && p->breaking == 21)
				p->door_open = mlx_load_png("textures/animation/4.png");
			if (p->mini_map[i][j] == '3' && p->breaking == 28)
				p->door_open = mlx_load_png("textures/animation/5.png");
			if (p->mini_map[i][j] == '3' && p->breaking == 35)
			{
				p->mini_map[i][j] = '4';
				p->breaking = 0;
			}
		}
	}
}

void	fix_the_wall(t_bjt *p)
{
	int	i;
	int	j;

	i = -1;
	while (p->mini_map[++i])
	{
		j = -1;
		while (p->mini_map[i][++j])
		{
			if (p->mini_map[i][j] == '3' && p->reset == 7)
				p->door_open = mlx_load_png("textures/animation/5.png");
			if (p->mini_map[i][j] == '3' && p->reset == 14)
				p->door_open = mlx_load_png("textures/animation/4.png");
			if (p->mini_map[i][j] == '3' && p->reset == 21)
				p->door_open = mlx_load_png("textures/animation/3.png");
			if (p->mini_map[i][j] == '3' && p->reset == 28)
				p->door_open = mlx_load_png("textures/animation/2.png");
			if (p->mini_map[i][j] == '3' && p->reset == 35)
			{
				p->mini_map[i][j] = '2';
				p->reset = 0;
			}
		}
	}
}

void	fix_wall(t_bjt *p)
{
	if ((int)p->dist <= 100)
	{
		if (p->mini_map[((int)p->ray_ay) / 50][((int)p->ray_ax - 1)
			/ 50] == '4')
			p->mini_map[(int)p->ray_ay / 50][((int)p->ray_ax - 1) / 50] = '3';
		if (p->mini_map[((int)p->ray_ay - 1) / 50][((int)p->ray_ax)
			/ 50] == '4')
			p->mini_map[((int)p->ray_ay - 1) / 50][(int)p->ray_ax / 50] = '3';
		p->reset = 1;
	}
}

void	break_wall(t_bjt *p)
{
	if ((int)p->dist <= 100)
	{
		if (p->mini_map[(int)p->ray_ay / 50][(int)p->ray_ax / 50] == '2')
			p->mini_map[(int)p->ray_ay / 50][(int)p->ray_ax / 50] = '3';
		if (p->mini_map[((int)p->ray_ay) / 50][((int)p->ray_ax - 1)
			/ 50] == '2')
			p->mini_map[(int)p->ray_ay / 50][((int)p->ray_ax - 1) / 50] = '3';
		if (p->mini_map[((int)p->ray_ay - 1) / 50][((int)p->ray_ax)
			/ 50] == '2')
			p->mini_map[((int)p->ray_ay - 1) / 50][(int)p->ray_ax / 50] = '3';
		if (p->mini_map[(int)p->ray_ay / 50][(int)p->ray_ax / 50] == '4')
			p->mini_map[(int)p->ray_ay / 50][(int)p->ray_ax / 50] = '3';
		p->breaking = 1;
	}
}

void	put_horizontal_walls(t_bjt *p, int xx, int y, float dist_top)
{
	if (p->mini_map[(int)p->ray_ay / 50][(int)p->ray_ax / 50] == '2' ||
		p->mini_map[((int)p->ray_ay - 1) / 50][((int)p->ray_ax) / 50] == '2')
		render_wall_v(p, xx, y, dist_top);
	else if (p->mini_map[(int)p->ray_ay / 50][(int)p->ray_ax / 50] == '3' ||
				p->mini_map[((int)p->ray_ay - 1) / 50][((int)p->ray_ax)
					/ 50] == '3')
		render_crack_v(p, xx, y, dist_top);
	else if (p->mini_map[(int)p->ray_ay / 50][(int)p->ray_ax / 50] == '4' ||
				p->mini_map[((int)p->ray_ay - 1) / 50][((int)p->ray_ax)
					/ 50] == '4')
		render_door_v(p, xx, y, dist_top);
	else if (sin(p->rays) > 0)
		north_texture(p, xx, y, dist_top);
	else
		south_texture(p, xx, y, dist_top);
}
