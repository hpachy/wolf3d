/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:35:42 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/10 11:25:17 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Wolf3D.h"
#include "../libft/libft.h"
#include <math.h>

void	chose_texture(t_data *p)
{
	if (p->map[p->mapy][p->mapx].wall == 1)
		grey_stone_wall(p);
	if (p->map[p->mapy][p->mapx].wall == 2)
		blue_stone(p);
	if (p->map[p->mapy][p->mapx].wall == 3)
		eagle(p);
	if (p->map[p->mapy][p->mapx].wall == 4 ||
		p->map[p->mapy][p->mapx].wall == 9)
		barrel(p);
	if (p->map[p->mapy][p->mapx].wall == 5)
		wall_brique(p);
	if (p->map[p->mapy][p->mapx].wall == 6)
		youmad(p);
	if (p->map[p->mapy][p->mapx].wall == 7)
		bedrock(p);
	if (p->map[p->mapy][p->mapx].wall == 8)
		trollcat(p);
	if (p->map[p->mapy][p->mapx].wall == 10)
		key2(p);
}

void	chose_texture_hd(t_data *p)
{
	if (p->map[p->mapy][p->mapx].wall == 1)
		blue_orange(p);
	if (p->map[p->mapy][p->mapx].wall == 2)
		brown(p);
	if (p->map[p->mapy][p->mapx].wall == 3)
		lotus(p);
	if (p->map[p->mapy][p->mapx].wall == 4)
		bush(p);
	if (p->map[p->mapy][p->mapx].wall == 5)
		blue(p);
	if (p->map[p->mapy][p->mapx].wall == 6)
		troll_cat_hd(p);
	if (p->map[p->mapy][p->mapx].wall == 7)
		green(p);
	if (p->map[p->mapy][p->mapx].wall == 8)
		troll_cat_hd(p);
	if (p->map[p->mapy][p->mapx].wall == 9)
		door(p);
	if (p->map[p->mapy][p->mapx].wall == 10)
		brown_key(p);
}

void	print_wall_hd(t_data *p)
{
	int				y;

	y = p->drawstart;
	if (p->side == 0)
		p->wallx = p->rayposy + p->perpwalldist * p->raydiry;
	else
		p->wallx = p->rayposx + p->perpwalldist * p->raydirx;
	p->wallx -= (int)p->wallx;
	p->texx = (int)(p->wallx * (double)(p->width_wall_hd));
	if (p->side == 0 && p->raydirx > 0)
		p->texx = p->width_wall_hd - p->texx - 1;
	if (p->side == 1 && p->raydiry < 0)
		p->texx = p->width_wall_hd - p->texx - 1;
	p->wall_tex.x = p->index;
	print_wall_color_hd(p, y);
}

void	print_wall(t_data *p)
{
	int		y;

	y = p->drawstart;
	if (p->side == 0)
		p->wallx = p->rayposy + p->perpwalldist * p->raydiry;
	else
		p->wallx = p->rayposx + p->perpwalldist * p->raydirx;
	p->wallx -= (int)p->wallx;
	p->texx = (int)(p->wallx * (double)(p->width_wall));
	if (p->side == 0 && p->raydirx > 0)
		p->texx = p->width_wall - p->texx - 1;
	if (p->side == 1 && p->raydiry < 0)
		p->texx = p->width_wall - p->texx - 1;
	p->wall_tex.x = p->index;
	print_wall_color(p, y);
}
