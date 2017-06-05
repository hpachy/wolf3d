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

int		load_text4(t_data *p)
{
	if ((p->youmad = mlx_xpm_file_to_image(p->mlx,
		"texture_image/youmad.xpm", &p->width_wall_youmad,
		&p->height_wall_youmad)) == NULL)
		return (-1);
	if ((p->youmad_text = mlx_get_data_addr(p->youmad,
		&(p->bits_wall_youmad), &(p->size_line_wall_youmad),
		&(p->dian_wall_youmad))) == NULL)
		return (-1);
	if ((p->bedrock = mlx_xpm_file_to_image(p->mlx,
		"texture_image/bedrock.xpm", &p->width_wall_bedrock,
		&p->height_wall_bedrock)) == NULL)
		return (-1);
	if ((p->bedrock_text = mlx_get_data_addr(p->bedrock,
		&(p->bits_wall_bedrock), &(p->size_line_wall_bedrock),
		&(p->dian_wall_bedrock))) == NULL)
		return (-1);
	if ((p->key2 = mlx_xpm_file_to_image(p->mlx,
		"texture_image/key2.xpm", &p->width_wall,
		&p->height_wall)) == NULL)
		return (-1);
	if ((p->key2_text = mlx_get_data_addr(p->key2,
		&(p->bits_wall), &(p->size_line_wall), &(p->dian_wall))) == NULL)
		return (-1);
	return (0);
}

int		load_text3(t_data *p)
{
	if ((p->bluestone = mlx_xpm_file_to_image(p->mlx,
		"texture_image/bluestone.xpm", &p->width_wall,
		&p->height_wall)) == NULL)
		return (-1);
	if ((p->bluestone_text = mlx_get_data_addr(p->bluestone,
		&(p->bits_wall), &(p->size_line_wall), &(p->dian_wall))) == NULL)
		return (-1);
	if ((p->brique = mlx_xpm_file_to_image(p->mlx,
		"texture_image/mur_brique.xpm", &p->width_wall,
		&p->height_wall)) == NULL)
		return (-1);
	if ((p->brique_text = mlx_get_data_addr(p->brique, &(p->bits_wall),
		&(p->size_line_wall), &(p->dian_wall))) == NULL)
		return (-1);
	if ((p->trollcat = mlx_xpm_file_to_image(p->mlx,
		"texture_image/trollcat.xpm", &p->width_wall_cat,
		&p->height_wall_cat)) == NULL)
		return (-1);
	if ((p->trollcat_text = mlx_get_data_addr(p->trollcat,
		&(p->bits_wall_cat), &(p->size_line_wall_cat),
		&(p->dian_wall_cat))) == NULL)
		return (-1);
	if (load_text4(p))
		return (-1);
	return (0);
}

int		load_text2(t_data *p)
{
	if ((p->wood = mlx_xpm_file_to_image(p->mlx,
		"texture_image/wood.xpm", &p->width_wall, &p->height_wall)) == NULL)
		return (-1);
	if ((p->wood_text = mlx_get_data_addr(p->wood, &(p->bits_wall),
		&(p->size_line_wall), &(p->dian_wall))) == NULL)
		return (-1);
	if ((p->barrel = mlx_xpm_file_to_image(p->mlx,
		"texture_image/barrel.xpm", &p->width_wall, &p->height_wall)) == NULL)
		return (-1);
	if ((p->barrel_text = mlx_get_data_addr(p->barrel, &(p->bits_wall),
		&(p->size_line_wall), &(p->dian_wall))) == NULL)
		return (-1);
	if ((p->eagle = mlx_xpm_file_to_image(p->mlx, "texture_image/eagle.xpm",
		&p->width_wall, &p->height_wall)) == NULL)
		return (-1);
	if ((p->eagle_text = mlx_get_data_addr(p->eagle, &(p->bits_wall),
		&(p->size_line_wall), &(p->dian_wall))) == NULL)
		return (-1);
	if (load_text3(p))
		return (-1);
	return (0);
}

int		load_text1(t_data *p)
{
	if ((p->sky = mlx_xpm_file_to_image(p->mlx,
		"texture_image/brouillard_nuit.xpm", &p->width, &p->height)) == NULL)
		return (-1);
	if ((p->fin = mlx_xpm_file_to_image(p->mlx,
		"texture_image/ecran_fin.xpm", &p->width, &p->height)) == NULL)
		return (-1);
	if ((p->greystone = mlx_xpm_file_to_image(p->mlx,
		"texture_image/greystone.xpm",
		&p->width_wall, &p->height_wall)) == NULL)
		return (-1);
	if ((p->greystone_text = mlx_get_data_addr(p->greystone,
		&(p->bits_wall), &(p->size_line_wall), &(p->dian_wall))) == NULL)
		return (-1);
	if (load_text2(p))
		return (-1);
	return (0);
}

int		load_text(t_data *p)
{
	write(1, "\ntexture loading so please wait!\n", 33);
	if ((load_text1(p)) == -1)
		return (-1);
	if ((load_hd_text(p)) == -1)
		return (-1);
	write(1, "\nHAVE FUN!!!\n", 13);
	return (0);
}
