/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:13:22 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/01 11:05:33 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_map_colors
{
	int	floor_R;
	int	floor_G;
	int	floor_B;
	int	sky_R;
	int	sky_G;
	int	sky_B;

}t_map_colors;

typedef struct s_map_data
{
	int		row_count;
	int		col_count;
	char	**map_cub;
	char	**map;
	char	**NO;
	char	**WE;
	char	**EA;
	char	**SO;
	char	*Floor_color;
	char	*sky_color;
	char	**Floor_color1;
	char	**sky_color1;
}t_map_data;

void	checker00(t_map_colors *m_c, char **map);
int		cub_checker(char *haystack, char *needle);
int		player_checker(char **av);
char	**read_map(char **av, int size);
int	borders_checker(t_map_data *m_d);
void	ft_texture(t_map_data *m_d);
int	tex_checker(char *haystack, char *needle);
void	ft_colors(t_map_data *m_d, t_map_colors *m_c);
char	*check(char *str);
void	error_printf(char *s);
void ft_texture_check(t_map_data *m_d);
void	fill_map(t_map_data *m_d);
int	col_size(char **av);
int	check_to_fill(t_map_data *m_d);
int	ft_len(t_map_data *m_d);
void	zero_check(t_map_data *m_d);
#endif
