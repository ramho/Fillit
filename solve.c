/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:08:17 by imanoka-          #+#    #+#             */
/*   Updated: 2019/10/23 14:14:39 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_place(t_tetro *tetro, t_map *map, int x, int y)
{
	int i;
	int a;
	int b;

	if (map->map[x][y] == '.')
	{
		i = 0;
		if (tetro->pos[0][0] == 0 && tetro->pos[0][1] == 1)
			y = y - 1;
		if (tetro->pos[0][0] == 0 && tetro->pos[0][1] == 2)
			y = y - 2;
		while (i < 4)
		{
			a = 0;
			b = 0;
			a = x + tetro->pos[i][0];
			b = y + tetro->pos[i][1];
			if (!(a <= map->size - 1 && b <= map->size - 1
						&& map->map[a][b] == '.'))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	set_piece(t_map *map, t_tetro *tetro, int x, int y)
{
	int i;
	int a;
	int b;

	i = 0;
	if (tetro->pos[0][0] == 0 && tetro->pos[0][1] == 1)
		y = y - 1;
	if (tetro->pos[0][0] == 0 && tetro->pos[0][1] == 2)
		y = y - 2;
	while (i < 4)
	{
		a = 0;
		b = 0;
		a = x + tetro->pos[i][0];
		b = y + tetro->pos[i][1];
		if (a < x)
			a = a - 1;
		map->map[a][b] = tetro->lettre;
		i++;
	}
}

void	set_piece_bis(t_map *map, t_tetro *tetro, int x, int y)
{
	int i;
	int a;
	int b;

	i = 0;
	if (tetro->pos[0][0] == 0 && tetro->pos[0][1] == 1)
		y = y - 1;
	if (tetro->pos[0][0] == 0 && tetro->pos[0][1] == 2)
		y = y - 2;
	while (i < 4)
	{
		a = 0;
		b = 0;
		a = x + tetro->pos[i][0];
		b = y + tetro->pos[i][1];
		if (a < x)
			a = a - 1;
		map->map[a][b] = '.';
		i++;
	}
}

int		solve_map(t_map *map, t_tetro *tetro)
{
	int x;
	int y;

	x = -1;
	while (++x < map->size)
	{
		y = -1;
		while (++y < map->size)
		{
			if (find_place(tetro, map, x, y))
			{
				set_piece(map, tetro, x, y);
				if (tetro->next != NULL)
				{
					if (solve_map(map, tetro->next) == 0)
						set_piece_bis(map, tetro, x, y);
					else
						return (1);
				}
				else
					return (1);
			}
		}
	}
	return (0);
}

void	solve(t_liste *head)
{
	t_map		*map;
	t_tetro		*tetro;

	if (!(map = malloc(sizeof(*map))))
		exit(0);
	tetro = head->head_tetro;
	map->size = map_size(head);
	map = initialise_map(map);
	while (!solve_map(map, tetro))
	{
		map->size++;
		free_map(map);
		map = initialise_map(map);
	}
	print_map(map);
	free_map(map);
	free(map);
}
