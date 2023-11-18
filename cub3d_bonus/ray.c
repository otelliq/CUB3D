/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:17:16 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/18 12:17:19 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_simulation_h(t_bjt *p)
{
	while (1)
	{
		if (p->rays > 0 && p->rays < M_PI)
			p->h_y += SQ;
		else
			p->h_y -= SQ;
		p->h_x = p->p_x + (p->h_y - p->p_y) / tan(p->rays);
		if (touch_wall_hori_b(p))
			break ;
	}
}

void	ray_simulation_v(t_bjt *p)
{
	while (1)
	{
		if (p->rays - 90 <= 0 && (p->rays <= M_PI / 2 || p->rays >= 3 * M_PI
				/ 2))
			p->v_x += SQ;
		else
			p->v_x -= SQ;
		p->v_y = p->p_y - (p->p_x - p->v_x) * tan(p->rays);
		if (touch_wall_ver_b(p))
			break ;
	}
}

void	ray_horizon_b(t_bjt *p)
{
	p->h_y = (int)(p->p_y / SQ) * SQ;
	if (p->rays > 0 && p->rays < M_PI)
		p->h_y += SQ;
	p->h_x = p->p_x + (p->h_y - p->p_y) / tan(p->rays);
	if ((p->h_x <= p->map_size_wide * SQ && p->h_x >= 0
			&& p->h_y <= p->map_size_hight * SQ && p->h_y >= 0))
	{
		if ((p->mini_map[(int)(p->h_y / SQ)][(int)(p->h_x / SQ)] != '1' &&
				p->mini_map[(int)(p->h_y - 1) / SQ][(int)(p->h_x / SQ)] != '1')
				&&
			(p->mini_map[(int)(p->h_y / SQ)][(int)(p->h_x / SQ)] != '2' &&
				p->mini_map[(int)(p->h_y - 1) / SQ][(int)(p->h_x / SQ)] != '2')
				&&
			(p->mini_map[(int)(p->h_y / SQ)][(int)(p->h_x / SQ)] != '3' &&
				p->mini_map[(int)(p->h_y - 1) / SQ][(int)(p->h_x / SQ)] != '3')
				&&
			(p->mini_map[(int)(p->h_y / SQ)][(int)(p->h_x / SQ)] != '4' &&
				p->mini_map[(int)(p->h_y - 1) / SQ][(int)(p->h_x / SQ)] != '4'))
			ray_simulation_h(p);
	}
	chech_horizon_value(p);
}

void	ray_vertical_b(t_bjt *p)
{
	p->v_x = (int)(p->p_x / SQ) * SQ;
	if (p->rays - 90 <= 0 && (p->rays <= M_PI / 2 || p->rays >= 3 * M_PI / 2))
		p->v_x += SQ;
	p->v_y = p->p_y - (p->p_x - p->v_x) * tan(p->rays);
	if ((p->v_x <= p->map_size_wide * SQ && p->v_x >= 0
			&& p->v_y <= p->map_size_hight * SQ && p->v_y >= 0))
	{
		if ((p->mini_map[(int)(p->v_y / SQ)][(int)(p->v_x / SQ)] != '1' &&
				p->mini_map[(int)(p->v_y) / SQ][(int)((p->v_x - 1)
						/ SQ)] != '1') &&
			(p->mini_map[(int)(p->v_y / SQ)][(int)(p->v_x / SQ)] != '2' &&
				p->mini_map[(int)(p->v_y) / SQ][(int)((p->v_x - 1)
						/ SQ)] != '2') &&
			(p->mini_map[(int)(p->v_y / SQ)][(int)(p->v_x / SQ)] != '3' &&
				p->mini_map[(int)(p->v_y) / SQ][(int)((p->v_x - 1)
						/ SQ)] != '3') &&
			(p->mini_map[(int)(p->v_y / SQ)][(int)(p->v_x / SQ)] != '4' &&
				p->mini_map[(int)(p->v_y) / SQ][(int)((p->v_x - 1)
						/ SQ)] != '4'))
			ray_simulation_v(p);
	}
	chech_vertical_value(p);
}

void	init_struct_value(t_bjt *map)
{
	map->mous_x = 0;
	map->mous_y = 0;
	map->breaking = 0;
	map->reset = 0;
	map->fps = 0;
}
