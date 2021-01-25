/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:14:42 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/10/23 14:46:16 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_liste		*initialisation(char *single_tetro)
{
	t_liste *liste;
	t_tetro *tetro;

	if (!(liste = malloc(sizeof(*liste))) ||
			!(tetro = malloc(sizeof(*tetro))))
		return (NULL);
	tetro->lettre = 'A';
	put_in_tab(single_tetro, tetro);
	tetro->next = NULL;
	liste->head_tetro = tetro;
	return (liste);
}

int			insert_next(t_liste *liste, char *single_tetro, int i)
{
	t_tetro		*temp;
	t_tetro		*index;

	if (!(temp = malloc(sizeof(*temp))))
		return (0);
	temp->lettre = 'A' + (i / 21);
	put_in_tab(single_tetro, temp);
	temp->next = NULL;
	if (liste->head_tetro == NULL)
		liste->head_tetro = temp;
	else
	{
		index = liste->head_tetro;
		while (index->next != NULL)
			index = index->next;
		index->next = temp;
	}
	return (1);
}

void		suppression(t_liste **liste)
{
	t_tetro *temp;

	if (*liste == NULL)
		exit(0);
	while ((*liste)->head_tetro != NULL)
	{
		temp = (*liste)->head_tetro;
		(*liste)->head_tetro = (*liste)->head_tetro->next;
		free(temp);
	}
	free((*liste)->head_tetro);
	free(*liste);
	*liste = NULL;
}
