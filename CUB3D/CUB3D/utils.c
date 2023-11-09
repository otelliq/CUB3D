/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:41:45 by otelliq           #+#    #+#             */
/*   Updated: 2023/11/09 19:42:36 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	checker00(t_map_colors *m_c, char __unused **map)
{
	if(m_c->floor_R > 225 || m_c->floor_R < 0 || m_c->floor_G > 225 || m_c->floor_G < 0 || m_c->floor_B > 225 || m_c->floor_B < 0 || m_c->sky_R > 225 || m_c->sky_R < 0 || m_c->sky_G > 225 || m_c->sky_G < 0 ||  m_c->sky_B > 225 || m_c->sky_B < 0)
	{
		printf("Error, invalid RGB!");
		exit(0);
	}
	// if (player_checker(map) != 1)
	// {
	// 	printf("Error, invalid player count!");
	// 	exit(0);
	// }


}

// void	map_filler(t_map_data *m_d)
// {
// 	int i = 0;
// 	int len = 0;
// 	char *tmp;
// 	while(m_d->map[len])
// 	i++;
// }
void	error_printf(char *s)
{
	printf("%s\n", s);
	exit(1);
}