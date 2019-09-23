#include "libft/libft.h"
#include "read.h"
#include <stdio.h>//

int		main(int ac, char **av)
{
	int count;
	int x = 0;
	int y = 0;
	int map[x][y];
	double size;

	count = 10;
	size = ft_sqrt(count * 4);
	printf("%f\n", size);
	while (x < size)
	{
		while ( y < size)
		{
			ft_putchar('.');
			y++;
		}
		ft_putchar('\n');
		y  = 0;
		x++;
	}
	return (0);
}
