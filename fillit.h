/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:01:14 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/10/23 14:06:26 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"
# define TETRO 545

typedef struct			s_liste
{
	struct s_tetro		*head_tetro;
}						t_liste;

typedef	struct			s_tetro
{
	int					coord[4][2];
	int					min[2];
	int					pos[4][2];
	char				lettre;
	struct s_tetro		*next;
}						t_tetro;

typedef struct			s_map
{
	int					size;
	char				**map;
}						t_map;

int						cut_chain(char *str_tetra, char **single_tetro, int i);
int						read_fd(int fd, char **str_tetra);
int						put_in_struct(t_liste **head, char *str_tetra);
t_tetro					*create_node(int type, char lettre);
t_liste					*initialisation(char *single_tetro);
int						insert_next(t_liste *first, char *single_tetro, int i);
void					afficherliste(t_liste *liste);
int						count_char(char *single_tetro);
int						check_char(char *str_tetra);
int						check_tetro_char(char *single_tetro);
int						get_coord(char tab[4][4], t_tetro *temp);
int						put_in_tab(char	*single_tetro, t_tetro *temp);
int						minx(char tab[4][4], t_tetro *temp);
int						miny(char tab[4][4], t_tetro *temp);
int						get_position(t_tetro *temp);
void					solve(t_liste *head);
int						solve_map(t_map *map, t_tetro *tetro);
int						map_size(t_liste *head);
t_map					*initialise_map(t_map *map);
int						find_place(t_tetro *tetro, t_map *map, int x, int y);
void					set_piece(t_map *map, t_tetro *tetro, int x, int y);
void					set_piece_bis(t_map *map, t_tetro *tetro, int x, int y);
void					print_map(t_map *map);
char					*last_n(char *str_tetra);
void					lstdeltetro(t_tetro **tetro);
void					lstdelhead(t_liste **tetro);
void					suppression(t_liste **liste);
void					free_map(t_map *map);
int						free_str_tetro(char *str_tetra,
							char *single_tetro);

#endif
