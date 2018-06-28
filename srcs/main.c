/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:27:04 by ahadjer           #+#    #+#             */
/*   Updated: 2018/06/28 00:00:19 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	get_player(t_env *env, char *line)
{
	get_next_line(0, &line);
	env->player = ft_strstr(line, "exec p1") ? 'O' : 'X';
	dprintf(2, "%s\n", line);
	dprintf(2, "player = %c\n", env->player);
	//dprintf(2, "enemi = %c\n", env->enemi);

}


void	get_map_size(t_env *env, char *line)
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


void	get_map(t_env *env, char *line)
{
	int		x;
	int		y;

	dprintf(2, "SEGV 1\n");
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

	dprintf(2, "SEGV 2\n");
}

void	init_piece(t_env *env)
{
	int		i;

	i = 0;
	if (!(env->piece = (char **)ft_memalloc(sizeof(char *) * env->piece_x)))
		exit(1);
	while (i < env->piece_y)
	{
		if (!(env->piece[i] = (char*)ft_memalloc(sizeof(char) * env->piece_y)))
			exit(1);
		i++;
	}
}

void	get_piece_size(t_env *env, char *line)
{
	int		i;
	char	**p;

	get_next_line(0, &line);
	while (!ft_strstr(line, "Piece "))
		get_next_line(0, &line);
	i = ft_strlen(line);
	line[i - 1] = '\0';
	p = ft_strsplit(line, ' ');
	env->piece_x = ft_atoi(p[1]);
	env->piece_y = ft_atoi(p[2]);
	dprintf(0, "%s\n", line);
}

void	get_piece(t_env *env, char *line)
{
	int		x;
	int		y;

	while (!ft_strstr(line, "Piece "))
		get_next_line(0, &line);
	dprintf(2, "%s\n", line);
	y = 0;
	while (y <= env->piece_y)
	{
		x = 0;
		while (x <= env->piece_x)
		{
			env->piece[x][y] = line[x];
			x++;
		}
		get_next_line(0, &line);
		y++;
	}
}

void play()
{
	//...
}

void	init_env(t_env *env)
{
	env->player = 0;
}

void	debug_show_map(t_env *env)
{
	int x;
	int y;

	y = 0;
	x = 0;

	while (y < env->map_y)
	{
		x = 0;
		while (x < env->map_x)
		{
			dprintf(2, "%c", env->map[x][y].sign);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}

}

int		main(void)
{
	char	*line;
	t_env	env;

	init_env(&env);
	line = NULL;
	get_player(&env, line);
	get_map_size(&env, line);
	init_map(&env);
	get_next_line(0, &line);
	get_map(&env, line);
    debug_show_map(&env);
	// while (get_next_line(0, &line))
	// {
	// 	play();
	// 	// get_map();
	// }

	//get_piece_size(&env, line);
	//init_piece(&env);
	//while (get_next_line(0, &line))
	//{
	//	get_map(&env, line);
	//	get_piece(&env, line);
	//}
	return (0);
}
