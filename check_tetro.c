/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:39:05 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/10/23 14:46:37 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*last_n(char *str_tetra)
{
	int i;

	i = 0;
	while (str_tetra[i] != '\0')
		i++;
	if (!(str_tetra[i - 1] == '\n' &&
				(str_tetra[i - 2] == '.' || str_tetra[i - 2] == '#')))
		return (NULL);
	return (str_tetra);
}

int		check_connection(char *single_tetro)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (single_tetro[i] == '#')
		{
			if ((i + 1) < 20 && single_tetro[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && single_tetro[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && single_tetro[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && single_tetro[i - 5] == '#')
				block++;
		}
		i++;
	}
	if (block == 6 || block == 8)
		return (1);
	return (0);
}

int		check_char(char *single_tetro)
{
	int i;

	i = 0;
	while (single_tetro[i] != '\0')
	{
		if ((single_tetro[i] != '.' && single_tetro[i] != '#'
					&& single_tetro[i] != '\n'))
			return (0);
		i++;
	}
	return (check_connection(single_tetro));
}

int		count_char(char *single_tetro)
{
	int i;
	int count1;
	int count2;
	int count3;

	i = 0;
	count1 = 0;
	count2 = 0;
	count3 = 0;
	while (single_tetro[i] != '\0')
	{
		single_tetro[i] == '.' ? count1++ : count1;
		single_tetro[i] == '#' ? count2++ : count2;
		single_tetro[i] == '\n' ? count3++ : count3;
		i++;
	}
	if (count1 != 12 || count2 != 4 || count3 != 4)
		return (0);
	return (check_char(single_tetro));
}

int		check_tetro_char(char *single_tetro)
{
	if (single_tetro[4] != '\n' || single_tetro[9] != '\n'
			|| single_tetro[14] != '\n' || single_tetro[19] != '\n')
		return (0);
	if (!(count_char(single_tetro)))
		return (0);
	return (count_char(single_tetro));
}
