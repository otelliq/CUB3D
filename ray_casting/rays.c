/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:09:00 by ckannane          #+#    #+#             */
/*   Updated: 2023/11/10 20:56:53 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	chech_horizon_value(t_bjt *p)
{
	if (p->h_x > p->map_size_wide * SQ)
		p->h_x = p->map_size_wide * SQ;
	if (p->h_x < 0)
		p->h_x = 0;
	p->dis_h = sqrt((p->p_y - p->h_y) * (p->p_y - p->h_y) + 
			(p->p_x - p->h_x) * (p->p_x - p->h_x));
}

void	ray_horizon(t_bjt *p)
{
	p->h_y = (int)(p->p_y / SQ) * SQ;
	if (p->rays > 0 && p->rays < M_PI)
		p->h_y += SQ;
	p->h_x = p->p_x + (p->h_y - p->p_y) / tan(p->rays);
	if ((p->h_x <= p->map_size_wide * SQ && p->h_x >= 0 && 
			p->h_y <= p->map_size_hight * SQ && p->h_y >= 0))
	{
		if (p->mini_map[(int)(p->h_y / SQ)][(int)(p->h_x / SQ)] != '1' &&
			p->mini_map[(int)(p->h_y - 1) / SQ][(int)(p->h_x / SQ)] != '1')
		{
			while (1)
			{
				if (p->rays > 0 && p->rays < M_PI)
					p->h_y += SQ;
				else
					p->h_y -= SQ;
				p->h_x = p->p_x + (p->h_y - p->p_y) / tan(p->rays);
				if (touch_wall_hori(p))
					break ;
			}
		}
	}
	chech_horizon_value(p);
}

void	chech_vertical_value(t_bjt *p)
{
	if (p->v_y > p->map_size_hight * SQ || 
		(p->v_y < 0 && (p->rays > 0 && p->rays < M_PI)))
		p->v_y = p->map_size_hight * SQ;
	if (p->v_y < 0)
		p->v_y = 0;
	if (p->v_x > p->map_size_wide * SQ)
		p->v_x = p->map_size_wide * SQ;
	if (p->v_x < 0)
		p->v_x = 0;
	p->dis_v = sqrt((p->p_y - p->v_y) * (p->p_y - p->v_y) + 
			(p->p_x - p->v_x) * (p->p_x - p->v_x));
}

void	ray_vertical(t_bjt *p)
{
	p->v_x = (int)(p->p_x / SQ) * SQ;
	if (p->rays - 90 <= 0 && (p->rays <= M_PI / 2 || p->rays >= 3 * M_PI / 2))
		p->v_x += SQ;
	p->v_y = p->p_y - (p->p_x - p->v_x) * tan(p->rays);
	if ((p->v_x <= p->map_size_wide * SQ && p->v_x >= 0 && 
			p->v_y <= p->map_size_hight * SQ && p->v_y >= 0))
	{
		if (p->mini_map[(int)(p->v_y / SQ)][(int)(p->v_x / SQ)] != '1' && 
			p->mini_map[(int)(p->v_y) / SQ][(int)((p->v_x - 1) / SQ)] != '1')
		{
			while (1)
			{
				if (p->rays - 90 <= 0 && (p->rays <= M_PI / 2 || 
						p->rays >= 3 * M_PI / 2))
					p->v_x += SQ;
				else
					p->v_x -= SQ;
				p->v_y = p->p_y - (p->p_x - p->v_x) * tan(p->rays); 
				if (touch_wall_ver(p))
					break ;
			}
		}
	}
	chech_vertical_value(p);
}
