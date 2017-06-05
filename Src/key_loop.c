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

static	void	key_release2(int keycode, void *param)
{
	t_data *p;

	p = ((t_data *)(param));
	if (keycode == 49 && p->touch.keycode124 == 0)
		p->touch.keycode49 = 0;
	if (keycode == 53)
		p->touch.keycode53 = 0;
}

int				key_release(int keycode, void *param)
{
	t_data *p;

	p = ((t_data *)(param));
	if (keycode == 124)
		p->touch.keycode124 = 0;
	if (keycode == 123)
		p->touch.keycode123 = 0;
	if (keycode == 125)
		p->touch.keycode125 = 0;
	if (keycode == 126)
		p->touch.keycode126 = 0;
	key_release2(keycode, param);
	return (0);
}

static	void	multi_touch_press2(int keycode, void *param)
{
	t_data *p;

	p = ((t_data *)(param));
	if (keycode == 49 && p->touch.keycode124 == 0)
		p->touch.keycode49 = 1;
	if (keycode == 53)
		p->touch.keycode53 = 1;
}

int				multi_touch_press(int keycode, void *param)
{
	t_data *p;

	p = ((t_data *)(param));
	if (keycode == 124)
		p->touch.keycode124 = 1;
	if (keycode == 123)
		p->touch.keycode123 = 1;
	if (keycode == 125)
		p->touch.keycode125 = 1;
	if (keycode == 126)
		p->touch.keycode126 = 1;
	multi_touch_press2(keycode, param);
	return (0);
}
