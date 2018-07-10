#include "../includes/filler.h"

char	*get_piece_size(t_env *env, char *line)
{
	int		i;
	char	**p;

	if (!ft_strstr(line, "Piece "))
		get_next_line(0, &line);

	i = ft_strlen(line);
	line[i - 1] = '\0';
	p = ft_strsplit(line, ' ');
	env->piece_x = ft_atoi(p[2]);
	env->piece_y = ft_atoi(p[1]);
	return (line);
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

char	*get_piece(t_env *env, char *line)
{
	int		x;
	int		y;

	while (!ft_strstr(line, "Piece "))
		get_next_line(0, &line);
	y = 0;
	while (y < env->piece_y)
	{
		get_next_line(0, &line);
		dprintf(2, "r2\n");
		x = 0;
		while (x < env->piece_x)
		{
			dprintf(2, "c1\n");
			env->piece[x][y] = line[x];
			x++;
		}
		y++;
	}
	dprintf(2, "end\n");
	return (line);
}
