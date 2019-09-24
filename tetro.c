/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:36:52 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/09/05 17:37:48 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

int		check_tetro3(char *str)
{
	int i = -1;

	while (str[++i] != '\0')
	{
		if (str[i] == '#' && (str[i + 4] == '#') && (str[i + 5] == '#')
			&& (str[i + 9] == '#'))
			return (14);// zdebout
		if (str[i] == '#' && (str[i + 1] == '#') && (str[i + 6] == '#')
			&& (str[i + 7] == '#'))
			return (15);// zcouche
		if (str[i] == '#' && (str[i + 4] == '#') && (str[i + 5] == '#')
			&& (str[i + 6] == '#'))
			return (16);// t1
		if (str[i] == '#' && (str[i + 4] == '#') && (str[i + 5] == '#')
			&& (str[i + 10] == '#'))
			return (17);// t2
		if (str[i] == '#' && (str[i + 5] == '#') && (str[i + 6] == '#')
			&& (str[i + 10] == '#'))
			return (18);// t3
		if (str[i] == '#' && (str[i + 1] == '#') && (str[i + 2] == '#')
			&& (str[i + 6] == '#'))
			return (19);// t4
	}
	return (0);
}

int		check_tetro2(char *str)
{
	int i = -1;

	while (str[++i] != '\0')
	{
		if (str[i] == '#' && (str[i + 1] == '#') && (str[i + 2] == '#')
			&& (str[i + 5] == '#'))
			return (8);// lg3
		if (str[i] == '#' && (str[i + 3] == '#') && (str[i + 4] == '#')
			&& (str[i + 5] == '#'))
			return (9);// lg4
		if (str[i] == '#' && (str[i + 1] == '#') && (str[i + 5] == '#')
			&& (str[i + 10] == '#'))
			return (10);// ld1
		if (str[i] == '#' && (str[i + 5] == '#') && (str[i + 9] == '#')
			&& (str[i + 10] == '#'))
			return (11);// ld2
		if (str[i] == '#' && (str[i + 5] == '#') && (str[i + 6] == '#')
			&& (str[i + 7] == '#'))
			return (12);// ld3
		if (str[i] == '#' && (str[i + 1] == '#') && (str[i + 2] == '#')
			&& (str[i + 7] == '#'))
			return (13);// ld4
	}
	return (check_tetro3(str));
}

int		check_tetro1(char *str)
{
	int	i = -1;

	if (str == NULL)
		return (0);

	while (str[++i] != '\0')
	{
		if (str[i] == '#' && (str[i + 1] == '#') && (str[i + 2]) == '#'
			&& (str[i + 3] == '#'))
			return (1);// ligne couche
		if (str[i] == '#' && (str[i + 5] == '#') && (str[i + 10] == '#')
			&& (str[i + 15] == '#'))
			return (2);// ligne droite
		if (str[i] == '#' && (str[i + 1] == '#') && (str[i + 5] == '#')
			&& (str[i + 6] == '#'))
			return (3);//carre
		if (str[i] == '#' && (str[i + 5] == '#') && (str[i + 6] == '#')
			&& (str[i + 11] == '#'))
			return (4);// quatre debout
		if (str[i] == '#' && (str[i + 1] == '#') && (str[i + 4] == '#')
			&& (str[i + 5] == '#'))
			return (5);// quatre couche
		if (str[i] == '#' && (str[i + 5] == '#') && (str[i + 10] == '#')
			&& (str[i + 11] == '#'))
			return (6);// lg1
		if (str[i] == '#' && (str[i + 1] == '#') && (str[i + 6] == '#')
			&& (str[i + 11] == '#'))
			return (7);// lg2
	}
	return (check_tetro2(str));
}
