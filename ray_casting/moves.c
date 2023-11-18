/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:46:38 by ckannane          #+#    #+#             */
/*   Updated: 2023/11/16 19:54:43 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	step_check(t_bjt *p)
{
	float	i;
	float	j;

	j = p->tmp_x / (SQ);
	i = p->tmp_y / (SQ);
	if (p->mini_map[(int)i][(int)j] == '1' ||
		p->mini_map[(int)i][(int)j] == '2')
		return (0);
	i = (p->tmp_y + 2) / SQ;
	if (p->mini_map[(int)i][(int)j] == '1' ||
		p->mini_map[(int)i][(int)j] == '2')
		return (0);
	i = (p->tmp_y - 2) / SQ;
	if (p->mini_map[(int)i][(int)j] == '1' ||
		p->mini_map[(int)i][(int)j] == '2' )
		return (0);
	j = (p->tmp_x + 2) / SQ;
	if (p->mini_map[(int)i][(int)j] == '1' ||
		p->mini_map[(int)i][(int)j] == '2')
		return (0);
	j = (p->tmp_x - 2) / SQ;
	if (p->mini_map[(int)i][(int)j] == '1' ||
		p->mini_map[(int)i][(int)j] == '2')
		return (0);
	return (1);
}

void	move_a(t_bjt *p)
{
	p->tmp_x = p->p_x + 3 * sin(p->p_angle);
	p->tmp_y = p->p_y - 3 * cos(p->p_angle);
	if (step_check(p))
	{
		p->p_x = p->tmp_x;
		p->p_y = p->tmp_y;
	}
}

void	move_d(t_bjt *p)
{
	p->tmp_x = p->p_x - 3 * sin(p->p_angle);
	p->tmp_y = p->p_y + 3 * cos(p->p_angle);
	if (step_check(p))
	{
		p->p_x = p->tmp_x;
		p->p_y = p->tmp_y;
	}
}

void	move_w(t_bjt *p)
{
	p->tmp_x = p->p_x + 3 * cos(p->p_angle);
	p->tmp_y = p->p_y + 3 * sin(p->p_angle);
	if (step_check(p))
	{
		p->p_x = p->tmp_x;
		p->p_y = p->tmp_y;
	}
}

void	move_s(t_bjt *p)
{
	p->tmp_x = p->p_x - 3 * cos(p->p_angle);
	p->tmp_y = p->p_y - 3 * sin(p->p_angle);
	if (step_check(p))
	{
		p->p_x = p->tmp_x;
		p->p_y = p->tmp_y;
	}
}
