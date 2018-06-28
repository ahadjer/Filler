
void	debug_show_map(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y <= env->map_y)
	{
		x = 0;
		while (x <= env->map_x)
		{
			dprintf(2, "%c", env->map[x][y].sign);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}

void	debug_show_piece(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y <= env->piece_y)
	{
		x = 0;
		while (x <= env->piece_x)
		{
			dprintf(2, "%c", env->piece[x][y]);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}
