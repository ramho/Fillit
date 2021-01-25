/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:33:55 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/10/23 14:53:25 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	t_liste	*head;
	char	*str_tetra;

	str_tetra = NULL;
	if (ac != 2)
	{
		write(1, "usage: ./fillit [file]\n", 23);
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (!read_fd(fd, &str_tetra))
	{
		write(1, "error\n", 6);
		return (-1);
	}
	if (!(put_in_struct(&head, str_tetra)))
	{
		write(1, "error\n", 6);
		suppression(&head);
		return (-1);
	}
	solve(head);
	suppression(&head);
	return (0);
}
