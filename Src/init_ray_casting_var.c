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
#include "math.h"

void	init_while(t_data *p)
{
	p->camerax = 2 * p->index / (double)p->x - 1;
	p->rayposx = p->posx;
	p->rayposy = p->posy;
	p->raydirx = p->dirx + p->planex * p->camerax;
	p->raydiry = p->diry + p->planey * p->camerax;
	p->mapx = (int)p->rayposx;
	p->mapy = (int)p->rayposy;
	p->deltadistx = sqrt(1 + (p->raydiry * p->raydiry)
		/ (p->raydirx * p->raydirx));
	p->deltadisty = sqrt(1 + (p->raydirx * p->raydirx)
		/ (p->raydiry * p->raydiry));
	p->hit = 0;
}

void	wall_hit_box(t_data *p)
{
	init_while(p);
	direction(p);
	wall_detection(p);
	if (p->side == 0)
		p->perpwalldist = (p->mapx - p->rayposx +
			((1 - p->stepx) >> 1)) / p->raydirx;
	else
		p->perpwalldist = (p->mapy - p->rayposy +
			((1 - p->stepy) >> 1)) / p->raydiry;
}
