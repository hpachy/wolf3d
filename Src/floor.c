/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:35:42 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/08 13:35:43 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3D.h"
#include "libft.h"
#include <math.h>

static	void	app_texture1(t_data *p)
{
	p->floortexx = (int)(p->currentfloorx * p->width_wall) % p->width_wall;
	p->floortexy = (int)(p->currentfloory * p->height_wall) % p->height_wall;
	p->wall_tex.b = (unsigned char)(p->wood_text)[(p->floortexx << 2) +
		(p->floortexy * p->size_line_wall)] / (p->currentdist);
	p->wall_tex.g = (unsigned char)(p->wood_text)[(p->floortexx << 2) +
		(p->floortexy * p->size_line_wall) + 1] / (p->currentdist);
	p->wall_tex.r = (unsigned char)(p->wood_text)[(p->floortexx << 2) +
		(p->floortexy * p->size_line_wall) + 2] / (p->currentdist);
	p->wall_tex.trans = (p->wood_text)[(p->floortexx << 2) +
		(p->floortexy * p->size_line_wall) + 3];
}

static	void	app_texture2(t_data *p)
{
	p->floortexx = (int)(p->currentfloorx * p->width_wall_metal)
	% p->width_wall_metal;
	p->floortexy = (int)(p->currentfloory * p->height_wall_metal)
	% p->height_wall_metal;
	p->wall_tex.b = (unsigned char)(p->metal_text)[(p->floortexx << 2) +
		(p->floortexy * p->size_line_wall_metal)] / (p->currentdist);
	p->wall_tex.g = (unsigned char)(p->metal_text)[(p->floortexx << 2) +
		(p->floortexy * p->size_line_wall_metal) + 1] / (p->currentdist);
	p->wall_tex.r = (unsigned char)(p->metal_text)[(p->floortexx << 2) +
		(p->floortexy * p->size_line_wall_metal) + 2] / (p->currentdist);
	p->wall_tex.trans = (p->metal_text)[(p->floortexx << 2) +
		(p->floortexy * p->size_line_wall_metal) + 3];
}

void			app_texture(t_data *p)
{
	p->weight = (p->currentdist - p->distplayer) /
	(p->distwall - p->distplayer);
	p->currentfloorx = p->weight * p->floorxwall +
	(1.0 - p->weight) * p->posx;
	p->currentfloory = p->weight * p->floorywall +
	(1.0 - p->weight) * p->posy;
	if (p->definition_texture == 1)
		app_texture1(p);
	if (p->definition_texture == 2)
		app_texture2(p);
}

void			check_wall(t_data *p)
{
	p->y_floor = p->drawend;
	if (p->side == 0 && p->raydirx > 0)
	{
		p->floorxwall = p->mapx;
		p->floorywall = p->mapy + p->wallx;
	}
	else if (p->side == 0 && p->raydirx < 0)
	{
		p->floorxwall = p->mapx + 1.0;
		p->floorywall = p->mapy + p->wallx;
	}
	else if (p->side == 1 && p->raydiry > 0)
	{
		p->floorxwall = p->mapx + p->wallx;
		p->floorywall = p->mapy;
	}
	else
	{
		p->floorxwall = p->mapx + p->wallx;
		p->floorywall = p->mapy + 1.0;
	}
}

void			print_floor(t_data *p)
{
	check_wall(p);
	p->distwall = p->perpwalldist;
	if (p->drawend < 0)
		p->distplayer = 0.0;
	p->drawend = p->y;
	while (p->y_floor < p->y)
	{
		p->wall_tex.x = p->index;
		p->wall_tex.y = p->y_floor;
		p->currentdist = p->y / (2.0 * p->y_floor - p->y);
		app_texture(p);
		light_on(p->wall_tex.x, p->wall_tex.y, *p, p->wall_tex);
		++p->y_floor;
	}
}
