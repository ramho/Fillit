/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognise_tetro.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:09:37 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/10/23 11:57:58 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_position(t_tetro *temp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		temp->pos[i][0] = temp->coord[i][0] - temp->min[0];
		temp->pos[i][1] = temp->coord[i][1] - temp->min[1];
		i++;
	}
	return (1);
}

int		miny(char tab[4][4], t_tetro *temp)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[x][y] == '#')
			{
				temp->min[1] = y;
				return (get_position(temp));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		minx(char tab[4][4], t_tetro *temp)
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tab[x][y] == '#')
			{
				temp->min[0] = x;
				return (miny(tab, temp));
			}
			y++;
		}
		x++;
	}
	return (0);
}

int		get_coord(char tab[4][4], t_tetro *temp)
{
	int x;
	int y;
	int i;

	x = 0;
	i = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tab[x][y] == '#')
			{
				temp->coord[i][0] = x;
				temp->coord[i][1] = y;
				i++;
			}
			y++;
		}
		x++;
	}
	return (minx(tab, temp));
}

int		put_in_tab(char *single_tetro, t_tetro *temp)
{
	int		i;
	int		x;
	int		y;
	char	tab[4][4];

	i = 0;
	x = -1;
	y = 0;
	while (x++ < 3)
	{
		y = 0;
		while (y < 4)
		{
			tab[x][y] = single_tetro[i++];
			y++;
		}
		i++;
	}
	if (!(get_coord(tab, temp)))
		exit(0);
	return (1);
}
