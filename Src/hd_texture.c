/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:35:42 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/30 12:57:55 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3D.h"
#include "libft.h"

void	blue(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->blue_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->blue_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->blue_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->blue_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 3];
	}
	else
	{
		p->wall_tex.b = (p->blue_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd)];
		p->wall_tex.g = (p->blue_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 1];
		p->wall_tex.r = (p->blue_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 2];
		p->wall_tex.trans = (p->blue_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 3];
	}
}

void	green(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->green_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->green_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->green_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->green_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 3];
	}
	else
	{
		p->wall_tex.b = (p->green_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd)];
		p->wall_tex.g = (p->green_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 1];
		p->wall_tex.r = (p->green_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 2];
		p->wall_tex.trans = (p->green_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 3];
	}
}

void	troll_cat_hd(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->cat_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->cat_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->cat_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->cat_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 3];
	}
	else
	{
		p->wall_tex.b = (p->cat_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd)];
		p->wall_tex.g = (p->cat_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 1];
		p->wall_tex.r = (p->cat_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 2];
		p->wall_tex.trans = (p->cat_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 3];
	}
}

void	bush(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->bush_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->bush_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->bush_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->bush_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 3];
	}
	else
	{
		p->wall_tex.b = (p->bush_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd)];
		p->wall_tex.g = (p->bush_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 1];
		p->wall_tex.r = (p->bush_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 2];
		p->wall_tex.trans = (p->bush_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 3];
	}
}

void	lotus(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->lotus_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->lotus_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->lotus_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->lotus_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 3];
	}
	else
	{
		p->wall_tex.b = (p->lotus_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd)];
		p->wall_tex.g = (p->lotus_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 1];
		p->wall_tex.r = (p->lotus_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 2];
		p->wall_tex.trans = (p->lotus_text)[(p->texx << 2) +
			(p->texy * p->size_line_wall_hd) + 3];
	}
}
