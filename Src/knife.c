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

void	animation_knife(t_data *p)
{
	static int n;

	if (p->touch.keycode49 == 0)
		mlx_put_image_to_window(p->mlx, p->win, p->knife1, 280, 705);
	else if (p->touch.keycode49 == 1 && n == 1)
		mlx_put_image_to_window(p->mlx, p->win, p->knife2, 280, 705);
	else if (p->touch.keycode49 == 1 && n == 2)
		mlx_put_image_to_window(p->mlx, p->win, p->knife2, 280, 705);
	else if (p->touch.keycode49 == 1 && n == 3)
		mlx_put_image_to_window(p->mlx, p->win, p->knife3, 330, 710);
	else if (p->touch.keycode49 == 1 && n == 4)
		mlx_put_image_to_window(p->mlx, p->win, p->knife3, 330, 710);
	else if (p->touch.keycode49 == 1 && n == 5)
		mlx_put_image_to_window(p->mlx, p->win, p->knife4, 370, 710);
	else if (p->touch.keycode49 == 1 && n == 6)
		mlx_put_image_to_window(p->mlx, p->win, p->knife4, 330, 710);
	else if (p->touch.keycode49 == 1 && n == 7)
		mlx_put_image_to_window(p->mlx, p->win, p->knife3, 330, 710);
	else if (p->touch.keycode49 == 1 && n == 8)
		mlx_put_image_to_window(p->mlx, p->win, p->knife3, 280, 705);
	else if (p->touch.keycode49 == 1 && n == 9)
		mlx_put_image_to_window(p->mlx, p->win, p->knife2, 330, 710);
	else if (p->touch.keycode49 == 1 && n == 10)
		mlx_put_image_to_window(p->mlx, p->win, p->knife2, 330, 710);
	(++n == 11) ? n = 0 : 0;
}

int		knife_texture(t_data *p)
{
	if ((p->knife1 = mlx_xpm_file_to_image(p->mlx,
					"texture_image/knife1.xpm", &p->width_knife1,
					&p->height_knife1)) == NULL)
		return (-1);
	if ((p->knife2 = mlx_xpm_file_to_image(p->mlx,
					"texture_image/knife2.xpm", &p->width_knife2,
					&p->height_knife2)) == NULL)
		return (-1);
	if ((p->knife3 = mlx_xpm_file_to_image(p->mlx,
					"texture_image/knife3.xpm", &p->width_knife3,
					&p->height_knife3)) == NULL)
		return (-1);
	if ((p->knife4 = mlx_xpm_file_to_image(p->mlx,
					"texture_image/knife4.xpm", &p->width_knife4,
					&p->height_knife4)) == NULL)
		return (-1);
	return (0);
}
