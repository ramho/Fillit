/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:01:14 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/09/23 18:28:09 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"
# define TETRO 547 //taille maxi de 26 tetros

typedef struct 	s_liste
{
	struct	s_tetro		*head_tetro;
	int size;
}				t_liste;

typedef	struct	s_tetro
{
	int	type;
	char	lettre;
	struct s_tetro		*next;

}				t_tetro;

int		check_tetro1(char *str);
int		check_tetro2(char *str);
int 	check_tetro3(char *str);
char  	*cut_chain(char *str_tetra, char **single_tetro, int i);
int 	ft_read(int fd, char *str_tetra, t_liste *head);
t_tetro	*create_node(int type, char lettre);
t_liste	*initialisation(int forme);
void	insert_next(t_liste *first, int type, int i);
void	afficherListe(t_liste *liste);

#endif
