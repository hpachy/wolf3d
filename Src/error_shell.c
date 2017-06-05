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

int		error_bis(int error)
{
	if (error == 3)
	{
		write(1, "\n(>_<) AIE!!! ", 14);
		write(1, "==> your map is false <==\n\n", 27);
		write(1, "\n\n==> or you trying to crash my game <==\n\n", 42);
	}
	if (error == 4)
	{
		write(1, "\n\n(>_<) AIE!!! ", 15);
		write(1, "==> MLX FAILED!!!! <==\n\n", 22);
	}
	if (error == 5)
	{
		write(1, "\n\n(>_<) AIE!!! ", 15);
		write(1, "==> mode false !! <==\n\n", 23);
	}
	return (1);
}

int		error_shell(int error)
{
	if (error == 1)
	{
		write(1, "\n\n(>_<) AIE!!! ", 15);
		write(1, "==> wrong numbers of arguments <==\n\n", 36);
		write(1, "==> first: your executable ;", 28);
		write(1, " second : your map.txt and after is ", 36);
		write(1, " '1'(basic mode) or '2'(HD mode) ;\n", 35);
		write(1, "\n\n", 2);
		write(1, "\n================================================\n", 50);
		write(1, "\n ↑, ↓ : to move ; →, ← : to rotate", 43);
		write(1, "\nspace to cut bush or barrel\n\n", 30);
		write(1, "================================================\n\n", 50);
	}
	if (error == 2)
	{
		write(1, "\n\n(>_<) AIE!!! ", 15);
		write(1, "==> LOAD TEXTURE FAILED!!!! <==\n\n", 33);
		write(1, "==> or you trying to crash my texture game ! <==\n\n", 50);
	}
	error_bis(error);
	return (1);
}
