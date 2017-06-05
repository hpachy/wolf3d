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

void	trollcat(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->trollcat_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_cat)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->trollcat_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_cat) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->trollcat_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_cat) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->trollcat_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_cat) + 3];
	}
	else
	{
		p->wall_tex.b = (p->trollcat_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_cat)];
		p->wall_tex.g = (p->trollcat_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_cat) + 1];
		p->wall_tex.r = (p->trollcat_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_cat) + 2];
		p->wall_tex.trans = (p->trollcat_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_cat) + 3];
	}
}

void	bedrock(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->bedrock_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_bedrock)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->bedrock_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_bedrock) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->bedrock_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_bedrock) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->bedrock_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_bedrock) + 3];
	}
	else
	{
		p->wall_tex.b = (p->bedrock_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_bedrock)];
		p->wall_tex.g = (p->bedrock_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_bedrock) + 1];
		p->wall_tex.r = (p->bedrock_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_bedrock) + 2];
		p->wall_tex.trans = (p->bedrock_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall_bedrock) + 3];
	}
}

void	youmad(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->youmad_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->youmad_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->youmad_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->youmad_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
	else
	{
		p->wall_tex.b = (p->youmad_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)];
		p->wall_tex.g = (p->youmad_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1];
		p->wall_tex.r = (p->youmad_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2];
		p->wall_tex.trans = (p->youmad_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
}

void	key2(t_data *p)
{
	if (p->perpwalldist > 1)
	{
		p->wall_tex.b = (unsigned char)(p->key2_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)] / (p->perpwalldist);
		p->wall_tex.g = (unsigned char)(p->key2_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1] / (p->perpwalldist);
		p->wall_tex.r = (unsigned char)(p->key2_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2] / (p->perpwalldist);
		p->wall_tex.trans = (p->key2_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
	else
	{
		p->wall_tex.b = (p->key2_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall)];
		p->wall_tex.g = (p->key2_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 1];
		p->wall_tex.r = (p->key2_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 2];
		p->wall_tex.trans = (p->key2_text)[(p->texx << 2)
			+ (p->texy * p->size_line_wall) + 3];
	}
}
