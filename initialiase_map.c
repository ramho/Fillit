int	initialise_map(t_list head, char **map)
{
	int x;
	int y;
	map[x][y];

	x = 0;
	y = 0;
	
	while ( x < head.count)
	{
		while ( y < head.count)
		{
			ft_putchar('.');
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}
