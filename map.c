/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:30:11 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/10/23 12:10:21 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		map_size(t_liste *head)
{
	int			n;
	double		size;
	t_tetro		*p;

	n = 1;
	p = head->head_tetro;
	while (p->next != NULL)
	{
		p = p->next;
		n++;
	}
	size = ft_sqrt(n * 4);
	if (size - (int)size != 0)
		size += 1;
	return (size);
}

t_map	*initialise_map(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(map->map = (char**)malloc(sizeof(*map) * map->size + 1)))
		return (NULL);
	while (x < map->size)
	{
		if (!(map->map[x] = ft_strnew(map->size)))
			return (NULL);
		while (y < map->size)
		{
			map->map[x][y] = '.';
			y++;
		}
		y = 0;
		x++;
	}
	map->map[map->size] = NULL;
	return (map);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->map[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (map->map[i])
	{
		ft_strdel(&map->map[i++]);
	}
	free(map->map);
}
