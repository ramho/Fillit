
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:14:42 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/09/24 16:33:49 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "read.h"
#include <stdio.h> //

t_liste		*initialisation(int forme)
{
	t_liste *liste;
	t_tetro *tetro;

	if(!(liste = malloc(sizeof(*liste))) || !(tetro = malloc(sizeof(*tetro))))
			return(NULL);
	tetro->type = forme; 
	tetro->lettre = 'A';
	tetro->next = NULL;
	liste->head_tetro = tetro;
	return (liste);	
}

void		insert_next(t_liste *liste, int type, int i)
{
	t_tetro 	*temp;
	t_tetro 	*index;
//	char		lettre;
	
	if(!(temp = malloc(sizeof(*temp))))
//		return(NULL);
		exit(EXIT_FAILURE);

	temp->type = type;
	temp->lettre = 'A'+ (i/21);
	temp->next = NULL;
	if(liste->head_tetro == NULL)
		liste->head_tetro = temp;
	else
	{
		index = liste->head_tetro;
		while (index->next!= NULL)
			index = index->next;
		index->next = temp;
	}
}

void 	afficherListe(t_liste *liste)
{
	t_tetro *index;

	if (liste == NULL)
        exit(EXIT_FAILURE);
 	index = liste->head_tetro;
    while (index != NULL)
    {
     //   printf("%d -> ", index->type);
       // printf("%c -> ", index->lettre);
	   printf("%c : %d --> ", index->lettre, index->type);
        index = index->next;
    }
    printf("NULL\n");
}
