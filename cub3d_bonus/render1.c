/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:43:05 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/17 18:54:17 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_door_h(t_bjt *p, int x, int y, float dist_top)
{
	int	color;
	int	offse_x;
	int	offse_y;

	offse_y = dist_top * p->fac / 2;
	offse_x = (int)p->ray_ay % p->east->width;
	color = get_color_from_pos(p->passing, offse_y, offse_x);
	mlx_put_pixel(p->angle, x, y, color);
}

void	render_crack_h(t_bjt *p, int x, int y, float dist_top)
{
	int	color;
	int	offse_x;
	int	offse_y;

	offse_y = dist_top * p->fac / 2;
	offse_x = (int)p->ray_ay % p->east->width;
	color = get_color_from_pos(p->door_open, offse_y, offse_x);
	mlx_put_pixel(p->angle, x, y, color);
}

void	render_door_v(t_bjt *p, int x, int y, float dist_top)
{
	int	color;
	int	offse_x;
	int	offse_y;

	offse_y = dist_top * p->fac / 2;
	offse_x = (int)p->ray_ax % p->east->width;
	color = get_color_from_pos(p->passing, offse_y, offse_x);
	mlx_put_pixel(p->angle, x, y, color);
}

void	render_crack_v(t_bjt *p, int x, int y, float dist_top)
{
	int	color;
	int	offse_x;
	int	offse_y;

	offse_y = dist_top * p->fac / 2;
	offse_x = (int)p->ray_ax % p->east->width;
	color = get_color_from_pos(p->door_open, offse_y, offse_x);
	mlx_put_pixel(p->angle, x, y, color);
}

void	render_wall_h(t_bjt *p, int x, int y, float dist_top)
{
	int	color;
	int	offse_x;
	int	offse_y;

	offse_y = dist_top * p->fac / 2;
	offse_x = (int)p->ray_ay % p->east->width;
	color = get_color_from_pos(p->door_closed, offse_y, offse_x);
	mlx_put_pixel(p->angle, x, y, color);
}
