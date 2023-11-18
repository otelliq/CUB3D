/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:27:29 by ckannane          #+#    #+#             */
/*   Updated: 2023/11/18 22:37:33 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	procces_the_rendring_b(t_bjt *p)
{
	int		rays;
	int		start;
	int		end;
	float	distance_project;

	rays = -1;
	while (++rays < WIDE)
	{
		p->rays = rays / (float)WIDE + p->p_angle - M_PI / 6;
		normilatation_angle(&p->rays);
		ray_horizon_b(p);
		ray_vertical_b(p);
		get_value(p);
		p->dist = p->dist * cos(p->p_angle - p->rays);
		distance_project = (WIDE / 2) / tan(M_PI / 4);
		p->wall_height = (SQ / p->dist) * distance_project;
		if (p->wall_height < 0)
			p->wall_height *= -1;
		start = (HEIGHT / 2) - p->wall_height;
		end = (HEIGHT / 2) + p->wall_height;
		fix_the_value(&start, &end);
		open_close_door(p);
		dda_bns(p, rays, start, end);
	}
}

void	render_the_ground(t_bjt *p, int blue, int green, int red)
{
	int	sky;
	int	i;

	i = 0;
	sky = HEIGHT / 2;
	while (sky < HEIGHT)
	{
		i = 0;
		while (i <= WIDE)
			mlx_put_pixel(p->shadow, i++, sky, ft_pixel(red, green, blue, 255));
		sky++;
	}
}

void	render_the_sun_set(t_bjt *p, int blue, int green, int red)
{
	int	sky;
	int	i;

	i = 0;
	sky = 0;
	while (sky < (HEIGHT) / 2)
	{
		i = 0;
		while (i <= WIDE)
			mlx_put_pixel(p->shadow, i++, sky, ft_pixel(red, green, blue, 255));
		if (blue < 70)
			blue++;
		if (green < 255)
			green++;
		sky++;
	}
	render_the_ground(p, 206, 181, 156);
}

void	render_b(t_bjt *map)
{
	map->mlx = mlx_init(WIDE, HEIGHT, "CUB3D", 0);
	map->north = mlx_load_png("textures/red.png");
	map->west = mlx_load_png("textures/black.png");
	map->east = mlx_load_png("textures/sky.png");
	map->south = mlx_load_png("textures/green.png");
	map->door_closed = mlx_load_png("textures/animation/1.png");
	map->door_open = mlx_load_png("textures/animation/2.png");
	map->passing = mlx_load_png("textures/open_door.png");
	map->angle = mlx_new_image(map->mlx, WIDE, HEIGHT);
	map->shadow = mlx_new_image(map->mlx, WIDE, HEIGHT);
	render_the_sun_set(map, 0, 0, 255);
	mlx_image_to_window(map->mlx, map->angle, 0, 0);
	mlx_image_to_window(map->mlx, map->shadow, 0, 0);
	mlx_loop_hook(map->mlx, key_hook_b, map);
	mlx_loop(map->mlx);
}

int	main(int ac, char **av)
{
	t_bjt	*map;
	int		height;

	(void)ac;
	checkfile_name_b(av);
	map = malloc(sizeof(t_bjt));
	height = colon_size(av);
	map->file = read_map(av, height);
	fill_map(map);
	setup(map, 0, 0, 0);
	zero_check(map);
	check_all_b(map);
	init_struct_value(map);
	map->map_size_hight = ft_hight_size(map->mini_map);
	map->map_size_wide = ft_len(map->mini_map);
	if (map->map_size_hight > 70 || map->map_size_wide > 70)
	{
		printf("\nERROR : the MAP is dam big\
		\nwhat you trying to do ??? GTA VI map ?!");
		exit(1);
	}
	render_b(map);
	return (0);
}
