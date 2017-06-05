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

void	grey_stone_wall(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->greystone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->greystone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->greystone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->greystone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
	else
	{
		p->wall_tex.b = (p->greystone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)];
		p->wall_tex.g = (p->greystone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1];
		p->wall_tex.r = (p->greystone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2];
		p->wall_tex.trans = (p->greystone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
}

void	eagle(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->eagle_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->eagle_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->eagle_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->eagle_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
	else
	{
		p->wall_tex.b = (p->eagle_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)];
		p->wall_tex.g = (p->eagle_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1];
		p->wall_tex.r = (p->eagle_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2];
		p->wall_tex.trans = (p->eagle_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
}

void	blue_stone(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->bluestone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->bluestone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->bluestone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->bluestone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
	else
	{
		p->wall_tex.b = (p->bluestone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)];
		p->wall_tex.g = (p->bluestone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1];
		p->wall_tex.r = (p->bluestone_text)[(p->texx << 2)
		+ (p->texy * p->size_line_wall) + 2];
		p->wall_tex.trans = (p->bluestone_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
}

void	barrel(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->barrel_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->barrel_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->barrel_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->barrel_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
	else
	{
		p->wall_tex.b = (p->barrel_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)];
		p->wall_tex.g = (p->barrel_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1];
		p->wall_tex.r = (p->barrel_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2];
		p->wall_tex.trans = (p->barrel_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
}

void	wall_brique(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->brique_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->brique_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->brique_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->barrel_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
	else
	{
		p->wall_tex.b = (p->brique_text)[(p->texx << 2)
		+ (p->texy * p->size_line_wall)];
		p->wall_tex.g = (p->brique_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1];
		p->wall_tex.r = (p->brique_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2];
		p->wall_tex.trans = (p->brique_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
}
