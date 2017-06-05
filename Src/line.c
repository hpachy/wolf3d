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

void	my_dx_sup(t_data data, t_test *testpos, t_board board)
{
	testpos->cumul = testpos->dx / 2.0;
	testpos->i = 1;
	while (testpos->i <= testpos->dx)
	{
		testpos->x += testpos->xinc;
		testpos->cumul += testpos->dy;
		if (testpos->cumul >= testpos->dx)
		{
			testpos->cumul -= testpos->dx;
			testpos->y += testpos->yinc;
		}
		light_on(testpos->x, testpos->y, data, board);
		testpos->i++;
	}
}

void	my_dx_inf(t_data data, t_test *testpos, t_board board)
{
	testpos->cumul = testpos->dy / 2.0;
	testpos->i = 1;
	while (testpos->i <= testpos->dy)
	{
		testpos->y += testpos->yinc;
		testpos->cumul += testpos->dx;
		if (testpos->cumul >= testpos->dy)
		{
			testpos->cumul -= testpos->dy;
			testpos->x += testpos->xinc;
		}
		light_on(testpos->x, testpos->y, data, board);
		testpos->i++;
	}
}

void	opti_line(t_data data, t_board board, t_board boardbis)
{
	t_test		testpos;

	testpos.x = (float)board.x;
	testpos.y = (float)board.y;
	testpos.dx = (float)boardbis.x - (float)board.x;
	testpos.dy = (float)boardbis.y - (float)board.y;
	testpos.xinc = (testpos.dx > 0.0) ? 1.0 : -1.0;
	testpos.yinc = (testpos.dy > 0.0) ? 1.0 : -1.0;
	testpos.dx = my_abs(testpos.dx);
	testpos.dy = my_abs(testpos.dy);
	light_on(testpos.x, testpos.y, data, board);
	if (testpos.dx > testpos.dy)
		my_dx_sup(data, &testpos, board);
	else
		my_dx_inf(data, &testpos, board);
}
