/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:28:34 by ckannane          #+#    #+#             */
/*   Updated: 2023/11/13 22:29:43 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	north_texture(t_bjt *p, int x, int y, float dist_top)
{
	int	color;
	int	offse_x;
	int	offse_y;

	offse_y = dist_top * p->fac / 2;
	offse_x = (int)p->ray_ax % p->north->width;
	color = get_color_from_pos(p->north, offse_y, offse_x);
	mlx_put_pixel(p->angle, x, y, color);
}

void	east_texture(t_bjt *p, int x, int y, float dist_top)
{
	int	color;
	int	offse_x;
	int	offse_y;

	offse_y = dist_top * p->fac / 2;
	offse_x = (int)p->ray_ay % p->east->width;
	color = get_color_from_pos(p->east, offse_y, offse_x);
	mlx_put_pixel(p->angle, x, y, color);
}

void	south_texture(t_bjt *p, int x, int y, float dist_top)
{
	int	color;
	int	offse_x;
	int	offse_y;

	offse_y = dist_top * p->fac / 2;
	offse_x = (int)p->ray_ax % p->south->width;
	color = get_color_from_pos(p->south, offse_y, offse_x);
	mlx_put_pixel(p->angle, x, y, color);
}

void	west_texture(t_bjt *p, int x, int y, float dist_top)
{
	int	color;
	int	offse_x;
	int	offse_y;

	offse_y = dist_top * p->fac / 2;
	offse_x = (int)p->ray_ay % p->west->width;
	color = get_color_from_pos(p->west, offse_y, offse_x);
	mlx_put_pixel(p->angle, x, y, color);
}

void	fix_the_value(int *start, int *end)
{
	if (*start < 0)
		*start = 0;
	if (*start > (HEIGHT / 2))
		*start = (HEIGHT / 2);
	if (*end > HEIGHT)
		*end = HEIGHT;
	if (*end < HEIGHT / 2)
		*end = HEIGHT / 2;
}
