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

void	blue_orange(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->blue_orange_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->blue_orange_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->blue_orange_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->blue_orange_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 3];
	}
	else
	{
		p->wall_tex.b = (p->blue_orange_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd)];
		p->wall_tex.g = (p->blue_orange_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 1];
		p->wall_tex.r = (p->blue_orange_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 2];
		p->wall_tex.trans = (p->blue_orange_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 3];
	}
}

void	brown_key(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->key_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->key_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->key_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->key_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 3];
	}
	else
	{
		p->wall_tex.b = (p->key_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd)];
		p->wall_tex.g = (p->key_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 1];
		p->wall_tex.r = (p->key_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 2];
		p->wall_tex.trans = (p->key_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 3];
	}
}

void	brown(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->brown_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->brown_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->brown_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->brown_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 3];
	}
	else
	{
		p->wall_tex.b = (p->brown_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd)];
		p->wall_tex.g = (p->brown_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 1];
		p->wall_tex.r = (p->brown_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 2];
		p->wall_tex.trans = (p->brown_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 3];
	}
}

void	sol_metal(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->metal_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_metal)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->metal_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_metal) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->metal_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_metal) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->metal_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_metal) + 3];
	}
	else
	{
		p->wall_tex.b = (p->metal_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_metal)];
		p->wall_tex.g = (p->metal_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_metal) + 1];
		p->wall_tex.r = (p->metal_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_metal) + 2];
		p->wall_tex.trans = (p->metal_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_metal) + 3];
	}
}

void	door(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->door_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->door_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->door_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->door_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 3];
	}
	else
	{
		p->wall_tex.b = (p->door_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd)];
		p->wall_tex.g = (p->door_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 1];
		p->wall_tex.r = (p->door_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 2];
		p->wall_tex.trans = (p->door_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_hd) + 3];
	}
}
