/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:35:42 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/08 17:35:27 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3D.h"
#include "libft.h"

double	my_abs(double a)
{
	if (a < 0)
		a = -a;
	return (a);
}

void	color_back_ground(t_data data)
{
	int		up;
	int		count;

	count = (data.x * data.y) << 2;
	up = 0;
	while (up != count)
	{
		data.picture[up] = 0;
		data.picture[up + 1] = 255;
		data.picture[up + 2] = 0;
		data.picture[up + 3] = 0;
		up = up + 4;
	}
}

void	light_on(int x, int y, t_data p, t_board board)
{
	if ((x >= 0 && x < p.x) && (y >= 0 && y < p.y))
	{
		(p.picture)[(x << 2) + (y * p.size_line)] = board.b;
		(p.picture)[(x << 2) + (y * p.size_line) + 1] = board.g;
		(p.picture)[(x << 2) + (y * p.size_line) + 2] = board.r;
		(p.picture)[(x << 2) + (y * p.size_line) + 3] = board.trans;
	}
}
