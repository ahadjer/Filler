#include "../includes/filler.h"

char	*get_map_size(t_env *env, char **line)
{
	int		i;
	char	**w;

	get_next_line(0, line);
	if (!ft_strstr(*line, "Plateau"))
		exit(0);
	w = ft_strsplit(*line, ' ');
	if (!w[1] || !w[2])
		exit(0);
	env->map_x = ft_atoi(w[2]);
	env->map_y = ft_atoi(w[1]);
	dprintf(2, "mapx:%d:  \nmapY:%d:\n", env->map_x, env->map_y);
	return (*line);
}

void	init_map(t_env *env)
{
	int		i;

	i = 0;
	if (!(env->map = (t_flag **)ft_memalloc(sizeof(t_flag *) * env->map_x)))
		exit(0);
	while (i < env->map_x)
	{
		if (!(env->map[i] = (t_flag*)ft_memalloc(sizeof(t_flag) * env->map_y)))
			exit(0);
		i++;
	}
}

char	*get_map(t_env *env, char **line)
{
	int		x;
	int		y;

	y = 0;
	// get_next_line(0, line);

	while (!ft_strstr(*line, "000 "))
		get_next_line(0, line);


	dprintf(2, "FUCK YOU ONE\n");
	while (y < env->map_y)
	{
		// dprintf(2, "%s\n", *line);
		x = 0;
		*line += 4;
		while (x < env->map_x)
		{
			env->map[x][y].sign = (*line)[x];
			x++;
		}
		y++;
		get_next_line(0, line);
	}
	dprintf(2, "FUCK YOU TWO\n");
	return (*line);
}
