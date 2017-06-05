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

void	print_wall_color_hd(t_data *p, int y)
{
	long	int	d;

	while (y < p->drawend)
	{
		p->wall_tex.y = y;
		d = (y << 8) - (p->y << 7) + (p->lineheight << 7);
		p->texy = ((d * p->height_wall_hd) / p->lineheight) >> 8;
		chose_texture_hd(p);
		light_on(p->wall_tex.x, p->wall_tex.y, *p, p->wall_tex);
		y++;
	}
}

void	print_wall_color(t_data *p, int y)
{
	long	int	d;

	while (y < p->drawend)
	{
		p->wall_tex.y = y;
		d = (y << 8) - (p->y << 7) + (p->lineheight << 7);
		p->texy = ((d * p->height_wall) / p->lineheight) >> 8;
		chose_texture(p);
		light_on(p->wall_tex.x, p->wall_tex.y, *p, p->wall_tex);
		light_on(p->wall_tex.x, p->wall_tex.y, *p, p->wall_tex);
		y++;
	}
}
