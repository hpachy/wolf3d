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

void	detection(int x, int y, t_data *p)
{
	if (p->map[y][x].wall == 4)
		p->map[y][x].wall = 0;
	if (p->map[y][x].wall == 8)
	{
		p->map[y][x].wall = 0;
		p->nb_trollcat -= 1;
	}
	if (p->map[y][x].wall == 10)
	{
		p->map[y][x].wall = 2;
		p->int_key = 1;
	}
	if (p->map[y][x].wall == 9 && p->int_key == 1)
		p->map[y][x].wall = 0;
}
