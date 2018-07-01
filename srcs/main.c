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
		dprintf(2, "new line youhou !\n");
		x = 0;
		while (x < env->piece_x)
		{
			dprintf(2, "new char youhou !\n");
			env->piece[x][y] = line[x];
			x++;
		}
		y++;
	}
	dprintf(2, "end youhou !\n");
	return (line);
}

void play()
{
	//...
}

void	debug_show_map(t_env *env)
{
	int x;
	int y;

	y = 0;
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


void	debug_show_piece(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->piece_y)
	{
		x = 0;
		while (x < env->piece_x)
		{
			dprintf(2, "%c", env->piece[x][y]);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}

void	debug_show_score(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->map_y)
	{
		x = 0;
		while (x < env->map_x)
		{
			dprintf(2, "%d", env->map[x][y].f);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}

void	init_env(t_env *env)
{
	env->player = 0;
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
	while (get_next_line(0 ,&line))
	{
		line = get_map(&env, line);
		line = get_piece_size(&env, line);
		init_piece(&env);
		get_piece(&env, line);
		calculate_score(&env);
		put_piece(&env);
	 	ft_putstr(ft_itoa(env.pos_y));
	 	ft_putstr(" ");
		ft_putstr(ft_itoa(env.pos_x));
	 	ft_putstr("\n");
	}
	return (0);
}
