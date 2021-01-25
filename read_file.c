/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:43:39 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/10/23 14:11:29 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_fd(int fd, char **str_tetra)
{
	if (!(*str_tetra = ft_strnew(TETRO + 1)))
		return (0);
	if ((read(fd, *str_tetra, TETRO + 1) > TETRO))
	{
		ft_strdel(&*str_tetra);
		return (0);
	}
	return (1);
}

int		free_str_tetro(char *str_tetra, char *single_tetro)
{
	ft_strdel(&str_tetra);
	ft_strdel(&single_tetro);
	return (0);
}

int		cut_chain(char *str_tetra, char **single_tetro, int i)
{
	if (str_tetra == NULL)
		return (0);
	if (!(*single_tetro = ft_strsub(str_tetra, i, 20)))
		return (0);
	return (1);
}

int		put_in_struct(t_liste **head, char *str_tetra)
{
	int		i;
	char	*single_tetro;

	single_tetro = NULL;
	if (!(cut_chain(last_n(str_tetra), &single_tetro, 0)))
		return (free_str_tetro(str_tetra, single_tetro));
	if (!(check_tetro_char(single_tetro)))
		return (free_str_tetro(str_tetra, single_tetro));
	*head = initialisation(single_tetro);
	ft_strdel(&single_tetro);
	i = 21;
	while (str_tetra[i] != '\0')
	{
		if (!(cut_chain(str_tetra, &single_tetro, i)))
			return (free_str_tetro(str_tetra, single_tetro));
		if (!(check_tetro_char(single_tetro)))
			return (free_str_tetro(str_tetra, single_tetro));
		insert_next(*head, single_tetro, i);
		i += 21;
		ft_strdel(&single_tetro);
	}
	ft_strdel(&str_tetra);
	return (1);
}
