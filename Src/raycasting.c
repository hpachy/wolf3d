/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:35:42 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/19 16:56:03 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3D.h"
#include "libft.h"
#include <math.h>

void	print_sky(t_data *p)
{
	p->lineheight = (int)(p->y / p->perpwalldist);
	p->point1.r = 0xFF;
	p->point1.g = 0xFF;
	p->point1.b = 0xFF;
	p->point1.trans = 0xFF;
	p->point1.x = p->index;
	p->point1.y = 0;
	p->point2.x = p->index;
	p->point2.y = p->drawstart;
}

void	direction(t_data *p)
{
	if (p->raydirx < 0)
	{
		p->stepx = -1;
		p->sidedistx = (p->rayposx - p->mapx) * p->deltadistx;
	}
	else
	{
		p->stepx = 1;
		p->sidedistx = (p->mapx + 1.0 - p->rayposx) * p->deltadistx;
	}
	if (p->raydiry < 0)
	{
		p->stepy = -1;
		p->sidedisty = (p->rayposy - p->mapy) * p->deltadisty;
	}
	else
	{
		p->stepy = 1;
		p->sidedisty = (p->mapy + 1.0 - p->rayposy) * p->deltadisty;
	}
}

void	wall_detection(t_data *p)
{
	while (p->hit == 0)
	{
		if (p->sidedistx < p->sidedisty)
		{
			p->sidedistx += p->deltadistx;
			p->mapx += p->stepx;
			p->side = 0;
		}
		else
		{
			p->sidedisty += p->deltadisty;
			p->mapy += p->stepy;
			p->side = 1;
		}
		if (p->map[p->mapy][p->mapx].wall > 0)
			p->hit = 1;
	}
}

void	application_color(t_data *p)
{
	p->drawstart = -(p->lineheight >> 1) + (p->y >> 1);
	if (p->drawstart < 0)
		p->drawstart = 0;
	p->drawend = (p->lineheight >> 1) + (p->y >> 1);
	if (p->drawend >= p->y)
		p->drawend = p->y - 1;
	p->point1.x = p->index;
	p->point1.y = 0;
	p->point2.x = p->index;
	p->point2.y = p->drawstart;
	opti_line(*p, p->point1, p->point2);
}

int		ray_casting(t_data *p)
{
	p->index = 0;
	while (p->index < p->x)
	{
		wall_hit_box(p);
		print_sky(p);
		opti_line(*p, p->point1, p->point2);
		application_color(p);
		if (p->definition_texture == 1)
			print_wall(p);
		if (p->definition_texture == 2)
			print_wall_hd(p);
		print_floor(p);
		if (p->index == 400)
		{
			p->wall_pos_x = p->mapx;
			p->wall_pos_y = p->mapy;
		}
		p->index++;
	}
	return (0);
}
