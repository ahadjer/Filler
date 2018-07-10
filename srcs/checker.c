#include "../includes/filler.h"

void    check_score ( t_env *env, int x, int y)
{
	if (env->map[x][y].sign == env->enemi)
	{

		y - 1 >= 0 ? env->map[x][y - 1].f = 1 : 0;
		y + 1 < env->map_y ? env->map[x][y + 1].f = 1 : 0;
		x - 1 >= 0 ? env->map[x - 1][y].f = 1 : 0;
		x + 1 < env->map_x ? env->map[x + 1][y].f = 1 : 0;
	}
}
void calculate_score(t_env *env)
{
	int     x;
	int     y;

	x = 0;
	y = 0;
	dprintf(2, "r1\n");
	while (y < env->map_y)
	{
		x = 0;
		while (x < env->map_x)
		{
			check_score(env, x, y);
			x++;
		}
		y++;
	}
}

int		map_limit(t_env *env, int x, int y)
{
	int		i;

	i = 1;
	y < 0 || y >= env->map_y ? i = 0 : 0;
	x < 0 || x >= env->map_x ? i = 0 : 0;
	return (i);
}

void    check_block(t_env *env, int pos_x, int pos_y)
{
	int     x;
	int     y;
	int     touch;
	int			score;

	x = 0 - env->piece_x;
	y = 0 - env->piece_y;
	score = 0;
	touch = 0;
	while(y < env->piece_y)
	{
		x = 0;
		while (x < env->piece_x)
		{
			if (env->piece[x][y] == '*')
			{
				if (!map_limit(env, pos_x + x, pos_y + y))
					return;
				if (env->map[pos_x + x][pos_y + y].sign == env->player)
					touch++;
				if (env->map[pos_x + x][pos_y + y].sign == env->enemi)
					return;
				if (env->map[x][y].f == '1')
					score++;
			}
			x++;
		}
		y++;
	}
	env->high_score = -1;
	if (touch == 1 && score > env->high_score)
	{
		env->pos_x = pos_x;
		env->pos_y = pos_y;
	}
}

void    put_piece(t_env *env)
{
	int     x;
	int     y;

	x = 0;
	y = 0;
	while(y < env->map_y)
	{
		x = 0;
		while (x < env->map_x)
		{
			dprintf(2, "%d ", x);
			check_block(env, x, y);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}
