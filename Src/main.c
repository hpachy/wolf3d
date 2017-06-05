/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:35:42 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/30 12:56:15 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3D.h"
#include "libft.h"

int		mlx_fonction(t_data *p)
{
	if (!(p->mlx = mlx_init()))
		return (-1);
	if (!(p->win = mlx_new_window(p->mlx, p->x, p->y, "Wolf3D")))
		return (-1);
	if (!(p->img = mlx_new_image(p->mlx, p->x, p->y)))
		return (-1);
	if (!(p->picture = mlx_get_data_addr(p->img,
		&(p->bits), &(p->size_line), &(p->dian))))
		return (-1);
	return (0);
}

int		exit_win(void *param)
{
	t_data *p;

	p = ((t_data *)(param));
	mlx_destroy_image(p->mlx, p->img);
	mlx_destroy_window(p->mlx, p->win);
	exit(1);
	return (0);
}

int		game_mode(char *str, t_data *p)
{
	if ((p->definition_texture = ft_atoi(str)) > 2 ||
		(p->definition_texture = ft_atoi(str)) <= 0)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data		p;

	p.nb_trollcat = 0;
	p.int_key = 0;
	if (argc != 3)
		return (error_shell(1));
	p.x = 800;
	p.y = 800;
	if ((game_mode(argv[2], &p)) == -1)
		return (error_shell(5));
	if ((mlx_fonction(&p)) == -1)
		return (error_shell(4));
	ccinit(&p);
	if (((parsing(&p, argv[1])) == -1) || (parser_map(&p) == -1))
		return (error_shell(3));
	if (p.map[(int)p.posy][(int)p.posx].wall >= 1)
		p.map[(int)p.posy][(int)p.posx].wall = 0;
	if ((load_text(&p)) == -1)
		return (error_shell(2));
	mlx_hook(p.win, 17, 1, &exit_win, &p);
	mlx_hook(p.win, 3, 1L << 1, &key_release, &p);
	mlx_hook(p.win, 2, 1L << 2, &multi_touch_press, &p);
	mlx_loop_hook(p.mlx, &key_hook, &p);
	mlx_loop(p.mlx);
	return (0);
}
