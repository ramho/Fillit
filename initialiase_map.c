#include "libft/libft.h"
#include "read.h"
#include <stdio.h>//

char		**initialise_map(t_liste *head)
{
	int count;
	int x = 0;
	int y = 0;
	double size1;
	int size;
	char **map;

	size = (int)size1;
	count = 1;
	size = ft_sqrt(count * 4);
	if (!(map = (char**)ft_memalloc(sizeof(*map) * size + 1)))
			return (NULL);
	while (x < size)
	{
		if(!(map[x] = ft_strnew(size)))
			return (NULL);
		while (y < size)
		{
			map[x][y] = '.';
			y++;
		}
		y  = 0;
		x++;
	}
	return (map);
}
