/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:01:14 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/07/17 17:17:33 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# define TETRO 546 //taille maxi de 26 tetros

typedef	struct	s_tetro
{
	int	type;
	int x;
	int y; 
}				t_tetro


#endif
