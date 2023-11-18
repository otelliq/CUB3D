/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:15:40 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/18 22:09:43 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mouse_mouves(t_bjt *p)
{
	int	tmp_mous_x;
	int	tmp_mous_y;

	tmp_mous_x = p->mous_x;
	tmp_mous_y = p->mous_y;
	mlx_get_mouse_pos(p->mlx, &tmp_mous_x, &tmp_mous_y);
	if (tmp_mous_x < p->mous_x && tmp_mous_x > 0
		&& tmp_mous_x < WIDE && tmp_mous_y > 0 && tmp_mous_y < HEIGHT)
	{
		p->p_angle -= degree_to_radians(4);
		p->mous_x = tmp_mous_x;
		p->mous_y = tmp_mous_y;
	}
	if (tmp_mous_x > p->mous_x && tmp_mous_x > 0
		&& tmp_mous_x < WIDE && tmp_mous_y > 0 && tmp_mous_y < HEIGHT)
	{
		p->p_angle += degree_to_radians(4);
		p->mous_x = tmp_mous_x;
		p->mous_y = tmp_mous_y;
	}
}

void	commands(t_bjt *p)
{
	if (mlx_is_key_down(p->mlx, MLX_KEY_A))
		move_a(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_S))
		move_s(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_D))
		move_d(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_W))
		move_w(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_SPACE))
		break_wall(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		exit_now_b(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
		p->p_angle += degree_to_radians(2);
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
		p->p_angle -= degree_to_radians(2);
	mouse_mouves(p);
}

void	key_hook_b(void *map)
{
	t_bjt	*p;

	p = map;
	p->tmp_x = p->p_x;
	p->tmp_y = p->p_y;
	commands(p);
	normilatation_angle(&p->p_angle);
	mlx_delete_image(p->mlx, p->angle);
	if (p->breaking != 0)
		p->breaking++;
	if (p->reset != 0)
		p->reset++;
	p->angle = mlx_new_image(p->mlx, WIDE, HEIGHT);
	mlx_image_to_window(p->mlx, p->angle, 0, 0);
	procces_the_rendring_b(p);
	break_the_wall(p);
	fix_the_wall(p);
	water_fall(p);
	water_fall2(p);
	p->fps++;
	print_map(p);
}

void	setup(t_bjt *map, int i, int j, int n)
{
	(void)n;
	while (map->mini_map[i])
	{
		j = 0;
		while (map->mini_map[i][j])
		{
			if (map->mini_map[i][j] == 'N' || map->mini_map[i][j] == 'E'
				|| map->mini_map[i][j] == 'W' || map->mini_map[i][j] == 'S')
			{
				if (map->mini_map[i][j] == 'N')
					map->p_angle = 3 * M_PI / 2;
				else if (map->mini_map[i][j] == 'W')
					map->p_angle = 0;
				else if (map->mini_map[i][j] == 'E')
					map->p_angle = M_PI;
				else if (map->mini_map[i][j] == 'S')
					map->p_angle = M_PI / 2;
				map->p_y = 50 * i + 25;
				map->p_x = 50 * j + 25;
			}
			j++;
		}
		i++;
	}
}

void	open_close_door(t_bjt *p)
{
	if (mlx_is_key_down(p->mlx, MLX_KEY_SPACE))
		break_wall(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_C))
		fix_wall(p);
}
