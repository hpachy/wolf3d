/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:35:42 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/30 12:56:36 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Wolf3D.h"
#include "../libft/libft.h"
#include <math.h>

void			ccinit(t_data *p)
{
	p->posx = 2.5;
	p->posy = 1.5;
	p->dirx = -1;
	p->diry = 0;
	p->planex = 0;
	p->planey = 0.66;
	p->time = 0;
	p->oldtime = 0;
	p->index = 0;
}

int				end(void)
{
	sleep(10);
	exit(0);
	return (0);
}

static	void	rotation(double rotspeed, t_data *p)
{
	double		olddirx;
	double		oldplanex;

	if (p->touch.keycode123 == 1)
	{
		olddirx = p->dirx;
		p->dirx = p->dirx * cos(rotspeed) - p->diry * sin(rotspeed);
		p->diry = olddirx * sin(rotspeed) + p->diry * cos(rotspeed);
		oldplanex = p->planex;
		p->planex = p->planex * cos(rotspeed) - p->planey * sin(rotspeed);
		p->planey = oldplanex * sin(rotspeed) + p->planey * cos(rotspeed);
	}
	if (p->touch.keycode124 == 1)
	{
		olddirx = p->dirx;
		p->dirx = p->dirx * cos(-rotspeed) - p->diry * sin(-rotspeed);
		p->diry = olddirx * sin(-rotspeed) + p->diry * cos(-rotspeed);
		oldplanex = p->planex;
		p->planex = p->planex * cos(-rotspeed) - p->planey * sin(-rotspeed);
		p->planey = oldplanex * sin(-rotspeed) + p->planey * cos(-rotspeed);
	}
}

static	void	deplacement(double ms, t_data *p)
{
	if ((p->nb_trollcat) == 0)
	{
		mlx_loop_hook(p->mlx, &end, p);
		mlx_put_image_to_window(p->mlx, p->win, p->fin, 0, 0);
		mlx_string_put(p->mlx, p->win, 150, 50, 255255255,
			"WP BILLY!!! you finished the game so grade me now ;)");
		mlx_loop(p->mlx);
	}
	if (p->touch.keycode126 == 1)
	{
		if (p->map[(int)(p->posy)][(int)(p->posx + p->dirx * ms * 3)].wall == 0)
			p->posx += p->dirx * ms;
		if (p->map[(int)(p->posy + p->diry * ms * 3)][(int)(p->posx)].wall == 0)
			p->posy += p->diry * ms;
	}
	if (p->touch.keycode125 == 1)
	{
		if (p->map[(int)(p->posy)][(int)(p->posx - p->dirx * ms * 3)].wall == 0)
			p->posx -= p->dirx * ms;
		if (p->map[(int)(p->posy - p->diry * ms * 3)][(int)(p->posx)].wall == 0)
			p->posy -= p->diry * ms;
	}
}

int				key_hook(t_data *p)
{
	double		movespeed;
	double		rotspeed;

	rotspeed = 0.2;
	movespeed = 0.2;
	deplacement(movespeed, p);
	rotation(rotspeed, p);
	if (p->touch.keycode53 == 1)
		exit(1);
	if (p->touch.keycode49 > 0)
		detection(p->wall_pos_x, p->wall_pos_y, p);
	ray_casting(p);
	mlx_put_image_to_window(p->mlx, p->win, p->sky, 0, 0);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	animation_knife(p);
	mlx_string_put(p->mlx, p->win, 400, 400, 255255255, "+");
	mlx_do_key_autorepeaton(p->mlx);
	return (0);
}
