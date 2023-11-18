/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:55:16 by ckannane          #+#    #+#             */
/*   Updated: 2023/11/10 20:56:40 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	normilatation_angle(double *angle)
{
	if (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
	if (*angle < 0)
		*angle += 2 * M_PI;
}

int	touch_wall_hori(t_bjt *p)
{
	if (p->h_x > p->map_size_wide * SQ || p->h_x < 0)
		return (1);
	if (p->mini_map[(int)(p->h_y / SQ)][(int)(p->h_x / SQ)] == '1' ||
		p->mini_map[(int)(p->h_y - 1) / SQ][(int)(p->h_x / SQ)] == '1')
		return (1);
	return (0);
}

int	touch_wall_ver(t_bjt *p)
{
	if (p->v_y > p->map_size_hight * SQ || p->v_x > p->map_size_wide * SQ 
		|| p->v_y < 0 || p->v_x < 0)
		return (1);
	if (p->mini_map[(int)(p->v_y / SQ)][(int)(p->v_x / SQ)] == '1' || 
		p->mini_map[(int)(p->v_y) / SQ][(int)((p->v_x - 1) / SQ)] == '1')
		return (1);
	return (0);
}
