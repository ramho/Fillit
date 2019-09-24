
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:52:24 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/09/24 16:29:40 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // remove 
#include "read.h"

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
	printf(". :%d, # :%d, \\n :%d\n", count1, count2, count3);
	if (count1 == 12  && count2 == 4 && count3 == 4)	
		return (1);
	return (-1);
}

//read 20 bit to check if valid shape
char		*cut_chain(char	*str_tetra, char **single_tetro, int i)
{
	int ret = 0;

	if (!(*single_tetro = ft_strsub(str_tetra, i, 20)))
	{
		return (NULL);
	}
	if (single_tetro[0][4] != '\n' || single_tetro[0][9] != '\n' || single_tetro[0][14] != '\n' || single_tetro[0][19] != '\n')
		return (NULL);
	if (!(ret = count_char(*single_tetro)))
	{	
		printf("ret: %d\n", ret);
		return (NULL);
	}
	return(*single_tetro);	
}

// check if the tetro are only ., #, \n, check if ret - 1 = \n 11 ret -2 = . ou #

int		ft_read(int fd, char *str_tetra, t_liste **head)
{
	int i = 0;
	char *single_tetro;
	int ret;

	if(!(str_tetra = ft_strnew(TETRO)))
		return (-1); //free
	if(read(fd, str_tetra, TETRO) > 545)
		return (-2);
	while (str_tetra[i] != '\0')
	{
		if(str_tetra[i] != '.' && str_tetra[i] != '#' && str_tetra[i] != '\n') // free
			return (-3);
		i++;
	}
	if (str_tetra[i] == '#')//
		return (-4);//
	i = 0;
	*head = initialisation(check_tetro1(cut_chain(str_tetra, &single_tetro, i)));
	i = 21;
	while ((ret = (check_tetro1(cut_chain(str_tetra, &single_tetro, i)))) != 0)
	{
		insert_next(*head,ret, i);
		i += 21;
	}
//	afficherListe(head);

	return (1);
}

int		main(int ac, char **av)
{
	int fd;
	int ret;
	static char *str_tetra = NULL;
	t_liste *head;
	char **map;

	if (ac != 2)
		write( 1, "usage: fillit source_file\n", 26);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ret = ft_read(fd, str_tetra, &head);
		afficherListe(head);
		map = initialise_map(head); // gcsize so can increment later
	}	
	return (0);
}

