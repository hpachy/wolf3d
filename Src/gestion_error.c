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

int		checker_int(int y, int x, t_data *p)
{
	int		i;
	int		n;

	i = -1;
	while (++i != y)
	{
		n = -1;
		while (++n != x)
		{
			if (p->map[i][n].wall > 10 || p->map[i][n].wall < 0)
				return (-1);
		}
	}
	return (0);
}

int		border_map(int y, int x, t_data *p)
{
	int		a;

	a = -1;
	while (++a != x)
	{
		if (p->map[0][a].wall == 4 || p->map[0][a].wall > 10
			|| p->map[0][a].wall <= 0 || p->map[0][a].wall == 8)
			return (-1);
		if (p->map[y][a].wall == 4 || p->map[y][a].wall > 10
			|| p->map[y][a].wall <= 0 || p->map[y][a].wall == 8)
			return (-1);
	}
	a = -1;
	while (++a != y)
	{
		if (p->map[a][0].wall == 4 || p->map[a][0].wall > 10
			|| p->map[a][0].wall <= 0 || p->map[a][0].wall == 8)
			return (-1);
		if (p->map[a][x].wall == 4 || p->map[a][x].wall > 10
			|| p->map[a][x].wall <= 0 || p->map[a][x].wall == 8)
			return (-1);
	}
	return (0);
}

int		parser_map(t_data *p)
{
	if ((checker_int(p->index - 1, p->index_x - 1, p)) == -1)
		return (-1);
	if ((p->index_x - 1) > 30)
		return (-1);
	if ((p->index - 1) > 35)
		return (-1);
	if ((p->index_x - 1) < 5)
		return (-1);
	if ((p->index - 1) < 5)
		return (-1);
	if (border_map(p->index - 1, p->index_x - 1, p) == -1)
		return (-1);
	return (0);
}
