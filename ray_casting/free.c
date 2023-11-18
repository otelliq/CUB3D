/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:34:58 by ckannane          #+#    #+#             */
/*   Updated: 2023/11/18 21:50:57 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_double_array(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
}

void	ft_free_struct_b(t_bjt *p)
{
	if (p->file)
		free_double_array(p->file);
	if (p->mini_map)
		free_double_array(p->mini_map);
	if (p->tmp)
		free_double_array(p->tmp);
}

void	exit_now_b(t_bjt *p)
{
	mlx_terminate(p->mlx);
	mlx_delete_texture(p->north);
	mlx_delete_texture(p->west);
	mlx_delete_texture(p->east);
	mlx_delete_texture(p->south);
	ft_free_struct_b(p);
	free(p);
	exit(0);
}

void	ft_free_struct(t_bjt *p)
{
	if (p->file)
		free_double_array(p->file);
	if (p->mini_map)
		free_double_array(p->mini_map);
	if (p->tmp)
		free_double_array(p->tmp);
	if (p->floor_color1)
		free_double_array(p->floor_color1);
	if (p->sky_color1)
		free_double_array(p->sky_color1);
	if (p->no)
		free_double_array(p->no);
	if (p->we)
		free_double_array(p->we);
	if (p->ea)
		free_double_array(p->ea);
	if (p->so)
		free_double_array(p->so);
	if (p->sky_color)
		free(p->sky_color);
	if (p->floor_color)
		free(p->floor_color);
}

void	erroc_exit(t_bjt *p, char *text)
{
	printf("Error\n%s\n", text);
	free(p);
	exit(1);
}
