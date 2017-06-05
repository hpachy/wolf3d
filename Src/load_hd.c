/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:35:42 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/19 16:53:26 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3D.h"
#include "libft.h"

int		load_hd_text4(t_data *p)
{
	if ((p->lotus = mlx_xpm_file_to_image(p->mlx,
					"texture_image/lotus.xpm", &p->width_wall_hd,
					&p->height_wall_hd)) == NULL)
		return (-1);
	if ((p->lotus_text = mlx_get_data_addr(p->lotus,
					&(p->bits_wall_hd), &(p->size_line_wall_hd),
					&(p->dian_wall_hd))) == NULL)
		return (-1);
	if ((p->key = mlx_xpm_file_to_image(p->mlx,
					"texture_image/key_hd.xpm", &p->width_wall_hd,
					&p->height_wall_hd)) == NULL)
		return (-1);
	if ((p->key_text = mlx_get_data_addr(p->key,
					&(p->bits_wall_hd), &(p->size_line_wall_hd),
					&(p->dian_wall_hd))) == NULL)
		return (-1);
	if ((p->door_text = mlx_get_data_addr(p->door,
					&(p->bits_wall_hd), &(p->size_line_wall_hd),
					&(p->dian_wall_hd))) == NULL)
		return (-1);
	return (0);
}

int		load_hd_text3(t_data *p)
{
	if ((p->brown = mlx_xpm_file_to_image(p->mlx,
					"texture_image/brown.xpm", &p->width_wall_hd,
					&p->height_wall_hd)) == NULL)
		return (-1);
	if ((p->brown_text = mlx_get_data_addr(p->brown, &(p->bits_wall_hd),
					&(p->size_line_wall_hd), &(p->dian_wall_hd))) == NULL)
		return (-1);
	if ((p->metal = mlx_xpm_file_to_image(p->mlx,
					"texture_image/sol_metal.xpm", &p->width_wall_metal,
					&p->height_wall_metal)) == NULL)
		return (-1);
	if ((p->metal_text = mlx_get_data_addr(p->metal, &(p->bits_wall_metal),
					&(p->size_line_wall_metal), &(p->dian_wall_metal))) == NULL)
		return (-1);
	if ((load_hd_text4(p)) == -1)
		return (-1);
	return (0);
}

int		load_hd_text2(t_data *p)
{
	if ((p->blue = mlx_xpm_file_to_image(p->mlx,
					"texture_image/blue.xpm", &p->width_wall_hd,
					&p->height_wall_hd)) == NULL)
		return (-1);
	if ((p->blue_text = mlx_get_data_addr(p->blue, &(p->bits_wall_hd),
					&(p->size_line_wall_hd), &(p->dian_wall_hd))) == NULL)
		return (-1);
	if ((p->green = mlx_xpm_file_to_image(p->mlx, "texture_image/green.xpm",
					&p->width_wall_hd, &p->height_wall_hd)) == NULL)
		return (-1);
	if ((p->green_text = mlx_get_data_addr(p->green, &(p->bits_wall_hd),
					&(p->size_line_wall_hd), &(p->dian_wall_hd))) == NULL)
		return (-1);
	if ((p->bush = mlx_xpm_file_to_image(p->mlx, "texture_image/bush.xpm",
					&p->width_wall_hd, &p->height_wall_hd)) == NULL)
		return (-1);
	if ((p->bush_text = mlx_get_data_addr(p->bush, &(p->bits_wall_hd),
					&(p->size_line_wall_hd), &(p->dian_wall_hd))) == NULL)
		return (-1);
	if ((load_hd_text3(p)) == -1)
		return (-1);
	return (0);
}

int		load_hd_text1(t_data *p)
{
	if ((p->blue_orange = mlx_xpm_file_to_image(p->mlx,
		"texture_image/blue_orange.xpm",
		&p->width_hd, &p->height_hd)) == NULL)
		return (-1);
	if ((p->blue_orange_text = mlx_get_data_addr(p->blue_orange,
					&(p->bits_wall_hd), &(p->size_line_wall_hd),
					&(p->dian_wall_hd))) == NULL)
		return (-1);
	if ((p->cat = mlx_xpm_file_to_image(p->mlx,
					"texture_image/troll_cat_hd.xpm",
					&p->width_hd, &p->height_hd)) == NULL)
		return (-1);
	if ((p->cat_text = mlx_get_data_addr(p->cat,
					&(p->bits_wall_hd), &(p->size_line_wall_hd),
					&(p->dian_wall_hd))) == NULL)
		return (-1);
	if ((p->door = mlx_xpm_file_to_image(p->mlx,
		"texture_image/door.xpm", &p->width_hd, &p->height_hd)) == NULL)
		return (-1);
	if ((load_hd_text2(p)) == -1)
		return (-1);
	return (0);
}

int		load_hd_text(t_data *p)
{
	if (load_hd_text1(p) == -1)
		return (-1);
	if (knife_texture(p) == -1)
		return (-1);
	return (0);
}
