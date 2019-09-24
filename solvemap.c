/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:14:46 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/09/15 17:47:17 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

char	**printmap(char **map, int count)

int		can_place(int t_tetro->type)
{
	if
}

char	*place_head(t_liste)
{
	return(map);
}
char		*place_piece(t_tetro)
{
	return(map);
}

int		check_if_valid(char **map)
{
	//
}
int add_tetro_to_map()
{
	int pos;

	while(i->next != NULL)
	{
		if(!(can_place(i)))
			pos++;
		map = place_piece(i);
		if((solve(map, liste, i++))
			return(1);
	}
	return (-1);
}

int		solve(char **map, t_liste liste, t_tetro i)
{
	printmap(char **map, liste->size)
	map = place_head(map,head);
	if(!(add_tetro_to_map(map))
	{
		free(map);
		printmap(char **map, liste->size + 1);
		map = place_head(map,head)
	return(1);

}

int main()
{
	if(solvemap(map, head));
		ft_putstr(map);
	else
		ft_putstr("error");
	return(0);
}
