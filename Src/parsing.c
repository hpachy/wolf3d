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

int		checker_norm(char *tmp, t_data *p)
{
	int		index;

	index = -1;
	while (tmp[++index] != '\0')
	{
		if (tmp[index] == ' ')
		{
			if (tmp[index + 1] == '\n')
				return (-1);
		}
		else if (!((tmp[index] >= 48 && tmp[index] <= 57) || tmp[index] == 45
			|| tmp[index] == ' '))
			return (-1);
		if (tmp[index] == '8')
			p->nb_trollcat++;
	}
	free(tmp);
	return (0);
}

void	put_in(int i, char **tab, int y, t_data *p)
{
	int			x;
	int			n;

	x = 0;
	n = 0;
	while (n < i)
	{
		p->map[y][x].wall = ft_atoi(tab[n]);
		p->map[y][x].x = x;
		p->map[y][x].y = y;
		x++;
		n++;
	}
}

void	clear_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int		writer(t_list *list, t_data *data)
{
	char	**tab;
	int		i;
	int		y;

	y = 0;
	while (list)
	{
		i = 0;
		tab = ft_strsplit((char *)list->content, ' ');
		while (tab[i])
			i++;
		if (y > 0 && data->index_x != i)
			return (-1);
		data->index_x = i;
		if (!(data->map[y] = malloc(sizeof(t_board) * data->index_x)))
			return (-1);
		put_in(i, tab, y, data);
		++y;
		clear_tab(tab);
		free(list->content);
		list = list->next;
	}
	return (0);
}

int		parsing(t_data *p, char *map)
{
	t_list			*list;
	char			*line;
	int				ret;

	line = NULL;
	list = NULL;
	p->index = 0;
	if ((p->fd = open(map, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(p->fd, &line)) != 0)
	{
		if (ret == -1 && list == NULL)
			return (-1);
		ft_add_end(&list, ft_lstnew(line, (sizeof(char) * (ft_strlen(line)
		+ 1))));
		if ((checker_norm(line, p)) == -1)
			return (-1);
		p->index++;
	}
	if (!(p->map = malloc(sizeof(t_board) * p->index)))
		return (-1);
	if (writer(list, p) != 0)
		return (-1);
	free(list);
	return (0);
}
