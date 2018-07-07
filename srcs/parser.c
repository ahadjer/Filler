#include "../includes/filler.h"

char	*get_player(t_env *env, char *line)
{
	get_next_line(0, &line);
	env->player = ft_strstr(line, "exec p1") ? 'O' : 'X';
	env->enemi = ft_strstr(line, "exec p1") ? 'X' : 'O';
	dprintf(2, "%s\n", line);
	dprintf(2, "player = %c\n", env->player);
	dprintf(2, "enemi = %c\n", env->enemi);
	return (line);
}
