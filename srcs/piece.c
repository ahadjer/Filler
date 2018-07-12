#include "../includes/filler.h"

char	*get_piece_size(t_env *env, char **line)
{
	int		i;
	char	**p;

	if (!ft_strstr(*line, "Piece "))
		exit(0);

		dprintf(2, "POKEMON\n");
	p = ft_strsplit(*line, ' ');
	if (!p[1] || !p[2])
		exit(0);
	env->piece_x = ft_atoi(p[2]);
	env->piece_y = ft_atoi(p[1]);
	dprintf(2, "piece sizeX:%d   sizeY:%d\n", env->piece_x, env->piece_y);
	return (*line);
}

void	init_piece(t_env *env)
{
	int		i;

	i = 0;
	if (!(env->piece = (char **)ft_memalloc(sizeof(char *) * env->piece_x)))
		exit(1);
	while (i < env->piece_x)
	{
		if (!(env->piece[i] = (char*)ft_memalloc(sizeof(char) * env->piece_y)))
			exit(1);
		i++;
	}
}

char	*get_piece(t_env *env, char **line)
{
	int		x;
	int		y;

	// get_next_line(0, line);
	// dprintf(2, "putain : %s\n", *line);

	y = 0;
	while (y < env->piece_y)
	{
		get_next_line(0, line);
		x = 0;
		while (x < env->piece_x)
		{
			env->piece[x][y] = (*line)[x];
			dprintf(2, "%c", env->piece[x][y]);
			x++;
		}
		dprintf(2, "\n");
		y++;
		// exit(0);
	}
	dprintf(2, "end piece\n");
	return (*line);
}
