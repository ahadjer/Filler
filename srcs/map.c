#include "../includes/filler.h"

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

char	*get_map(t_env *env, char *line)
{
	int		x;
	int		y;

	get_next_line(0, &line);
	y = 0;
	while (!ft_strstr(line, "000 "))
		get_next_line(0, &line);
	while (y < env->map_y)
	{
		x = 0;
		line += 4;
		while (x < env->map_x)
		{
			env->map[x][y].sign = line[x];
			x++;
		}
		y++;
		get_next_line(0, &line);
	}
	return (line);
}

char	*get_map_size(t_env *env, char *line)
{
	int		i;
	char	**w;

	get_next_line(0, &line);
	if (!ft_strstr(line, "Plateau"))
		get_next_line(0, &line);
	dprintf(2, "%s\n", line);
	i = ft_strlen(line);
	line[i - 1] = '\0';
	w = ft_strsplit(line, ' ');
	env->map_x = ft_atoi(w[2]);
	env->map_y = ft_atoi(w[1]);
	dprintf(2, "mapx: %d\nmapY %d\n", env->map_x, env->map_y);
	return (line);
}
