/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:25:37 by ckannane          #+#    #+#             */
/*   Updated: 2023/11/18 22:34:51 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_hook(void *map)
{
	t_bjt	*p;

	p = map;
	p->tmp_x = p->p_x;
	p->tmp_y = p->p_y;
	if (mlx_is_key_down(p->mlx, MLX_KEY_A))
		move_a(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_S))
		move_s(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_D))
		move_d(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_W))
		move_w(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		exit_now(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
		p->p_angle += degree_to_radians(2);
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
		p->p_angle -= degree_to_radians(2);
	normilatation_angle(&p->p_angle);
	mlx_delete_image(p->mlx, p->angle);
	p->angle = mlx_new_image(p->mlx, WIDE, HEIGHT);
	mlx_image_to_window(p->mlx, p->angle, 0, 0);
	procces_the_rendring(p);
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
					map->p_angle = M_PI;
				else if (map->mini_map[i][j] == 'E')
					map->p_angle = 0;
				else if (map->mini_map[i][j] == 'S')
					map->p_angle = M_PI / 2;
				map->p_y = SQ * i + 25;
				map->p_x = SQ * j + 25;
			}
			j++;
		}
		i++;
	}
}

void	checkfile_name(char **av)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		error_file(line);
	free(line);
	while (av[1][i])
	{
		if (av[1][i] == '.' && av[1][i + 1] != '.')
		{
			i++;
			if (av[1][i] == 'c' && av[1][i + 1] == 'u' && \
			av[1][i + 2] == 'b' && av[1][i + 3] == '\0')
				break ;
			else
				exit(1);
		}
		i++;
	}
}

void	check_all(t_bjt *map)
{
	if (!tab_check(map) || !one_check(map) || !zero_check(map) || 
		!border_check(map->tmp) || !borders_checker(map)
		|| !component_check(map) || !component_check(map)
		|| player_checker(map->mini_map) != 1)
	{
		ft_free_struct_b(map);
		erroc_exit(map, "Numbers incorrects, Invalid map!");
	}
}

int	main(int ac, char **av)
{
	t_bjt	*map;
	int		height;

	(void)ac;
	checkfile_name(av);
	map = malloc(sizeof(t_bjt));
	height = colon_size(av);
	map->file = read_map(av, height);
	fill_map(map);
	setup(map, 0, 0, 0);
	ft_texture(map);
	ft_colors(map);
	check_all(map);
	checker00(map);
	map->map_size_hight = ft_hight_size(map->mini_map);
	map->map_size_wide = ft_len(map->mini_map);
	render(map);
	return (0);
}
