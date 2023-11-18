/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:12:01 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/18 21:49:21 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_vertical_walls(t_bjt *p, int xx, int y, float dist_top)
{
	if (p->mini_map[(int)p->ray_ay / 50][(int)p->ray_ax / 50] == '2' ||
		p->mini_map[((int)p->ray_ay) / 50][((int)p->ray_ax - 1) / 50] == '2')
		render_wall_h(p, xx, y, dist_top);
	else if (p->mini_map[(int)p->ray_ay / 50][(int)p->ray_ax / 50] == '3' ||
				p->mini_map[((int)p->ray_ay) / 50][((int)p->ray_ax - 1)
					/ 50] == '3')
		render_crack_h(p, xx, y, dist_top);
	else if (p->mini_map[(int)p->ray_ay / 50][(int)p->ray_ax / 50] == '4' ||
				p->mini_map[((int)p->ray_ay) / 50][((int)p->ray_ax - 1)
					/ 50] == '4')
		render_door_h(p, xx, y, dist_top);
	else if (cos(p->rays) > 0)
		east_texture(p, xx, y, dist_top);
	else
		west_texture(p, xx, y, dist_top);
}

int	touch_wall_hori_b(t_bjt *p)
{
	if (p->h_x > p->map_size_wide * SQ || p->h_x < 0)
		return (1);
	if (p->mini_map[(int)(p->h_y / SQ)][(int)(p->h_x / SQ)] == '1' ||
		p->mini_map[(int)(p->h_y - 1) / SQ][(int)(p->h_x / SQ)] == '1')
		return (1);
	if (p->mini_map[(int)(p->h_y / SQ)][(int)(p->h_x / SQ)] == '2' ||
		p->mini_map[(int)(p->h_y - 1) / SQ][(int)(p->h_x / SQ)] == '2')
	{
		p->door_detected = 1;
		return (1);
	}
	if (p->mini_map[(int)(p->h_y / SQ)][(int)(p->h_x / SQ)] == '3' ||
		p->mini_map[(int)(p->h_y - 1) / SQ][(int)(p->h_x / SQ)] == '3')
	{
		p->door_detected = 1;
		return (1);
	}
	if (p->mini_map[(int)(p->h_y / SQ)][(int)(p->h_x / SQ)] == '4' ||
		p->mini_map[(int)(p->h_y - 1) / SQ][(int)(p->h_x / SQ)] == '4')
	{
		p->door_detected = 1;
		return (1);
	}
	return (0);
}

int	touch_wall_ver_b(t_bjt *p)
{
	if (p->v_y > p->map_size_hight * SQ || p->v_x > p->map_size_wide * SQ
		|| p->v_y < 0 || p->v_x < 0)
		return (1);
	if (p->mini_map[(int)(p->v_y / SQ)][(int)(p->v_x / SQ)] == '1' ||
		p->mini_map[(int)(p->v_y) / SQ][(int)((p->v_x - 1) / SQ)] == '1')
		return (1);
	if (p->mini_map[(int)(p->v_y / SQ)][(int)(p->v_x / SQ)] == '2' ||
		p->mini_map[(int)(p->v_y) / SQ][(int)((p->v_x - 1) / SQ)] == '2')
	{
		p->door_detected = 1;
		return (1);
	}
	if (p->mini_map[(int)(p->v_y / SQ)][(int)(p->v_x / SQ)] == '3' ||
		p->mini_map[(int)(p->v_y) / SQ][(int)((p->v_x - 1) / SQ)] == '3')
	{
		p->door_detected = 1;
		return (1);
	}
	if (p->mini_map[(int)(p->v_y / SQ)][(int)(p->v_x / SQ)] == '4' ||
		p->mini_map[(int)(p->v_y) / SQ][(int)((p->v_x - 1) / SQ)] == '4')
	{
		p->door_detected = 1;
		return (1);
	}
	return (0);
}

void	water_fall2(t_bjt *p)
{
	if (p->fps == 3)
	{
		reset_textures(p);
		p->north = mlx_load_png("textures/animation/water_fall/north/wn_1.png");
		p->south = mlx_load_png("textures/animation/water_fall/south/wn_1.png");
		p->east = mlx_load_png("textures/animation/water_fall/east/wn_1.png");
		p->west = mlx_load_png("textures/animation/water_fall/west/wn_1.png");
	}
	if (p->fps == 6)
	{
		reset_textures(p);
		p->north = mlx_load_png("textures/animation/water_fall/north/wn_2.png");
		p->south = mlx_load_png("textures/animation/water_fall/south/wn_2.png");
		p->east = mlx_load_png("textures/animation/water_fall/east/wn_2.png");
		p->west = mlx_load_png("textures/animation/water_fall/west/wn_2.png");
	}
}

void	water_fall(t_bjt *p)
{
	if (p->fps == 9)
	{
		reset_textures(p);
		p->north = mlx_load_png("textures/animation/water_fall/north/wn_3.png");
		p->south = mlx_load_png("textures/animation/water_fall/south/wn_3.png");
		p->east = mlx_load_png("textures/animation/water_fall/east/wn_3.png");
		p->west = mlx_load_png("textures/animation/water_fall/west/wn_3.png");
	}
	if (p->fps == 12)
	{
		reset_textures(p);
		p->north = mlx_load_png("textures/animation/water_fall/north/wn_4.png");
		p->south = mlx_load_png("textures/animation/water_fall/south/wn_4.png");
		p->east = mlx_load_png("textures/animation/water_fall/east/wn_4.png");
		p->west = mlx_load_png("textures/animation/water_fall/west/wn_4.png");
	}
	if (p->fps == 15)
	{
		reset_textures(p);
		p->north = mlx_load_png("textures/animation/water_fall/north/wn_5.png");
		p->south = mlx_load_png("textures/animation/water_fall/south/wn_5.png");
		p->east = mlx_load_png("textures/animation/water_fall/east/wn_5.png");
		p->west = mlx_load_png("textures/animation/water_fall/west/wn_5.png");
		p->fps = 0;
	}
}
