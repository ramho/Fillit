/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:52:24 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/07/17 17:18:44 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // remove \\
#include "read.h"


//read 20 bit to check if valid shape
int		cut_chain(char	*str_tetra, char *single_tetro)
{
	int i = 0;
	char	*temp = NULL;
	single_tetro = ft_strnew(1);
	while (str_tetra)
	{
		single_tetro == (ft_strndup(str_tetra[i],20));

		return(single_tetro);
		i += 20;	
	}
}



// check if the tetro are only ., #, \n

int		ft_read(int fd, char *str_tetra)
{
	int i = 0;
	int ret = 0;
	int single_tetro;

	str_tetra = ft_strnew(TETRO);

	if((ret = read(fd, str_tetra, TETRO)) > 546)
		return (-1);
	while (str_tetra[i] != '\0')
	{
	   	if(str_tetra[i] != '.' && str_tetra[i] != '#' && str_tetra[i] != '\n')
			return (-2);
		i++;
	}
	while ((single_tetro = ft_check_tetro(cut_chain(str_tetra, single tetro) != 0))
		return (single_tetro);
	return (0);
}

//open fd

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char *str_tetra = NULL;
	int single_tetro = 0;
	t_tetro	tetro;

	if (ac != 2)
		write( 1, "usage: fillit source_file\n", 26);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ret = ft_read(fd, str_tetra);
		if (ret != 1)
			printf("error car ret = %d\n", ret);
		while ( ret > 0)
		{
			tetro.type = ft_read(str_tetra);
			// struct start

			// printf("\n%s\n", ???)
		}
	return (0);
}

